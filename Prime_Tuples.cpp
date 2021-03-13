#include <bits/stdc++.h>
#define pb push_back
#define all(a) a.begin(),a.end()
#define forn(i,n) for(int i=0;i<int(n);i++)
#define forr(i,n) for(int i=int(n-1);i>=0;i--)
#define fora(i,a,b) for(int i=int(a);i<=int(b);i++)
#define forb(i,a,b) for(int i=int(a);i>=int(b);i--)
#define kickstart int t,o;cin>>o;for(t=1;t<=o;t++){cout<<"Case #"<<t<<": ";solve();}
#define mod 1000000007
using namespace std;
using ll=long long int;
using ld = long double;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<ll> vii;
typedef pair<ll ,ll> pii;
void solve()
{
    int n, k;
    cin >> n >> k;
    int arr[n];
    forn(i, n) cin >> arr[i];
    stack<int> s;
    ll pre[n - 1];
    pre[0] = arr[0];
    for (int i =1; i < n; i++) pre[i] = pre[i - 1] + arr[i];
    vi ans(n, -1), ans2(n, -1);
    for (int i = 0; i < n; i++) {
        if (s.empty()) {
            s.push(i);
            continue;
        }
        while (s.empty() == false and arr[s.top()] >= arr[i]) {
            s.pop();
        }
        if (s.empty() == false) ans[i] = s.top();
        s.push(i);
    }
    while (s.empty() == false)s.pop();
    for (int i = n - 1; i >= 0; i--) {
        if (s.empty()) {
            s.push(i);
            continue;
        }
        while (s.empty() == false and arr[s.top()] >= arr[i]) {
            s.pop();
        }
        if (s.empty() == false) ans2[i] = s.top();
        s.push(i);
    }
    //for (auto i : ans2) cout << i << " " ;
   // cout << endl;
    //for (auto i : ans) cout << i << " ";
    ld res = 0;
    for (int  i = 0; i < n; i++) {
        int l, r;
        if (ans[i] == -1) l = 0;
        else l = ans[i] + 1;

        if (ans2[i] == -1) r = n - 1;
        else r = ans2[i] - 1;

        if (r - l + 1 < k) continue;
        ll s = pre[r] - (l - 1 >= 0 ? pre[l - 1] : 0);
        ld cur = (ld) s / (r - l + 1);
        res = max(res, cur);

    }
    cout << fixed << setprecision(6);
    cout << res << endl;
}

int main()
{
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);
    int t=1;
    //cin>>t;
    while(t--)
	solve();
    return 0;
}
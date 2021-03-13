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
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<ll> vii;
typedef pair<ll ,ll> pii;

bool check(ll a, ll n, bool neg) {
    ll s = 0, e = 1e6;
    n *= 2;
    while (s <= e) {
        ll mid = (s + e) / 2;
        ll x = 2 * a * mid  + (mid - 1) * mid;
        if (x == n) return true;
        if (x > n) {
            e = mid - 1;
        }
        else {
            s = mid + 1;
        }
    }
    return false;
}
void solve()
{
    ll n;
    cin >> n;
   /* n *= 2;
    int ans = 0;
    for (int i = -1000; i < 1000; i++) {
        for (int j = 1; j < 1000; j++) {
            ll x = j * (2 * i + (j - 1));
            if (x == n) ans++;
        }
    }
    cout << ans << endl;*/
    vii div;
    for (ll i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            div.push_back(i);
            if (n / i != i)div.push_back(n/i);
        }
    }
    ll ans = 0;
    for (auto a : div) {
        if(check(a, n, (a < 0))) ans++;
    }
    cout << 2 * ans << endl;
}

int main()
{
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);
    int t=1;
    //9cin>>t;
    while(t--)
	solve();
    return 0;
}
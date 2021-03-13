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
  
void solve()
{
    ll n, k;
    cin >> n >> k;
    k--;
    ll arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    vii v;
    v.pb(arr[0]);
    for (int i = 1; i < n; i++) {
        v.pb(arr[i - 1] ^ arr[i]);
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] & (1 << k))ans++;
    }
    cout << ans << endl;
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
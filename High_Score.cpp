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

vector<pair<pii,ll>> v;
void solve()
{
    ll n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        v.push_back({{a, b}, c});
    }
    vector<ll> dist(100005, -1e18);
    dist[1] = 0;
    for (int i = 0 ; i < n - 1; i++) {
        for (auto e : v) {
            ll ss = e.first.first;
            ll dd = e.first.second;
            ll cost = e.second;
            dist[dd] = max(dist[dd], dist[ss] + cost);
        }
    }
    
    for (auto e: v) {
        ll ss = e.first.first;
        ll dd = e.first.second;
        ll cost = e.second;
        if (dist[ss] + cost > dist[dd]) {
            cout << -1 << endl;
            return;
        }
    }
    cout << dist[n] << endl;
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
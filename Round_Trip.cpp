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
vi v[100005];
vi col(100005, 1);
vi cyc;
map<int,int> pp;
void dfs(int s, int par) {
    if (col[s] == 3) return; 
    if (col[s] == 2) {
        if (cyc.size() == 0) {
            cyc.push_back(s);
            int x = par;
            while (x != s) {
                cyc.push_back(x);
                x = pp[x];
            }
            cyc.push_back(s);
        }
        return;
    }
    pp[s] = par;
    col[s] = 2;
    for (auto i : v[s]) {
        if(i != par) dfs(i, s);
    }
    col[s] = 3; 
}
void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        v[a].pb(b);
        v[b].pb(a);
    }
    for (int i = 1; i <= n; i++) {
        if (col[i] == 1) dfs(i, 0);
    }
    if(cyc.size() == 0) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    cout << cyc.size() << endl;
    for (auto i : cyc) cout << i << " ";
    cout << endl;
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
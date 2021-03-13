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
  
vector<int> v[100005];
vector<int> col(100005, -1);
vector<bool> vis(100005);
bool dfs(int s, bool c) {
    col[s] = c;
    vis[s] = 1;
   // cout << s << endl;
    for (auto  i : v[s]) {
        if (!vis[i]) {
            if (dfs(i, c ^ 1) == false) return false;
        }
        else if (col[s] == col[i]) return false;
    }
    return true;
}
void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    //dfs(1, 0);
    //cout << vis[3] << endl;
    for (int i = 1; i <= n; i++) {
        if (vis[i] == false  and dfs(i, 0) == false) {
            //cout << i << endl;
            cout << "IMPOSSIBLE";
            exit(0);
        }
    }
    for (int i = 0; i < n; i++) cout << col[i + 1] + 1 << " ";
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
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
vi disc(200005, -1), low(200005);
vector<int> graph[200005];
vector<pi> v[200005];
vector<vector<int>> scc;
bool onstack[200005];
bool vis[200005];
int n, m , foundat;
void tarjan(int u){
    static stack<int> st;
    vis[u] = 1;
    disc[u]=low[u]=foundat++;
    st.push(u);
    onstack[u]=true;
    for(auto i:graph[u]){
        if(disc[i]==-1){
            tarjan(i);
            low[u]=min(low[u],low[i]);
        }
        else if(onstack[i])
            low[u]=min(low[u],disc[i]);
    }
    if(disc[u]==low[u]){
        vi scctem;
        while(1){
            int v=st.top();
            st.pop();onstack[v]=false;
            scctem.pb(v);
            if(u==v)
                break;
        }
        scc.pb(scctem);
    }
}
void solve()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].pb({b,c});
        graph[a].push_back(b);
    }
    for (int i = 1; i <= n; i++) {
        if (vis[i] == 0)tarjan(i);
    }
    for (auto i : scc) {
        for (auto j: i) cout << j << " ";
        cout << endl;
    }
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
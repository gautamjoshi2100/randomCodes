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
 
vector<pii> v[100005];
vector<ll> dist(100005,1e15);
vector<bool> vis(1000005);
void dijstra(int s) {
    dist[s] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0,s});
    while (pq.size() != 0) {
        pii curr = pq.top();
        pq.pop();
        ll cur = curr.second;
        vis[cur] = 1;
        if (dist[cur] < curr.first) continue;
        for (auto i : v[cur]) {
            if (vis[i.first])continue;
            if (dist[i.first] > i.second + dist[cur]) {
                dist[i.first] = i.second + dist[cur];
                pq.push({dist[i.first], i.first});
            }
        }
    }
}
void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({b, c});
        //v[b].push_back({a, c});
    }
    dijstra(1);
    for (int i = 1; i <= n; i++) cout << dist[i] << " ";
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
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
  
vector<pair<ll,ll>> v[100005];
vector<ll> dist(100005,1e15);
vector<bool> vis(100005);
vector<ll> par(100005);
vector<ll> maxinpath(100005, -1);
void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({b,c});
        //v[b].push_back({a,c});
    }
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;
    pq.push({0,1});
    dist[1] = 0;
    while (pq.empty() == false) {
        auto cur = pq.top();
        pq.pop();
        vis[cur.second] = 1;
        for (auto i : v[cur.second]) {
            if (!vis[i.first]) {
                if (dist[i.first] > dist[cur.second] + i.second) {
                    dist[i.first] = dist[cur.second] + i.second;
                    pq.push({dist[i.first], i.first});
                    par[i.first] = cur.second;
                    maxinpath[i.first] = i.second;
                }
            }
        }
    }
    int x = n;
    if (dist[x] == 1e15) {
        cout << -1 << endl;
        return;
    }
    vector<int> path;
    while (x != 1) {
        path.push_back(x);
        x = par[x];
    }
    reverse(all(path));
    ll mx = 0, s = 0;
    for (auto i : path) {
        mx = max(mx, maxinpath[i]);
      //  cerr << maxinpath[i] << " ";
        s += maxinpath[i];
    }
    cout << s - mx + (mx / 2);
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
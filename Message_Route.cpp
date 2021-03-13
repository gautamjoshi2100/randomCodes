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
vector<int> dist(100005,1e9);
vector<int> path;
int bfs(int s, int e) {
    queue<int> q;
    q.push(s);
    dist[s] = 1;
    map<int,int> track;
    track[s] = s;
    while (q.empty() == false) {
        int cur = q.front();
        q.pop();
        for (auto i : v[cur]) {
            if (dist[cur] + 1 < dist[i]) {
                dist[i] = dist[cur] + 1;
                track[i] = cur;
                q.push(i);
            }
        }
    }
    int p = e;
    if (dist[e] == 1e9) return -1;
    while (p != 1)
    {
        path.push_back(p);
        p = track[p];
    }
    path.push_back(1);
    return (dist[e] == 1e9? -1 : dist[e]);
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
    int ans = bfs(1, n);
    if (ans == -1) {
        cout << "IMPOSSIBLE";
    }
    else {
        cout << ans << endl;
        reverse(path.begin(), path.end());
        for (auto i : path) cout << i << " ";
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
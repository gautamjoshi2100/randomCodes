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
int n, m;
char grid[1005][1005];
int dist[1005][1005];
int dist2[1005][1005];
bool vis[1005][1005];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int dir[1005][1005];
void bfs(vector<pair<int,int>> &sources) {
    queue<pair<pair<int, int>,int>> q;
    for (auto i : sources) q.push({i,0});
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        vis[cur.first.first][cur.first.second] = 1;
        for (int i = 0; i < 4; i++) {
            int x = cur.first.first + dx[i], y = cur.first.second + dy[i];
            if (x >= 0 and x < n  and y >= 0 and y < m and grid[x][y] != '#' and vis[x][y] == false) {
                q.push({{x,y},cur.second + 1});
                dist[x][y] = cur.second + 1;
                vis[x][y] = 1;
            }
        }
    }
}
void solve()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            dist[i][j] = 1e9;
            dist2[i][j] = 1e9;
        }
    }
    bool vis[n][m];
    memset(vis, 0, sizeof(vis));
    vector<pair<int,int>> sources;
    pair<int,int> ss;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if(grid[i][j] == 'M') {
                sources.push_back({i, j});
                dist[i][j] = 0;
            }
            if(grid[i][j] == 'A') {
                ss = {i, j};
                dist2[i][j] = 0;
            }
        }
    }
    bfs(sources);
    memset(vis, 0, sizeof(vis));
    queue<pair<int,int>> q;
    q.push(ss);
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        vis[cur.first][cur.second] = 1;
        for (int i = 0; i < 4; i++) {
            int x = cur.first + dx[i], y = cur.second + dy[i];
            if (x >= 0 and x < n  and y >= 0 and y < m and grid[x][y] != '#' and vis[x][y] == false) {
                q.push({x, y});
                dist2[x][y] = dist2[cur.first][cur.second] + 1;
                vis[x][y] = 1;
                dir[x][y] = i + 1;
            }
        }
    }

    pair<int,int> reach = {-1, -1};
    for (int i = 0; i < n; i++) {
        if (dist[i][0] != -1 and dist2[i][0] != -1 and dist[i][0] > dist2[i][0]) {
            reach = {i, 0};
        }
        if (dist[i][m - 1] != -1 and dist2[i][m - 1] != -1 and dist[i][m - 1] > dist2[i][m - 1]) {
            reach = {i, m - 1};
        }
    }
    
    for (int i = 0; i < m; i++) {
        if (dist[0][i] != -1 and dist2[0][i] != -1 and dist[0][i] > dist2[0][i]) {
            reach = {0, i};
        }
        if (dist[n - 1][i] != -1 and dist2[n - 1][i] != -1 and dist[n - 1][i] > dist2[n - 1][i]) {
            reach = {n - 1, i};
        }
    }
    /*for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cout << dist2[i][j] << " ";
        cout << endl;
    }*/
    if (reach.first == -1) {
        cout << "NO" << endl;
        return;
    }
    string ans = "";
    string meh = "DULR";
    int x = reach.first, y = reach.second;
    cout << "YES" << endl;
    cout << dist2[x][y] << endl;
    while (x != ss.first or y != ss.second) {
        ans += meh[dir[x][y] - 1];
        if (dir[x][y] == 1) {
            x--;
        }
        else if(dir[x][y] == 2){
            x++;
        }
        else if(dir[x][y] == 3){
            y++;
        }
        else
        {
             y--;
        }  
    }
    reverse(all(ans));
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
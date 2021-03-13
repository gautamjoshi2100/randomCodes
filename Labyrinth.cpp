#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
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
char grid[1005][1005];
bool vis[1005][1005];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int dir[1005][1005];
void solve()
{
    int n, m;
    cin >> n >> m;
    int ex = 0, ey = 0, sx = 0, sy = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'A') sx = i, sy = j;
            if (grid[i][j] == 'B') ex = i, ey = j;
        }
    }
    
    queue<pair<pair<int,int>, int >> q;
    q.push({{sx, sy}, 0});
    map<pair<int,int>, char> par;
    while (!q.empty()) {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int dis = q.front().second;
        q.pop();
        if (x == ex and y == ey) {
            cout << "YES" << endl;
            cout << dis << endl;
            string pp = "DULR";
            string ans = "";
            while (dir[x][y] != 0) {
                ans += pp[dir[x][y] - 1];
                if (dir[x][y] == 1) {
                    x--;
                }
                else if (dir[x][y] == 2){
                    x++;
                }
                else if (dir[x][y] == 3) {
                    y++;
                }
                else if(dir[x][y] == 4) {
                    y--;
                }
                assert (x >= 0 and y >= 0 and x < n and y < m);
            }   
            reverse(all(ans));
            cout << ans << endl;
            return;
        }
        vis[x][y] = 1;
        for (int i = 0; i < 4; i++) {
            int xx = x + dx[i], yy = y + dy[i];
            if (xx >=0 and xx < n and yy >=0 and yy < m and grid[xx][yy] != '#' and !vis[xx][yy]) {
                q.push({{xx,yy}, dis + 1});
                dir[xx][yy] = i + 1;
                vis[xx][yy] = 1;
            }
        }
    } 
    cout << "NO" << endl;
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

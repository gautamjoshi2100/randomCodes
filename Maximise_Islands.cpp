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
    int n, m;
    cin >> n >> m;
    char arr[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cin >> arr[i][j];
    }  
    char can1[n][m];
    bool x = 0;
    int mx = (n * m) / 2 + ((n * m) % 2 != 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)can1[i][j] = '.';
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            bool is = 0;
            if (i - 1 >= 0 and can1[i - 1][j] == '*') is = 1;
            if (i + 1 < n and can1[i + 1][j] == '*') is = 1;
            if (j - 1 >= 0 and can1[i][j - 1] == '*') is = 1;
            if (j + 1 < m and can1[i][j + 1] == '*') is = 1;

            if (is) can1[i][j] = '.';
            else can1[i][j] = '*';
        }
    }
    int ans1 = 0, ans2 = 0;

    
    int cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++) {
            ans1 += (arr[i][j] != can1[i][j]);
            if(can1[i][j] == '*')cnt1++;
        }
    }
    for (int i = 0 ; i < n; i++) {
        for (int j = 0; j < m; j++) 
        {
            if (can1[i][j] == '*') can1[i][j] = '.';
            else can1[i][j] = '*';
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            ans2 += (arr[i][j] != can1[i][j]);
            if(can1[i][j] == '*')cnt2++;
        }
    }
    if (cnt1 != mx) cout << ans2 <<endl;
    else if (cnt2 != mx) cout << ans1 << endl;
    else cout << min(ans1, ans2) << endl;
    

    //cerr  << " -------------------------------" <<endl;
    //cout<<endl;
    //cout << min(ans1, ans2) << endl;
}

int main()
{
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);
    int t=1;
    cin>>t;
    while(t--)
	solve();
    return 0;
}
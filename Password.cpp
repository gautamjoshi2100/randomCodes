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
    string s;
    cin>> s;
    bool lc = 0, uc = 0, d = 0, sc = 0;
    if (s.size() < 10) 
    {
        cout << "NO" <<endl;
        return;
    }
    for(auto i : s)if(islower(i))lc = 1;
    for (int i = 1; i < s.size() - 1;i++)if(isupper(s[i])) uc = 1;
    for (int j = 1; j < s.size() - 1; j++){
        char i = s[j];
         if(i>='0' and i<='9')d = 1;
    }
    for(int j = 1;j < s.size() - 1; j++)
    {
        char i = s[j];
        if (i>='a' and  i<='z')continue;
        if(i>='A' and i<='Z')continue;
        if(i>='0' and i<='9')continue;
        sc = 1;
    }
    if (sc and lc and uc and d)cout <<"YES";
    else cout<<"NO";
    cout<<endl;
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
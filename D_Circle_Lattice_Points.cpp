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
    long double x, y, r;
    cin >> x >> y >> r;
    long double rs = (x - r), l = (x + r), u = (y + r), d = (y - r);
     //x = floor(x);
     //y = floor(y);
     ll ans = 1;
     rs = abs(abs(rs) - x);
     l = abs(abs(l) - x);
     u = abs(abs(u) - y);
     d = abs(abs(d) - y);
     cout << rs << " " << l << " " << u << " " << d << endl;
     ans += u * l;
     ans += d * r;
     ans += d * l;
     ans += u * r;
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
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
vi spf(2*1000005);
void seive(int n = 2 * 1e6) {
    vector<bool> is(n + 1, 1);
    spf[1] = 1;
    for (int i = 2; i * i <= n; i++) {
        if (is[i]) {
            spf[i] = i;
            for (int j = i * i; j <=n; j += i) {
                spf[j] = i;
                is[j] = false;
            }
        }
    }
    
}
ll ppow(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}
ll combine (ll a, ll b) {
    int x = 2;
    ll ans = 0;
    while (x <= b) {
        ans += ppow(a, x);
        ans %= mod;
        x += 2;
    }
    return ans;
}
void solve()
{
    int n;
    cin >> n;
    unordered_map<int, ll> pp;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        unordered_map<int, int> ryt;
        while (a != 1) {
            ryt[spf[a]]++;
            a /= spf[a];
        }
        for (auto j : ryt) {
            int mm = j.first;
            pp[mm] += ryt[mm] * b;
        }
    }
    vector<pair<ll,ll>> v;
    for (auto i : pp) {
        //cerr << i.first << " " << pp[i.first] << endl;
        v.push_back({i.first, pp[i.first]});
    }
    ll sum = 0;
    for (int i = 0; i < v.size(); i++) {
        int x = 2;
        while (x <= v[i].second) {
            sum += ppow(v[i].first, x);
            sum %= mod;
            x += 2;
        }
    }
    for (int i = 0; i < v.size(); i++) {
        ll cur = v[i].first, minp = v[i].second;
        for (int j = i + 1; j < v.size(); j++) {
            cur *= v[j].first;
            minp = min(minp, v[j].second);
            sum += combine(cur, minp);
        }
    }
    cout << sum + 1 << endl;
}

int main()
{
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);
    int t=1;
    //cin>>t;
    seive();
    while(t--)
	solve();
    return 0;
}
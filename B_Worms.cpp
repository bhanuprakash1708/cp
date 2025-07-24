#include <bits/stdc++.h>  
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int,int> p32;
typedef pair<ll,ll> p64;
typedef pair<double,double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int> > vv32;
typedef vector<vector<ll> > vv64;
typedef vector<vector<p64> > vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
ll MOD = 998244353;
double eps = 1e-12;
#define forn(i,e) for(ll i = 0; i < e; i++)
#define forsn(i,s,e) for(ll i = s; i < e; i++)
#define rforn(i,s) for(ll i = s; i >= 0; i--)
#define rforsn(i,s,e) for(ll i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
 

void solve(){
    ll n;
    cin>>n;
    vector<ll>a(n),p(n);
    for(ll i=0;i<n;i++) cin>>a[i];
    p[0]=a[0];
    for(ll i=1;i<n;i++){
        p[i]=p[i-1]+a[i];
    }
    ll q;
    cin>>q;
    while(q--){
        ll k;
        cin>>k;
        auto c=upper_bound(p.begin(),p.end(),k);
        int r=c-p.begin();
        if(r==n) cout<<r<<endl;
        else
        cout<<r+1<<endl;
    }
}
int main()
{
    fast_cin();
    solve();
    return 0;
}
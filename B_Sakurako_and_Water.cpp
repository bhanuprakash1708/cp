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
    int n,e=0,i,j;
    cin>>n;
    int a[n][n];
    int p[n*2-1];
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            cin>>a[i][j];
    for(i=0;i<n*2-1;i++)
        p[i]=0;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++){
            if(a[i][j]>p[i+n-j-1])
            p[i+n-j-1]=p[i+n-j-1];
            else
            p[i+n-j-1]=a[i][j];
        }
    for(i=0;i<2*n-1;i++)
        if(p[i]<0)
            e-=p[i];
    cout<<e<<endl;
}
int main()
{
    fast_cin();
    ll t;
    cin >> t;
    for(int p=1;p<=t;p++) {
        solve();
    }
    return 0;
}
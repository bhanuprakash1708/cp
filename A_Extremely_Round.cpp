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
vector<int>a;

bool func(int n){
    int d=0;
    string s=to_string(n);
    for(char i:s){
        if(i!='0'){
            d++;
        }
    }
    if(d==1) return true;
    return false;
}

void solve(){
    int n,c=0;
    cin>>n;
    for(int i=0;i<a.size();i++){
        if(a[i]<=n){
            c++;
        }
    }
    cout<<c<<endl;
}
int main()
{
    fast_cin();
    ll t;
    for(int i=1;i<=999999;i++){
        if(func(i)){
            a.push_back(i);
        }
    }
    cin >> t;
    for(int it=1;it<=t;it++) {
        solve();
    }
    return 0;
}
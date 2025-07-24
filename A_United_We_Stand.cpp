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
    int n;
    cin>>n;
    vector<int>a(n),b,c;
    for(int i=0;i<n;i++) cin>>a[i];
    int k=*min_element(a.begin(),a.end());
    int d=*max_element(a.begin(),a.end());
    if(k==d){
        cout<<-1<<endl;
        return;
    }
    int i;
    for(int i=0;i<n;i++){
        if(a[i]!=d){
            b.push_back(a[i]);
        }
        else{
            c.push_back(a[i]);
        }
    }
    if(b.size()==0){
        cout<<-1<<endl;
        return;
    }
    cout<<b.size()<<" "<<c.size()<<endl;
    for(int i=0;i<b.size();i++) cout<<b[i]<<" ";
    cout<<endl;
    for(int i=0;i<c.size();i++) cout<<c[i]<<" ";
    cout<<endl;
}
int main()
{
    fast_cin();
    ll t;
    cin >> t;
    for(int it=1;it<=t;it++) {
        solve();
    }
    return 0;
}
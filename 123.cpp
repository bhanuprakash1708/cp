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
vector<int>findCoins(vector<int>& numsWays){
    int n=numsWays.size();
    vector<long long>a(n+1,0);
    a[0]=1;
    vector<int>s;
    for(int i=n;i>=1;i--){
        long long c=numsWays[i-1]-a[i];
        if(c==1){
            s.push_back(i);
            for(int k=i;k<=n;k++){
                a[k]=a[k]+a[k-c];
            }
        }
    }
    reverse
    return s;
}
 
vector<int>findCoins(vector<int>& numsWays){
    int n=numsWays.size();
    vector<long long>dp(n+1,0);
    dp[0]=1;
    vector<int>ans;
    int ux=0;
    bool fl=false;
    for(int c=1;c<=n;c++){
        long long nw=numsWays[c-1];
        long long df=nw-dp[c];
        if(df<=0||df>1) return {};
        if(df==1){
            ans.push_back(c);
            for(int j=c;j<=n;j++){
                dp[j]+=dp[j-c];
            }
        }
    }
    return ans;
}

void solve(){
    
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
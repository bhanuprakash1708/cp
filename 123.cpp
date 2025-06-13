#include <bits/stdc++.h>  
#include <complex>
#include <queue>
#include <set>
#include <unordered_set>
#include <list>
#include <chrono>
#include <random>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <iomanip>
#include <fstream>
 
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
}
int main()
{
    fast_cin();
    int i,n;
    cin>>n;
    int a[n];
    for(i=0;i<n;i++)
    cin>>a[i];
    int sum=0;
    for(i=0;i<n;i++){
        sum+=a[i];
    }
    int sum2=0;
    set<int> b;
    for(i=0;i<n;i++)
    {
        if(i==0||a[i]*2<=a[0]){
            b.insert(i+1);
            sum2+=a[i];
        }
    }
    if(sum2*2>sum){
        cout<<b.size()<<endl;
        for(auto i: b){
            cout<<i<<" ";
        }
    }
    else{
        cout<<"0";
    }
    return 0;
}
int t;
    cin>>t;
    while(t--)
    {
        string s,t;
        cin>>s>>t;
        
        int n=s.size();
        int m=t.size();
        int cnt=0;
        
        for(int i=0;i<min(n,m);i++)
        {
            if(s[i]==t[i])
            {
                cnt++;
            }
            else
            {
                break;
            }
        }
        
        int ans=cnt+(n-cnt)+(m-cnt);
        
        if(cnt!=0)
        {
            ans++;
        }
        
        cout<<ans<<endl;
    }



    #include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9 + 7;
const int MAX_N = 1e5 + 1; 


int solve(int base, int exp, int mod) 
{
    int result = 1;
    while (exp > 0) 
    {
        if (exp % 2 == 1) 
        {
            result = (1LL * result * base) % mod;
        }
        
        base = (1LL * base * base) % mod; 
        exp /= 2;
    }
    
    return result;
}

int32_t main() 
{
    int t;
    cin >> t;

    vector<int> n(t), k(t);

    for (int i = 0; i < t; ++i) 
    {
    cin >> n[i];
    }

    for (int i = 0; i < t; ++i) 
    {
        cin >> k[i];
    }

    for( int i = 0 ; i < t ; i++)
    {
        cout <<solve(2 , k[i] , MOD) <<endl;
    }

    return 0;
}
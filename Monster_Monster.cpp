//Author: Bhanu Prakash
#include <bits/stdc++.h>  
using namespace std;
typedef long long ll;
ll MOD = 998244353;
double eps = 1e-12;

// ----------------------------------------------------------------

bool isAllUpperCase(string s){
    for(char c: s){
        if(islower(c)){
            return false;
        }
    }
    return true;
}

int getGCD(int n1, int n2) {
    if (n2 == 0) {
      return n1;
    }
    return getGCD(n2, n1 % n2);
  }

int getLCM(int n1, int n2) {
   if (n1 == 0 || n2 == 0)
     return 0;
   else {
     int gcd = getGCD(n1, n2);
     return abs(n1 * n2) / gcd;
   }
}

long long int highestPowerof2(long long int n)
{
    long long int c = 0;
    for (long long int i = n; i >= 1; i--) {
        if ((i & (i - 1)) == 0) {
            c=i;
            break;
        }
    }
    return c;
}

bool comp(int a, int b) {
      return a > b;
}

// -------------------------------------------------------------------

void solve(){
    ll n,x,d,r=0;
    cin>>n>>x;
    vector<ll> a(n),b(n);
    for(ll i=0;i<n;i++)
    cin>>a[i];
    sort(a.begin(),a.end());
    for(ll i=0;i<n;i++){
        d=a[i]+(n-i-1)*x;
        r=max(r,d);
    }
    cout<<r<<endl;
    
}

// -------------------------------------------------------------------

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll t;
    cin >> t;
    for(int it=1;it<=t;it++) {
        solve();
    }
    return 0;
}
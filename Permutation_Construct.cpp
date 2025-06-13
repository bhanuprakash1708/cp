#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int> > vv32;
ll MOD = 998244353;
double eps = 1e-12;
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
void solve(){
    long long int n,k;
    cin>>n>>k;
    vector<long long int>v(n+1);
    for(long long int i=0;i<(n+1);i++) v[i]=0;
    bool p=true;
    long long int r=0;
    while(r<k){
        vector<long long int>s;
        for(long long int i=1;i<n+1;i++){
            if(i%k==r){
                s.push_back(i);
            }
        }
        if(s.size()==1){
            p=false;
            break;
        }
        else{
            for(long long int j=0;j<s.size();j++){
                v[s[j]]=s[(j+1)%s.size()];
            }
        }
        r++;
    }
    if(p){
        for(int i=1;i<n+1;i++){
            cout<<v[i]<<" ";
        }
        cout<<endl;
    }
    else{
        cout<<-1<<endl;
    }
}
int main()
{
    fast_cin();
    long long int p;
    cin>>p;
    while(p--){
        solve();
    }
    return 0;
}

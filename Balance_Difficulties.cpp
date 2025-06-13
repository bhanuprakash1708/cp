#include <bits/stdc++.h>  
using namespace std;

bool feasible(long long k,const vector<long long>& b,int n,long long x){
    long long low=b[0]-k,high-b[0]+k;
    for(int i=1;i<n;i++){
        long long curr_low=max(b[i]-k,low);
        long long curr_high=min(b[i]+k,high+x);
        if(curr_low>curr_high) return false;
        low=curr_low;
        high=curr_high;
    }
    return true;
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        long long x;
        cin>>n>>x;
        vector<long long>b(n);
        for(int i=0;i<n;i++){
            cin>>b[i];
        }
        long long l=0,r=2e9,ans=r;
        while(l<=r){
            long long mid=l+(r-l)/2;
            if(feasible(mid,B,n,x)){
                ans=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        vector<long long> c(n);
        c[0]=b[0]+ans;
        c[0]=min(c[0],b[0]+ans);
        c[0]=max(c[0],b[0]-ans);
        for(int i=1;i<n;i++){
            long ong low=max(c[i-1],b[i]-ans);
            long long high=min(c[i-1]+x,b[i]+ans);
            c[i]=high;
        }
        long long max_dev=0;
        for(int i=0;i<n;i++)
        max_dev=max(max_dev,abs(c[i]-b[i]));
        cout<<max_dev<<"\n";
        for(int i=0;i<n;i++){
            
        }
    }
    return 0;
}

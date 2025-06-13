#include<bits/stdc++.h>
using namespace std;
#define int long long
 
int32_t main()
{
    int t;
    cin>>t;
 
    while(t--)
    {
        int n;
        cin>>n;
 
        vector<int>vec(n);
        for(int i=0;i<n;i++)
        {
            cin>>vec[i];
        }
 
        int ans=0;
        int len=1;
 
        for(int i=1;i<=n;i++)
        {
            if(i<n && vec[i]==vec[i-1])
            {
                len++;
            }
            else
            {
                ans+=(len)*(len+1)/2;
                len=1;
            }
        }
 
        cout<<ans<<endl;
 
 
    }
 
 
    return 0;
}
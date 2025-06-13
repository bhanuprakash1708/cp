#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        int a[n];
        for(int i=0;i<n;i++) cin>>a[i];
        int b[m];
        for(int i=0;i<m;i++) cin>>b[i];
        int prev=min(a[0],b[0]-a[0]);
                    bool found=true;
        for(int i=1;i<n;i++)
        {
            int test1,test2;
            test1=a[i];
            test2=b[0]-a[i];

            vector<int> vec;
            if(test1>=prev) vec.push_back(test1);
            if(test2>=prev) vec.push_back(test2);
            if(vec.size()==0)
            {
                found=false;
                break;
            }
            prev=*min_element(vec.begin(),vec.end());
        }
        if(found) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}
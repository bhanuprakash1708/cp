#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
	    int n,x;
        cin>>n>>x;
	    int arr[n];
	    int brr[n];
	    for(int i=0;i<n;i++)
	    {
	        cin>>arr[i];
	    }
	    for(int i=0;i<n;i++)
	    {
	        cin>>brr[i];
	    }
        int e=(n/2)+1;
	    int clean=0;
        vector<int> c;
	    for(int i=0;i<n;i++)
	    {
	        if(arr[i]>brr[i])
	        {
	            clean++;
	        }
	        else{
	         c.push_back(brr[i]-arr[i]+1);
	        }
	    }
        sort(c.begin(),c.end());
        for(int j=0;j<c.size();j++){
            if(x>=c[j]){
                x-=c[j];
                clean++;
            }
        }
	    if(clean>=e) cout<<"YES\n";
	    else cout<<"NO\n";
	}
return 0;
}

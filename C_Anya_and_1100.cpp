#include <bits/stdc++.h>
using namespace std;
const int n=1e5;
#define CONTAINS(str, sub) (str.find(sub) != string::npos)
int main(){
	int t;
	cin>>t;
	while(t--){
	    string s,p;
	    cin>>s;
	    int n;
	    p="1100";
	    cin>>n;
        
	    while(n--){
	        int a;
	        char b;
	        cin>>a>>b;
	        s[a-1]=b;
	        if(CONTAINS(s,"1100"))
	        cout<<"YES"<<endl;
	        else cout<<"NO"<<endl;
	        
	    }
	}
}
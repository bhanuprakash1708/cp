#include <bits/stdc++.h>
using namespace std;
long long int fact(long long int m){
    if(m<=1)
    return 1;
    else
    return m*fact(m-1);
}
int divisors(int n){
    int c=1;
    bool a[n+1];
    for(int i=0;i<n+1;i++){
        a[i]=true;
    }
    for(int j=2;j*j<n;j++){
        if(a[j]==true){
            for(int k=j*2;k<n;k+=j){
                a[k]=false;
            }
        }
    }
    for(int j=2;j<=n;j++){
        if(a[j]){
            int d=0;
            if(n%j==0){
                while(n%j==0){
                    n/=j;
                    d++;
                }
                c*=d+1;
            }
        }
    }
    return c;
}
int main() {
	// your code goes here
long long int n,m;
cin>>n>>m;
vector<long long int> a(n),b(n),c(n);
int d=fact(m);
for(int i=0;i<n;i++){
    cin>>a[i];
    b[i]=a[i]*d;
    c[i]=divisors(b[i]);
}
for(int num:c){
    cout<<num<<" ";
}
}

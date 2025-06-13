#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define yes cout<<"YES"<<"\n";
#define no cout<<"NO"<<"\n";
#define ll long long
#define veci vector<int>
#define vecl vector<lng>
#define vecc vector<char>
#define vecii vector<vector<int>>
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define pop pop_back
#define inf 1e18
#define pi 3.141592653589793238462
#define sorti(x) sort(x.begin(),x.end())
#define sortd(x) sort(x.begin(),x.end(),greater<int>())
#define all(x) x.begin(),x.end()
#define cntset(x) __builtin_popcountll(x)
#define e <<"\n"
#define mini(v) *min_element(v.begin(),v.end())
#define maxi(v) *max_element(v.begin(),v.end())
const int M = 1e9 + 7;
const int N = 1e5 + 5; 
#ifndef ONLINE_JUDGE
#define debug(x) cerr<<#x<<" : "; print_(x); cerr<<endl;
#else
#define debug(x)
#endif
void print_(int a){cerr<<a<<" ";}
void print_(ll a){cerr<<a<<" ";}
void print_(char a){cerr<<a<<" ";}
void print_(string a){cerr<<a<<" ";}
template<class T> void print_(vector<T> v){cerr<<"{ ";for(T i : v){print_(i);cerr<<" ";}cerr<<" }";}
template<class T> void print_(set<T> st){cerr<<"{ ";for(T i : st){print_(i);cerr<<" ";}cerr<<" }";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
void txts(){
    #ifndef ONLINE_JUDGE
      freopen("input.txt","r",stdin);
      freopen("output.txt","w",stdout);
      freopen("error.txt","w",stderr);
   #endif
}
// bool ispwrof2(int x){if(x<0) return false; return x && (!(x & (x - 1)));}
// int bexp(int a, int b)
// {
//   int ans = 1;
//   while(b)
//   {
//       if(b&1) ans *= (1LL * a) % M;
//       a *= a;
//       b >>= 1;
//   }
//   return ans;
// }
void fast_io() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);
}
// ll gcd(ll a, ll b) {
//     while (b) {
//         a %= b;
//         swap(a, b);
//     }
//     return a;
// }
// ll lcm(ll a, ll b) {
//     return (a / gcd(a, b)) * b;
// }
// bool prime(ll n) {
//     if (n < 2) return false;
//     for (ll i = 2; i * i <= n; i++) {
//         if (n % i == 0) return false;
//     }
//     return true;
// }
// vector<bool> sieve(ll n) {
//     vector<bool> is_prime(n + 1, true);
//     is_prime[0] = is_prime[1] = false;
//     for (ll i = 2; i * i <= n; i++) {
//         if (is_prime[i]) {
//             for (ll j = i * i; j <= n; j += i) {
//                 is_prime[j] = false;
//             }
//         }
//     }
//     return is_prime;
// }
// ll power(ll a, ll b, ll mod = MOD) {
//     ll res = 1;
//     a %= mod;
//     while (b > 0) {
//         if (b & 1) res = (res * a) % mod;
//         a = (a * a) % mod;
//         b >>= 1;
//     }
//     return res;
// }

// ll inv(ll a, ll mod = MOD) {
//     return power(a, mod - 2, mod);
// }

// ll nCr(ll n, ll r, vector<ll>& fact, vector<ll>& invFact) {
//     if (r > n) return 0;
//     return fact[n] * invFact[r] % MOD * invFact[n - r] % MOD;
// }

// Factorials and Inverse Factorials for nCr % MOD
// void precompute_factorials(ll n, vector<ll>& fact, vector<ll>& invFact, ll mod = MOD) {
//     fact[0] = invFact[0] = 1;
//     for (ll i = 1; i <= n; i++) {
//         fact[i] = fact[i - 1] * i % mod;
//     }
//     invFact[n] = inv(fact[n], mod);
//     for (ll i = n - 1; i >= 1; i--) {
//         invFact[i] = invFact[i + 1] * (i + 1) % mod;
//     }
// }

// Binary Search
// ll binary_search(vector<ll>& arr, ll target) {
//     ll low = 0, high = arr.size() - 1;
//     while (low <= high) {
//         ll mid = low + (high - low) / 2;
//         if (arr[mid] == target) return mid;
//         else if (arr[mid] < target) low = mid + 1;
//         else high = mid - 1;
//     }
//     return -1; // Target not found
// }

// Least Common Ancestor (LCA) Template 
// const int MAXN = 100000;
// const int LOG = 20;
// vector<int> adj[MAXN];
// int up[MAXN][LOG], depth[MAXN];

// void dfs(int v, int p) {
//     up[v][0] = p;
//     for (int i = 1; i < LOG; i++) {
//         up[v][i] = up[up[v][i-1]][i-1];
//     }
//     for (int u : adj[v]) {
//         if (u != p) {
//             depth[u] = depth[v] + 1;
//             dfs(u, v);
//         }
//     }
// }

// int lca(int u, int v) {
//     if (depth[u] < depth[v]) swap(u, v);
//     for (int i = LOG - 1; i >= 0; i--) {
//         if (depth[u] - (1 << i) >= depth[v]) {
//             u = up[u][i];
//         }
//     }
//     if (u == v) return u;
//     for (int i = LOG - 1; i >= 0; i--) {
//         if (up[u][i] != up[v][i]) {
//             u = up[u][i];
//             v = up[v][i];
//         }
//     }
//     return up[u][0];
// }

// struct DSU {
//     vector<int> parent, rank;
//     DSU(int n) : parent(n), rank(n, 1) {
//         for (int i = 0; i < n; i++) parent[i] = i;
//     }
//     int find(int a) {
//         if (a == parent[a]) return a;
//         return parent[a] = find(parent[a]);
//     }
//     bool unite(int a, int b) {
//         a = find(a);
//         b = find(b);
//         if (a != b) {
//             if (rank[a] < rank[b]) swap(a, b);
//             parent[b] = a;
//             if (rank[a] == rank[b]) rank[a]++;
//             return true;
//         }
//         return false;
//     }
// };
void solve(){
    int n;
    cin>>n;
    if (n == 0){
        cout<<1<<endl;
    }
    if (n == 1){
        cout<<0<<endl;
    }
    else{
    int s[n+1]; 
    for (int i=0;i<=n;i++) {
        long long int x=(1LL*(i - 1) * (s[i - 1] + s[i - 2]));
        if(i==0)
        s[i]=1;
        else if(i==1)
        s[i]=0;
        else
        s[i] =x % MOD;
    }
    cout<<s[n]<<endl;
    }
}
int main() {
    fast_io();
    solve();
    return 0;
}
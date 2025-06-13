#include <bits/stdc++.h>  

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> p32;
typedef pair<ll,ll> p64;
typedef pair<double,double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int>> vv32;
typedef vector<vector<ll>> vv64;
typedef vector<vector<p64>> vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
ll MOD = 998244353;
double eps = 1e-12;
#define forn(i,e) for(ll i = 0; i < e; i++)
#define forsn(i,s,e) for(ll i = s; i < e; i++)
#define rforn(i,s) for(ll i = s; i >= 0; i--)
#define rforsn(i,s,e) for(ll i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout << #x << " = " << x << ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

void solve() {
    ll n, k;
    cin >> n >> k;
    vector<ll> b(n);
    for (ll i = 0; i < n; i++)
    cin >> b[i];
    map<ll, ll> fm;
    ll mf = 0;
    for (ll i = 0; i < n; i++) {
        fm[b[i]]++;
        mf = max(mf, fm[b[i]]);
    }
    if (fm[k] == mf) {
        cout << 0 << endl;
        return;
    }
    fm.clear();
    ll cm = 0; 
    bool can_make_mf = false;
    for (ll i = 0; i < n; i++) {
        fm[b[i]]++;
        cm = max(cm, fm[b[i]]);
        if (cm == fm[k] && fm[k] > 0) {
            can_make_mf = true;
            break;
        }
    }
    if (!can_make_mf) {
        fm.clear();
        cm = 0;
        for (ll i = n - 1; i >= 0; i--) {
            fm[b[i]]++;
            cm = max(cm, fm[b[i]]);
            if (cm == fm[k] && fm[k] > 0) {
                can_make_mf = true;
                break;
            }
        }
    }
    cout << (can_make_mf ? 1 : 2) << endl;
}

int main() {
    fast_cin();
    ll t;
    cin >> t;
    for (int it = 1; it <= t; it++) {
        solve();
    }
    return 0;
}

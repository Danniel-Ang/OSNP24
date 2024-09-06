#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
#define pb push_back
#define eb emplace_back
#define ppb pop_back
#define fi first
#define se second
#define ub upper_bound
#define lb lower_bound
#define pii pair<int,int>
#define pll pair<ll,ll>
#define rep(i,n) for (i = 0; i < n; ++i)
#define REP(i,k,n) for (i = k; i <= n; ++i)
#define REPR(i,k,n) for (i = k; i >= n; --i)
using namespace std;
const ll MOD = 1e9 + 7;
#define semoga_ac ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

typedef complex<double> P;
#define X real()
#define Y imag()
typedef vector<int> vi;
typedef vector<vi> vvi;

main(){
semoga_ac;
    ll n, m; cin >> n >> m;
    ll jln_terpendek = (n + m - 1);
    ll decision = min(n, m) - 1;
    ll g_decision = jln_terpendek - decision;

    ll sum = 0;
    sum += g_decision * (g_decision + 1ll) / 2ll;

    for(int i = 0; i < decision; i++){
        g_decision += 2;
        sum += g_decision;
    }
    cout << sum;
}
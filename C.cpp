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
    ll n, i, temp; cin >> n;
    ll m; cin >> m;
    vector <ll> v;
    rep(i, n){
        cin >> temp;
        v.pb(temp);
    }
    sort(v.begin(), v.end(), greater<ll>());

    ll acc = 0, befa;
    REP(i, 1, n-1){
        befa = acc;
        acc += (i) * (v[i-1] - v[i]);
        if(acc >= m){
            ll adder = i;
            temp = m - befa;
            // cout << adder << endl;
            temp = (temp / adder) + min(1ll, temp % adder);
            // cout << temp << " " << v[i-1] << " ";
            cout << v[i-1] - temp;  
            return 0;
        }
        // cout << acc << endl;
    }
    befa = acc;
    acc += (v[n-1]) * n;
    if(acc >= m){
        ll adder = i;
        temp = m - befa;
        // cout << adder << endl;
        temp = (temp / adder) + min(1ll, temp % adder);
        // cout << temp << " " << v[i-1] << " ";
        cout << v[i-1] - temp;  
        return 0;
    }
    cout << -1;
    // cout << acc << endl;

}

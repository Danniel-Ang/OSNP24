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
using namespace std;
const ll MOD = 1e9 + 7;
#define semoga_ac ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

typedef complex<double> P;
#define X real()
#define Y imag()

main(){
semoga_ac;
    ll b, c, d; cin >> b >> c >> d;
    ll n = c - d;
    ll ans = 0;

    if(n == 0){
        cout << max(0ll, b - c);
    }else{
       for(ll i = 1; i * i <= n; ++i){
            if(n % i != 0) continue;
            ll fac2 = n / i;
            if(i > d && i <= b) ans++;
            if(i != fac2 && fac2 > d && fac2 <= b) ans++; 
        }
        cout << ans;
    }
}
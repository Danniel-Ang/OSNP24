#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

main(){
    ll b, c, d; cin >> b >> c >> d;
    ll n = c - d;
    if(c == d){
        cout << max(b - c, 0ll);
    }else{
        ll ans = 0;

        // Iterasi 1 -> sqrt(n)
        for(ll i = 1; i * i <= n; i++){
            if(n % i != 0) continue;

            ll fac2 = n / i;
            if(i <= b && i > d) ans++;
            if(fac2 <= b && fac2 > d && fac2 != i) ans++;
        }
        cout << ans;
    }
}   
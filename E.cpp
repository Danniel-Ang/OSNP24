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
int exampleFunction(int n) {
    if (n <= 1) {
        return 1;
    } else if (n % 2 == 0) {
        return 1 + exampleFunction (n / 2) + exampleFunction (n / 2 - 1);
    } else {
        return 1 + exampleFunction (n - 1) + exampleFunction (n - 3);
    }
}
main(){
semoga_ac;
    for(int i = 1; i <= 100; i++){
        cout << i << " " << exampleFunction(i) << endl;
    }
}
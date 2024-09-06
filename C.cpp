#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll pref[1000001];

int main(){
     ll n, m;
     cin >> n >> m;
     
     ll maxx = -1;

     for(int i = 0; i < n; i++){
          ll in; cin >> in;
          in--;
          pref[in]++;
          maxx = max(maxx, in);
     }

     ll cnt = 0;
     for(int i = maxx; i >= 0; i--){
          cnt += pref[i];
          pref[i] = cnt + pref[i+1];
     }

     ll ans = -1;
     ll l = 0, r = maxx, mid;
     while(l <= r){
          mid = (l + r)/2;
          if(pref[mid] >= m){
               ans = mid;
               l = mid + 1;
          }else{
               r = mid - 1;
          }
     }
     cout << ans;
}
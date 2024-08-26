#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll ar[1000001];

int main(){
     ll n, m;
     cin >> n >> m;
     
     ll maxx = -1;

     for(int i = 0; i < n; i++){
          ll in; cin >> in;
          ar[in-1]++;
          maxx = max(maxx, in-1);
     }   

     ll cnt = ar[maxx];
     for(int i = maxx-1; i >= 0; i--){
          cnt += ar[i];
          ar[i] = ar[i+1] + cnt;
          // cout << i << " " << ar[i] << endl;
     }

     int l, r, mid; l = 0; r = maxx;
     ll ans = -1;
     while(l <= r){
          mid = (l + r) >> 1;
          if(ar[mid] >= m){
               ans = mid;
               l = mid + 1;
          }else{
               r = mid - 1;
          }
     }
     cout << ans;
}
#include <iostream>
#include <string>
using namespace std;

int cek(string s, string uji){
    int ans = 0;
    int i = 0;
    for(char c : s){
        if(c != uji[i]) continue;
        ans++;
        i++;
        i %= 3;
    }
    return ans;
}

int main(){
    string s; cin >> s;
    int ans = 0;
    ans = max(ans, cek(s, "OSN"));
    ans = max(ans, cek(s, "ONS"));
    ans = max(ans, cek(s, "SON"));
    ans = max(ans, cek(s, "SNO"));
    ans = max(ans, cek(s, "NOS"));
    ans = max(ans, cek(s, "NSO"));
    if(ans < 3) cout << -1;
    else cout << ans;
}
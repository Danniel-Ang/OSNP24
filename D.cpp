#include <iostream>
#include <cstring>
using namespace std;

int main(){
    string b, y;
    cin >> b >> y;
    long long dp[y.length()+1];
    long long mod = 1000000007;

    memset(dp, 0ll, sizeof(dp));
    dp[y.length()] = 1;
    for(int i = y.length()-1; i >= 0; i--){

        string temp = "";
        temp += y[i];
        
        if(stoi(temp) >= stoi(b)) break;
        dp[i] = dp[i+1];
        
        if(y[i] == '0') continue;

        for(int j = 1; j < b.length() && i + j < y.length(); j++){
            temp += y[i+j];
            if(stoi(temp) < stoi(b)){
                dp[i] += dp[i+j+1];
                dp[i] %= mod;
            }else{
                break;
            }
        }
    }
    cout << dp[0] << endl;
}


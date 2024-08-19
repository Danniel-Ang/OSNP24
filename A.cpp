#include <iostream>
#include <string>
using namespace std;

string s; 

// Menghitung panjang string cantik dengan pola tertentu pada S
int cek(string pola){ // OSN, ONS, 0 -> 1 -> 2 -> 0
    int j = 0;
    int ans = 0; // Panjang string cantik osn saat ini
    for(int i = 0; i < s.length(); i++){
        if(s[i] == pola[j]){
            ans++;
            j++;
            j %= 3;
        }
    }
    return ans;
}

int main(){
    cin >> s;
    int maxx = 0;
    maxx = max(maxx, cek("OSN"));
    maxx = max(maxx, cek("ONS"));
    maxx = max(maxx, cek("SON"));
    maxx = max(maxx, cek("SNO"));
    maxx = max(maxx, cek("NOS"));
    maxx = max(maxx, cek("NSO"));
    if(maxx < 3){
        cout << -1;
    }else{
        cout << maxx;
    }
}
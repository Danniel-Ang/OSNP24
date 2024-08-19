#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
typedef long long ll;
using namespace std;

int n, m, k;
ll sum = 0;
ll b[100001];
ll g[100001];
vector <int> adj[100001];
bool vis[100001];

int main(){
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++){
        cin >> b[i];
    }
    for(int i = 1; i <= m; i++){
        cin >> g[i];
    }
    sort(g + 1, g + m + 1);
    for(int i = 0; i < k; i++){
        int p, q; cin >> p >> q;
        adj[p].push_back(q);
        adj[q].push_back(p);
    }  
    for(int i = 1; i <= n; i++){
        if(vis[i]) continue;

        vector <ll> acc = {b[i]};
        vis[i] = true;            
        queue <int> q; q.push(i);
        while(!q.empty()){
            int now = q.front();
            q.pop();
            for(int u : adj[now]){
                if(!vis[u]){
                    q.push(u);
                    vis[u] = true;
                    acc.push_back(b[u]);
                }
            }
        }

        sort(acc.begin(), acc.end());
        ll med = acc[acc.size() / 2];

        ll sv1 = g[m], sv2 = g[1];
        int l = 1, r = m, mid;
        while(l <= r){
            mid = (l + r) >> 1;
            if(g[mid] >= med){
                sv1 = g[mid];
                r = mid - 1;
            }else{
                l = mid + 1;
            }
        }
        l = 1; r = m;
        while(l <= r){
            mid = (l + r) >> 1;
            if(g[mid] <= med){
                sv2 = g[mid];
                l = mid + 1;
            }else{
                r = mid - 1;
            }
        }

        ll ans1, ans2;
        ans1 = ans2 = 0;
        for(ll u: acc){
            ans1 += abs(sv1 - u);
            ans2 += abs(sv2 - u);
        }
        sum += min(ans1, ans2);
    }
    cout << sum;
}

// 1 2 2 4 7 7 8
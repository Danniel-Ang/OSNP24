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

    for(int i = 1; i <= k; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i = 1; i <= n; i++){
        if(vis[i]) continue;
        vis[i] = true;

        queue <int> q;
        vector <ll> v;

        v.push_back(b[i]);
        q.push(i);

        while(!q.empty()){
            int now = q.front();
            q.pop();

            for(int u: adj[now]){
                if(vis[u]) continue;
                vis[u] = true;
                q.push(u);
                v.push_back(b[u]);
            }
        }
        sort(v.begin(), v.end());
        ll med = v[v.size() / 2];

        int l, r, mid, save = 1;
        l = 1; r = m;
        while(l <= r){
            mid = (l + r) / 2;
            if(g[mid] <= med){
                save = mid;
                l = mid + 1;
            } else r = mid - 1;
        }

        ll ans1 = 0;
        ll ans2 = 0;
        for(ll u: v){
            ans1 += abs(u - g[save]);
            if(save + 1 <= m) ans2 += abs(u - g[save + 1]);
        }
        if(save + 1 <= m) sum += min(ans1, ans2);
        else sum += ans1;
        // cout << sum << endl;
    }
    cout << sum;
}

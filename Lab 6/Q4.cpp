#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
int V, E;
vector<int> adj[N];
bool vis[N], cvis[N];

bool dfs(int s){
    vis[s] = 1;
    cvis[s] = 1;
    for(auto x:adj[s]){
        if(!vis[x]){
            if(dfs(x)) return true;
        }else if(cvis[x])
            return true;
    }
    cvis[s] = 0;
    return false;
}

int main(){
    freopen("test_cases_Q4.txt","r",stdin);
    freopen("output_Q4.txt","w",stdout);
    int t; cin >> t;
    while(t--){
        cin >> V >> E;
        for(int i=0; i<V; i++){
            adj[i].clear();
            vis[i] = 0;
        }
        for(int i=0; i<E; i++){
            int u, v; cin >> u >> v;
            u--; v--;
            adj[u].push_back(v);
        }
        bool d = 0;
        for(int i=0; i<V; i++){
            if(!vis[i] && dfs(i)){
                cout << "YES\n";
                d = 1; break;
            }
        }
        if(!d)
            cout << "NO\n";
    }
}
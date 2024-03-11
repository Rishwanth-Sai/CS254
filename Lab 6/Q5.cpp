#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
int V, E;
vector<int> adj[N];
bool nvis[N], bvis[N];
int ndis[N], nlow[N], bdis[N], blow[N];

bool node_dfs(int u, int p, int &time){
    nvis[u] = true;
    ndis[u] = nlow[u] = ++time;
    int child = 0;
    for(auto v:adj[u]){
        if(!nvis[v]){
            child++;
            if(node_dfs(v, u, time)) 
                return true;
            nlow[u] = min(nlow[u], nlow[v]);
            if(p != -1 && nlow[v]>=ndis[u])
                return true;
        }
        else if(v != p)
            nlow[u] = min(nlow[u], ndis[v]);
    }
    if(p == -1 && child>1)
        return true;
    return false;
}

bool edge_dfs(int u, int p, int &time){
    bvis[u] = true;
    bdis[u] = blow[u] = ++time;
    for(auto v:adj[u]){
        if(!bvis[v]){
            if(edge_dfs(v, u, time)) 
                return true;
            blow[u] = min(blow[u], blow[v]);
            if(blow[v] > bdis[u])
                return true;
        }
        else if(v != p)
            blow[u] = min(blow[u], bdis[v]);
    }
    return false;
}

int main(){
    freopen("test_cases_Q5.txt","r",stdin);
    freopen("output_Q5.txt","w",stdout);
    int t; cin >> t;
    while(t--){
        cin >> V >> E;
        for(int i=0; i<V; i++){
            adj[i].clear();
            nvis[i] = bvis[i] = 0;
            ndis[i] = nlow[i] = bdis[i] = blow[i] = 0;
        }
        for(int i=0; i<E; i++){
            int u, v; cin >> u >> v;
            u--; v--;
            adj[u].push_back(v);
        }
        cout << "Has Articulation Nodes: ";
        int ntime = 0, nd = 0;
        for(int i=0; i<V; i++)
            if(!nvis[i] && node_dfs(i, -1, ntime)){
                cout << "YES\n"; nd = 1;
                break;
            }
        if(!nd) cout << "NO\n";
        cout << "Has Articluation Bridges: ";
        int btime = 0, bd = 0;
        for(int i=0; i<V; i++)
            if(!bvis[i] && edge_dfs(i, -1, btime)){
                cout << "YES\n"; bd = 1;
                break;
            }
        if(!bd) cout << "NO\n";
    }
}
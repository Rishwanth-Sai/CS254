#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
int V, E;
vector<int> adj[N];
bool vis[N];

void dfs(int s, stack<int> &st){
    vis[s] = 1;
    for(auto x:adj[s])
        if(!vis[x])
            dfs(x, st);
    st.push(s);
}

vector<int> topological_sort(){
    stack<int> st;
    vector<int> srt;
    for(int i=0; i<V; i++)
        if(!vis[i])
            dfs(i, st);
    while(!st.empty()){
        srt.push_back(st.top());
        st.pop();
    }
    return srt;
}

int main(){
    freopen("test_cases_Q2.txt","r",stdin);
    freopen("output_Q2.txt","w",stdout);
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
        vector<int> tsrt = topological_sort();
        reverse(tsrt.begin(), tsrt.end());
        vector<int> dist(V);
        for(auto s:tsrt)
            for(auto x:adj[s])
                dist[s] = max(dist[s], dist[x]+1);
        cout << *max_element(dist.begin(), dist.end()) << endl;
    }
}
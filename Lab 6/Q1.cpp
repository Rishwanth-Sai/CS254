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

void topological_sort(){
    stack<int> st;
    for(int i=0; i<V; i++)
        if(!vis[i])
            dfs(i, st);
    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }
}

int main(){
    freopen("test_cases_Q1.txt","r",stdin);
    freopen("output_Q1.txt","w",stdout);
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
        topological_sort();
        cout << endl;
    }
}
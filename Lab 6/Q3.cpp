#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
int V, E;
vector<int> adj[N], radj[N];
bool vis[N], rvis[N];

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

void rdfs(int s){
    rvis[s] = 1; cout << s << " ";
    for(auto x:radj[s])
        if(!rvis[x])
            rdfs(x);
}

int main(){
    freopen("test_cases_Q3.txt","r",stdin);
    freopen("output_Q3.txt","w",stdout);
    int t; cin >> t;
    while(t--){
        cin >> V >> E;
        for(int i=0; i<V; i++){
            adj[i].clear();
            radj[i].clear();
            vis[i] = 0;
            rvis[i] = 0;
        }
        for(int i=0; i<E; i++){
            int u, v; cin >> u >> v;
            u--; v--;
            adj[u].push_back(v);
            radj[v].push_back(u);
        }
        vector<int> tsrt = topological_sort();
        for(auto i:tsrt){
            if(!rvis[i]){
                rdfs(i);
                cout << endl;
            }
        }
    }
}
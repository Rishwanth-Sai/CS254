#include<bits/stdc++.h>
using namespace std; 

struct dsu{
    vector<int> parent; 
    vector<int> set_size; 
    void init(int sz){
        parent.assign(sz+1,0); 
        set_size.assign(sz+1,1); 
        iota(parent.begin(),parent.end(),0); 
    }
    int find(int s){
        if (s == parent[s])
            return s;
        return parent[s] = find(parent[s]);
    }
    void merge(int u, int v){
        u = find(u); 
        v = find(v); 
        if(set_size[u] > set_size[v])
            swap(u,v); 
        parent[u] = v; 
    }
};

int main(){
    freopen("test_cases_Q1.txt","r",stdin); 
    freopen("output_Q1.txt","w",stdout); 
    int n, e; cin>> n >> e; 
    vector<vector<int>> edges; 
    vector<vector<int>> mst_edges;
    long long wt = 0; 
    for(int i = 0; i < e; i++){
        int u, v, w; cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }
    sort(edges.begin(),edges.end(),[](auto a, auto b){
        return a[2] > b[2]; 
    }); 
    dsu dsu; 
    dsu.init(n); 
    for(int i = 0; i < e && mst_edges.size() < n; i++){
        if(dsu.find(edges[i][0]) != dsu.find(edges[i][1])){
            dsu.merge(edges[i][0],edges[i][1]); 
            mst_edges.push_back(edges[i]); 
            wt += edges[i][2]; 
        }
    }
    cout << wt << endl; 
    for(auto edge : mst_edges)
        cout << edge[0] << " " << edge[1] << " " << edge[2] << endl;
}
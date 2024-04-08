#include<bits/stdc++.h>
#define INF LLONG_MAX
#define int long long

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

signed main(){
    freopen("test_cases_Q3.txt","r",stdin); 
    freopen("output_Q3.txt","w",stdout); 
    int n, e; cin >> n >> e; 
    vector<vector<int>> edges; 
    vector<int> mst_edges;
    for(int i = 0; i < e; i++){
        int u, v, w; cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }
    sort(edges.begin(),edges.end(),[](auto a, auto b){
        return a[2] < b[2]; 
    }); 
    dsu uf1; 
    uf1.init(n); 
    for(int i = 0; i < e && mst_edges.size() < n; i++){
        if(uf1.find(edges[i][0]) != uf1.find(edges[i][1])) {
            uf1.merge(edges[i][0],edges[i][1]); 
            mst_edges.push_back(i); 
        }
    }
    int wt = INF; 
    vector<int> second_mst_edges; 
    for(auto excluded_edge : mst_edges){
        dsu uf2; 
        uf2.init(n); 
        vector<int> temp_edges; 
        int temp_wt = 0; 
        for(int i = 0; i < e && temp_edges.size() < n; i++){   
            if(i == excluded_edge) continue; 
            if(uf2.find(edges[i][0]) != uf2.find(edges[i][1])) {
                uf2.merge(edges[i][0],edges[i][1]); 
                temp_edges.push_back(i);
                temp_wt += edges[i][2];  
            }
        }
        if(temp_wt < wt){
            wt = temp_wt; 
            second_mst_edges = temp_edges;  
        }
    }
    cout << wt << endl; 
    for(auto idx : second_mst_edges)
        cout << edges[idx][0] << " " << edges[idx][1] << " " << edges[idx][2] << endl; 
}
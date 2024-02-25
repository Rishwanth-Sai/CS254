#include <bits/stdc++.h>
using namespace std;

int n;

bool is_bipartite(int s, int c, vector<int> &cans, vector<vector<bool>> &g){
    if(cans[s] > -1){
        if(c != cans[s])
            return false;
        return true;
    }
    cans[s] = c;
    for(int i=0; i<n; i++)
        if(g[s][i] && !is_bipartite(i, 1-c, cans, g))
            return false;
    return true;
}

int main(){
    freopen("test_cases_Q3.txt","r",stdin);
    freopen("output_Q3.txt","w",stdout);
    int t; cin >> t;
    while(t--){
        cin >> n;
        vector<vector<bool>> adj(n, vector<bool>(n));
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                bool c; cin >> c;
                if(i != j)
                    adj[i][j] = !c;
            }
        }
        vector<int> cans(n, -1);
        int ans = 1;
        for(int i=0; i<n; i++)
            if(cans[i] == -1)
                if(!is_bipartite(i, 0, cans, adj))
                    ans = 0;
        if(ans)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
}
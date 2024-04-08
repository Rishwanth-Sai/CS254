#include <bits/stdc++.h>
#define INF 1e18
#define int long long

using namespace std;

void rec(int msk, int last_node, int last_col, vector<vector<vector<int>>> &adj, vector<vector<vector<int>>> &dp){
    if(dp[msk][last_node][last_col] != -1)
        return;
    int &res = dp[msk][last_node][last_col];
    if(msk == 0){
        res = 0;
        return;
    }
    res = INF;
    for(auto x:adj[last_node]){
        if(((1 << x[0]) & msk) && (x[1] == last_col)){
            rec((msk ^ (1 << x[0])), x[0], 1-last_col, adj, dp);
            res = min(res, dp[(msk ^ (1 << x[0]))][x[0]][1-last_col]+x[2]);
        }
    }
}

void construct_tree(int curr_node, int cur_msk, int last_col, vector<vector<int>> &edg, vector<vector<vector<int>>> &adj, vector<vector<vector<int>>> &dp){
    int nxt_min_ans = INF, nxt_min_node = -1;
    for(auto x:adj[curr_node]){
        if(x[1] == last_col && (cur_msk & (1 << x[0]))){
            if(dp[(cur_msk ^ (1 << x[0]))][x[0]][1-last_col] < nxt_min_ans){
                nxt_min_ans = dp[(cur_msk ^ (1 << x[0]))][x[0]][1-last_col];
                nxt_min_node = x[0];
            }
        }
    }
    if(nxt_min_node == -1)
        return;
    int cur_wei = INF;
    for(auto x:adj[curr_node])
        if(x[0] == nxt_min_node && x[1] == last_col)
            cur_wei = min(cur_wei, x[2]);
    edg.push_back({curr_node, nxt_min_node, last_col, cur_wei});
    construct_tree(nxt_min_node, (cur_msk ^ (1 << nxt_min_node)), 1-last_col, edg, adj, dp);
}

vector<vector<int>> alternating_MST(vector<vector<vector<int>>> &adj){
    int n = adj.size();
    int ans_last_node = -1, ans_last_col = -1, ans = INF;
    int msk = (1 << n) - 1;
    vector<vector<vector<int>>> dp(msk+1, vector<vector<int>>(n, vector<int>(2, -1)));
    for(int i=0; i<n; i++){
        rec((msk ^ (1 << i)), i, 0, adj, dp);
        rec((msk ^ (1 << i)), i, 1, adj, dp);
        if(ans > dp[(msk ^ (1 << i))][i][0]){
            ans = dp[(msk ^ (1 << i))][i][0];
            ans_last_col = 0;
            ans_last_node= i;
        }
        if(ans > dp[(msk ^ (1 << i))][i][1]){
            ans = dp[(msk ^ (1 << i))][i][1];
            ans_last_col = 1;
            ans_last_node= i;
        }
    }
    if(ans_last_node == -1)
        return {};
    vector<vector<int>> edg;
    cout << ans << endl;
    construct_tree(ans_last_node, (msk ^ (1 << ans_last_node)), ans_last_col, edg, adj, dp);
    return edg;
}

signed main(){
    freopen("test_cases_Q2.txt","r",stdin);
    freopen("output_Q2.txt","w",stdout);
    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        vector<vector<vector<int>>> adj(n);
        for(int i=0; i<m; i++){
            int u, v, w, c; cin >> u >> v >> c >> w;
            u--; v--;
            adj[u].push_back({v, c, w});
            adj[v].push_back({u, c, w});
        }
        cout << endl;
        vector<vector<int>> edg = alternating_MST(adj);
        if(edg.size() == 0)
            cout << "MST not possible\n";
        else
            for(auto i:edg)
                cout << i[0]+1 << " " << i[1]+1 << " " << i[2] << " " << i[3] << endl;
    }
}
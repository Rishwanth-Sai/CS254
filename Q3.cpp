#include <iostream>
#include <vector>
#define int long long
using namespace std;

int n;

vector<vector<int>> adj;
vector<vector<int>> dp;

int func(int i, int s){
    if(dp[i][s] != 0)
        return dp[i][s];
    
    if(__builtin_popcount(s) == 2)
        return dp[i][s] = adj[0][i];
    
    int res = INT_MAX;
    for(int msk = 1; msk < n; msk++)
        if((s & (1 << msk)) && msk != i)
            res = min(res, func(msk, s ^ (1 << i)) + adj[msk][i]);
    return dp[i][s] = res;
}

signed main(){
    freopen("test_cases_Q3.txt","r",stdin);
    freopen("output_Q3.txt","w",stdout);
    int t; cin >> t;
    while(t--){
        cin >> n;
        dp.resize(n);
        adj.resize(n);
        for(int i=0; i<n; i++){
            adj[i].resize(n);
            for(int j=0; j<n; j++)
                cin >> adj[i][j];
            dp[i].resize(1 << n);
        }
        int ans = INT_MAX;
        for(int j=1; j<n; j++)
            ans = min(ans, func(j, (1 << n)-1) + adj[j][0]);
        cout << ans << endl;
    }
}
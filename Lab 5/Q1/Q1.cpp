#include <bits/stdc++.h>
using namespace std;

int n, m;

void dfs(int i, int j, int &cnt, vector<vector<int>> &g){
    if(i == -1 || i == n || j == -1 || j == m || g[i][j] != 1)
        return;
    g[i][j] = -1;
    cnt++;
    dfs(i-1, j-1, cnt, g);
    dfs(i-1, j, cnt, g); 
    dfs(i-1, j+1, cnt, g);
    dfs(i, j-1, cnt, g);
    dfs(i, j+1, cnt, g);
    dfs(i+1, j-1, cnt, g);
    dfs(i+1, j, cnt, g); 
    dfs(i+1, j+1, cnt, g);
}

int main(){
    freopen("test_cases_Q1.txt","r",stdin);
    freopen("output_Q1.txt","w",stdout);
    int t; cin >> t;
    while(t--){
        cin >> n >> m;
        vector<vector<int>> g(n, vector<int>(m));
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                cin >> g[i][j];
        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(g[i][j] == 1){
                    int cans = 0;
                    dfs(i, j, cans, g);
                    ans = max(ans, cans);
                }
            }
        }
        cout << "Size of the largest Region: " << ans << endl;
    }
}
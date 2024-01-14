#include <iostream>
#include <vector>
using namespace std;

int main(){
    freopen("test_cases_Q2.txt","r",stdin);
    freopen("output_Q2.txt","w",stdout);
    int t; cin >> t;
    while(t--){
        int n, max_weight; cin >> n >> max_weight;
        vector<long long> weights(n), values(n);
        for(int i=0; i<n; i++)
            cin >> weights[i];
        for(int i=0; i<n; i++)
            cin >> values[i];
        vector<long long> dp(max_weight+1);
        for(int i=0; i<n; i++)
            for(int j=max_weight; j>=0; j--)
                if(j >= weights[i])
                    dp[j] = max(dp[j], dp[j-weights[i]] + values[i]);
        long long ans = 0;
        for(auto x:dp)
            ans = max(ans, x);
        cout << ans << endl;
    }
}
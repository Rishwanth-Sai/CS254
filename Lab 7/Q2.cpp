#include <bits/stdc++.h>
#define int long long
using namespace std;

struct profit_order {
    bool operator()(pair<int,int> &a, pair<int,int> &b){
        return a.second < b.second;
    }
};

int job_selection(vector<pair<int,int>> &jobs){
    int n = jobs.size(), ans = 0;
    vector<pair<int, int>> order;
    sort(jobs.begin(), jobs.end(), [](pair<int, int> &a, pair<int, int> &b){
        return a.first < b.first;
    });
    priority_queue<pair<int,int>, vector<pair<int,int>>, profit_order> pq;
    for(int i=n-1; i>-1; i--){
        int slots_available = jobs[i].first;
        if(i) slots_available -= jobs[i-1].first;
        pq.push(jobs[i]);
        while(slots_available && !pq.empty()){
            auto job = pq.top(); pq.pop();
            order.push_back(job);
            ans += job.second;
            slots_available--;
        }
    }
    sort(order.begin(), order.end(), [](pair<int, int> &a, pair<int, int> &b){
        return a.first < b.first;
    });
    return ans;
}

signed main(){
    freopen("test_cases_Q2.txt","r",stdin);
    freopen("output_Q2.txt","w",stdout);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<pair<int,int>> jobs(n); //{deadline, profit}
        for(int i=0; i<n; i++)
            cin >> jobs[i].first >> jobs[i].second;
        cout << job_selection(jobs) << endl;
    }
}
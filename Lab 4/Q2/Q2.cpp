#include <bits/stdc++.h>
using namespace std;

double median_sorted(vector<int> a1, vector<int> a2){
    if(a1.size() > a2.size())
        swap(a1, a2);
    int n = a1.size(), m = a2.size();
    if(!n){
        if(!(m%2))
            return (a2[m/2-1] + a2[m/2])/2.0;
        return a2[m/2]*1.0;
    }
    int l = -1, r = n;
    while(l <= r){
        int l1 = (l+r)/2, r1 = l1+1;
        int l2 = (n+m+1)/2 - (l1+1) - 1, r2 = l2+1;
        int l1e = (l1 > -1 ? a1[l1] : INT_MIN), r1e = (r1 < n ? a1[r1] : INT_MAX);
        int l2e = (l2 > -1 ? a2[l2] : INT_MIN), r2e = (r2 < m ? a2[r2] : INT_MAX);
        if(l1e > r2e)
            r = l1-1;
        else if(l2e > r1e)
            l = l1+1;
        else{
            if((n+m)%2)
                return max(l1e, l2e)*1.0;
            else
                return (max(l1e, l2e) + min(r1e, r2e))/2.0;
        }
    }
    return 0.0;
}

int main(){
    freopen("test_cases_Q2.txt","r",stdin);
    freopen("output_Q2.txt","w",stdout);
    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        vector<int> a(n), b(m);
        for(int i=0; i<n; i++)
            cin >> a[i];
        for(int i=0; i<m; i++)
            cin >> b[i];
        cout << "Median of the two sorted arrays: "<< median_sorted(a, b) << endl;
    }
}
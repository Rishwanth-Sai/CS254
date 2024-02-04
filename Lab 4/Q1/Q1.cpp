#include <bits/stdc++.h>
using namespace std;

long long merge(vector<int> &a, int l, int m, int r){
    long long ans = 0;
    vector<int> c(r-l+1);
    int k = 0, i = l, j = m;
    while(i < m && j < r+1){
        if(a[i] <= a[j])
            c[k++] = a[i++];
        else if(a[i] > a[j]){
            ans += (m-i);
            c[k++] = a[j++];
        }
    }
    while(i < m)
        c[k++] = a[i++];
    while(j < r+1)
        c[k++] = a[j++];
    for(int i=0; i<k; i++)
        a[i+l] = c[i];
    return ans;
}

long long merge_sort(vector<int> &a, int l, int r){
    if(l >= r)
        return 0;
    int mid = (r+l)/2;
    long long rans = merge_sort(a, l, mid);
    long long lans = merge_sort(a, mid+1, r);
    long long cans = merge(a, l, mid+1, r);
    return lans+cans+rans;
}

int main(){
    freopen("test_cases_Q1.txt","r",stdin);
    freopen("output_Q1.txt","w",stdout);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> a(n);
        for(int i=0; i<n; i++)
            cin >> a[i];
        cout << "Number of Inversions: " << merge_sort(a, 0, n-1) << endl;
    }
}
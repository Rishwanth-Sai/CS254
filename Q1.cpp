#include <iostream>
#include <vector>
using namespace std;

int main(){
    freopen("test_cases_Q1.txt","r",stdin);
    freopen("output_Q1.txt","w",stdout);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        long long mx1 = LLONG_MIN, mx2 = LLONG_MIN;
        for(int i=0; i<n; i++){
            long long t; cin >> t;
            if(t >= mx1){
                mx2 = mx1;
                mx1 = t;
            }else if(t > mx2)
                mx2 = t;
        }
        cout << mx1 + mx2 << endl;
    }
}
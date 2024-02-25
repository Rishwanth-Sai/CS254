#include <bits/stdc++.h>
#define PII pair<int, int>
#define F first
#define S second
using namespace std;

int min_throw(int n, vector<int> &a){
    map<int, int> sna, lad;
    for(int i=0; i<2*n; i+=2){
        if(a[i] < a[i+1])
            lad[a[i]-1] = a[i+1]-1;
        else
            sna[a[i]-1] = a[i+1]-1;
    }
    queue<PII> q;
    vector<bool> vis(30, 0);
    vis[0] = 1;
    q.push({0, 0});
    while(!q.empty()){
        PII cur = q.front(); q.pop();
        if(cur.F == 29)
            return cur.S;
        for(int cp = cur.F+1; cp <= min(cur.F+6, 29); cp++){
            int c = cp;
            if(lad.count(c))
                c = lad[c];
            else if(sna.count(c))
                c = sna[c];
            if(!vis[c]){
                vis[c] = 1;
                q.push({c, cur.S+1});
            }
        }
    }
}

int main(){
    freopen("test_cases_Q2.txt","r",stdin);
    freopen("output_Q2.txt","w",stdout);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> a(2*n);
        for(int i=0; i<2*n; i++)
            cin >> a[i];
        cout << "Minimum number of throws is: "<<  min_throw(n, a) << endl;
    }
}
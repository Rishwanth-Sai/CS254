  #include<bits/stdc++.h>
  using namespace std;
  long long givecross(vector<long long>&a,int low,int high,int mid){
        long long leftsum=INT16_MIN ,rightsum=INT16_MIN;
        long long x=0,y=0;
        for(int i=mid;i>=low;i--){
             x+=a[i];
             leftsum=max(leftsum,x);

              
        }
        for(int i=mid+1;i<=high;i++){
              y+=a[i];
             rightsum=max(rightsum,y);
        }
        return leftsum+rightsum;
  }
  long long maxsum(vector<long long>&a,int low,int high){
  int mid=(low+high)/2;
  if(low==high){return a[low];}
  if(low+1==high){return max({a[low],a[high],a[low]+a[high]});}
  while(low<high){
    long long leftside=maxsum(a,low,mid);
    long long rightside=maxsum(a,mid,high);
    long long cross=givecross(a,low,high,mid);
    return max(max(leftside,rightside),cross);
  }
  }
  int main()
  {
    freopen("input_Q2.txt","r",stdin);
    freopen("output_Q2.txt","w",stdout);
  int t;
  cin>>t;
  while(t--)
  {
    int n;cin>>n;
    vector<long long>a(n);
    for(auto i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<maxsum(a,0,n-1)<<'\n';
  }
    return 0;
  }

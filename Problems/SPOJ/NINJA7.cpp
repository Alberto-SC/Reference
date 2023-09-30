#include <bits/stdc++.h>
#define print(A) for(auto c:A)cout<<c<<" ";
using namespace std;
int main(){ 
    long long t,n,ai,ans;
    vector<int>A;
    vector<int>B;
    vector<int> min;
    cin>>t;
    while(t--){
        A.clear();
        B.clear();
        min.clear();
        cin>>n;
        for(int i = 0;i<n;i++){
            cin>>ai;
            A.push_back(ai);
        }
        for(int i = 0;i<n;i++){
            cin>>ai;
            B.push_back(ai);
        }
        long long ans = 0,sum= 0;
        for(int i = 0;i<n;i++){
            int d = A[i]-B[i];
            if(d>0) {
                ans++;
                sum+=d;
            }
            else min.push_back(-d);
        }
        sort(min.begin(),min.end());
        for(int  i:min){
            if(i>sum)break;
            ans++;
            sum-=i;
        }
        cout<<ans<<endl;
    }

    return 0;
}
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,ai,bi;
    cin>>n;
    vector<pair<int,int>> nums;
    for(int i = 0;i<n;i++){
        cin>>ai>>bi;
        nums.push_back({ai,bi});
    }
    int cont = 0;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            if(i == j)continue;
            if(nums[j].second == nums[i].first){cont++;break;}
        }
    }
    
    cout<<n-cont<<endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,a;
    cin>>n;
    vector<int> t;
    vector<int> nums(n);  
    //Online;
    for(int i = 0;i<n;i++){
        cin>>a;
        nums[i] = a;
        auto idx = upper_bound(t.begin(),t.end(),a);
        if(idx == t.end())t.push_back(a);
        else *idx = a;
    }
    cout<<n-t.size()<<endl;
    //ofline
    int inf = 1000000000;
    vector<int> t2(n+1,inf);
    t2[0] = -1;
    for(auto c:nums){
        int idx = upper_bound(t2.begin(),t2.end(),x)-t2.begin();
        t2[idx] = c;
    }
    int ans = 0;
    for(int i = 1;i<=n;i++){
        if(t2[i]== inf)break;
        ans++;
    }
    cout<<ans<<endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
int main(){
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        if(next_permutation(nums.begin(),nums.end())){
            for(auto c:nums)cout<<c;
            cout<<endl;
        }
        else cout<<-1<<endl;

    }

    return 0;
}
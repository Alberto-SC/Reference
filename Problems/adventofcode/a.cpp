#include <bits/stdc++.h>
using namespace std;
int main(){
    int n = 0,num;
    map<int,int> nums;
    int ans = 0;
    vector<int> v;
    while(cin>>num){
        nums[num]++;
        n++;
        v.push_back(num);
    }
    for(int i = 0;i<n;i++){
        for(int j = i;j<n;j++){
            int x = 2020-(v[i]+v[j]);
            cout<<x<<endl;
            if(nums.count(x)){
                ans = v[i]*v[j]*x;
                cout<<v[i]<<" "<<v[j]<<" "<<x<<endl;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
const lli mod = 2147483647;
int main(){
    int n;
    while(cin>>n){
        lli ans = 1;
        vector<int> nums(n-1);
        set<pair<int,int>> segments;
        int s1,e1;
        cin>>s1>>e1;
        segments.insert({s1,e1});
        bool two = false;
        for(auto &c:nums)cin>>c;
        int mult = 1;
        for(int i = 0;i<n-1;i++){
            bool flag = false;
            set<pair<int,int>> copy = segments;
            cout<<nums[i]<<endl;
            for(auto c:copy){
                cout<<c.first<<" "<<c.second<<endl;
                if(nums[i]>c.first && nums[i]<c.second){
                    cout<<"CRECE"<<endl;
                    flag =true;
                    mult++;
                    segments.insert({c.first,nums[i]});
                    segments.insert({nums[i],c.second});
                    segments.erase(c);
                    
                }
                else if(nums[i]<=c.first){
                    segments.insert({nums[i],c.second});
                    segments.erase(c);
                }
                else if(nums[i]>=c.second){
                    segments.insert({c.second,nums[i]});
                    segments.erase(c);
                }
            }
            cout<<endl<<endl;
            // if(flag)
                ans = ((ans%mod)*(mult%mod))%mod;
        }
        cout<<ans<<endl;
    }
    return 0;
}
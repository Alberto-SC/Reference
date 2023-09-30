#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        int one = 0,zero = 0;
        vector<int> nums(n);
        vector<int> type(n);
        for(auto &c:nums)cin>>c;
        for(auto &c:type)cin>>c;
        for(int i = 0;i<n;i++){
            if(type[i]== 0)zero++;
            else one++;
        }

        if(zero && one)cout<<"Yes"<<endl;
        else{
            bool flag = true;
            for(int i = 0;i<n-1;i++){
                if(nums[i]>nums[i+1])flag = false;
            }
            if(flag)cout<<"Yes"<<endl;
            else 
                cout<<"No"<<endl;

        }
    }

    return 0;
}
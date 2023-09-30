#include <bits/stdc++.h>
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl '\n'


using namespace std;

signed main(){
    int T,n;
    cin>>T;
    while(T--){
        cin>>n;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        vector<int> ans(n);
        int sum = accumulate(nums.begin(),nums.end(),0ll);
        if(sum != n-1){
            cout<<"NO"<<endl;
            continue;
        }
        ans[0] = 1;
        vector<int> f;
        bool flag = true;
        if(nums[0]!=0)flag = false;
        int last = 1;
        for(int i = 1;i<n;i++){
            if(nums[i]== 0){
                f.push_back(i+1);
            }
            else{
                ans[last++] = i+1;
                nums[i]--;
                if(f.size()<nums[i]){
                    flag = false;
                    break;
                }
                while(nums[i]--){
                    ans[last++] = f.back();
                    f.pop_back();
                }
            }
        }
        if(flag){
            cout<<"YES"<<endl;
            for(auto c:ans)cout<<c<<" ";
            cout<<endl;
        }
        else cout<<"NO"<<endl;
    }
    return 0;
}


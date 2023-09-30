#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> nums(n);
        vector<int> odd;
        for(auto &c:nums)cin>>c;
        for(int i = 0;i<n;i++){
            if(nums[i]&1)
                odd.push_back(i);
        }
        if(n&1){
            if(odd.size()!= n/2 && odd.size()!= (n+1)/2)
                cout<<-1<<endl;
            else if(odd.size()==n/2){
                int start = 1,ans = 0;
                for(int i = 0;i<odd.size();i++){
                    ans+=abs(odd[i]-start);
                    start+=2;
                }   
                cout<<ans<<endl;
            }
            else{
                int start = 0,ans = 0;
                for(int i = 0;i<odd.size();i++){
                    ans+=abs(odd[i]-start);
                    start+=2;
                }   
                cout<<ans<<endl;
            }
        }
        else{
            if(odd.size()!= n/2)
                cout<<-1<<endl;
            else{
                int start = 0,ans1 = 0,ans2 = 0;
                for(int i = 0;i<odd.size();i++){
                    ans1+=abs(odd[i]-start);
                    start+=2;
                }   
                start = 1;
                for(int i = 0;i<odd.size();i++){
                    ans2+=abs(odd[i]-start);
                    start+=2;
                }   
                cout<<min(ans1,ans2)<<endl;
            }
        }
    }
    return 0;
}  

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
        for(auto &c:nums)cin>>c;
        sort(nums.begin(),nums.end());
        multiset<int> st;
        for(int i = 0;i<n;i++)
            st.insert(nums[i]);
        bool flag = true;
        int ans = 0;
        for(int i= n;i>=1;i--){
            if(st.find(i)!= st.end()){
                st.erase(st.find(i));
            }
            else{
                if(st.lower_bound((i*2)+1)==st.end()){
                    flag = false;
                    break;
                }
                else{
                    ans++;
                    st.erase(st.lower_bound((i*2)+1));
                }
            }
        }
        if(!flag)cout<<-1<<endl;
        else cout<<ans<<endl;
    }
    return 0;
}  


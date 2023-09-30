#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){
	int t= 1,n;
    while(t--){
        cin>>n;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        set<int> st;
        vector<int> o[n+1];
        for(int i = 1;i<=n;i++)
            st.insert(i);
        for(int i = 0;i<n;i++)
            o[nums[i]].push_back(i),st.erase(nums[i]);
        
        vector<bool> pos(n);
        vector<int> ans = nums;
        for(int i = 1;i<=n;i++){
            reverse(o[i].begin(),o[i].end());
            if(o[i].size()>1){
                for(auto c:o[i])pos[c] = 1;
            }
        }
        
        int l = 0;
        vector<bool> used(n+1);
        cout<<st.size()<<endl;
        while(st.size()){
            while(pos[l]==0){l++;}
            int mn = *st.begin();
            if(ans[l]>mn){
                ans[l]= mn;
                o[nums[l]].pop_back();
                pos[l] = 0;
                if(!used[nums[l]] && o[nums[l]].size()==1){
                    pos[o[nums[l]][0]] = 0;
                    o[nums[l]].pop_back();
                }                            
                st.erase(st.begin());
            }
            else{
                // cout<<changes<<" "<<ones<<" "<<st.size()<<" "<<mn<<endl;
                if(used[nums[l]]){
                    ans[l] = mn;
                    st.erase(st.begin());
                    o[nums[l]].pop_back();
                    pos[l] = 0;
                }
                else if(o[nums[l]].size()>1){
                    o[nums[l]].pop_back();
                    used[nums[l]]= true;
                    pos[l] = 0;
                }  
                else if(o[nums[l]].size()==1){
                    ans[l] = mn;
                    o[nums[l]].pop_back();
                    pos[l] = 0;
                    st.erase(st.begin());
                }
            }
            // cout<<mn<<endl;
            // for(auto c:pos)cout<<c<<" ";
            // cout<<endl;
            // for(auto c:ans)cout<<c<<" ";
            // cout<<endl;
        }
        for(auto c:ans)cout<<c<<" ";
        cout<<endl;

    }
    return 0;
}  

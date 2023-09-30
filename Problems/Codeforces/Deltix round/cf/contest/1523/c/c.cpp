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
        bool flag = true;
        set<string> st;
        vector<string> ans;
        ans.push_back("1");
        st.insert("1");
        for(int i = 1;i<n;i++){
            bool flag = false;
            for(int j = ans.size()-1;j>=0;j--){
                string nw = ans[j]+"."+to_string(nums[i]);
                if(nums[i]==1 && !st.count(nw)){
                    ans.push_back(nw);
                    st.insert(nw);
                    flag = true;
                    break;
                }
                else{
                    string prev;
                    prev = ans[j]+"."+to_string(nums[i]-1);
                    if(st.count(prev) && !st.count(nw)){
                        ans.push_back(nw);
                        st.insert(nw);
                        flag = true;
                        break;
                    }
                }
            }
            if(!flag){
                string nl = to_string(nums[i]);
                string prevl = to_string(nums[i]-1);
                if(nums[i]>1 && !st.count(nl)  && st.count(prevl)){
                    ans.push_back(nl);
                    st.insert(nl);
                    continue;
                }
            }
        }
        sort(ans.begin(),ans.end());
        for(int i= 0;i<ans.size();i++){
            cout<<ans[i]<<endl;
        }
    }
    return 0;
}  

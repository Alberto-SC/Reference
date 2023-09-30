#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){
	int t= 1,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> nums(2*n);
        for(auto &c:nums)cin>>c;
        vector<pair<int,int>> ans;
        sort(nums.begin(),nums.end());
        int first = 0;
        for(int i = 0;i<(2*n)-1;i++){
            multiset<int> st(nums.begin(),nums.end());
            st.erase(st.find(nums[i]));
            st.erase(st.find(nums.back()));
            ans.resize(1);
            ans[0] ={nums.back(),nums[i]};
            first = nums[i]+nums.back();
            int num = nums.back();
            while(st.size()){
                auto it = st.end();
                int aux = *(--it);
                if(st.find(num-aux)!= st.end() && st.find(num-aux)!= it){
                    st.erase(it);
                    st.erase(st.find(num-aux));
                    ans.push_back({aux,num-aux});
                    num = aux;
                }
                else 
                    break;
            }
            if(ans.size()==n){
                break;
            }
        }
        if(ans.size()== n){
            cout<<"YES"<<endl;
            cout<<first<<endl;
            for(auto c:ans)cout<<c.first<<" "<<c.second<<endl;
        }
        else
            cout<<"NO"<<endl;
    }
    return 0;
}  


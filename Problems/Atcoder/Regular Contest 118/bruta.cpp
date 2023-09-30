#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n;
    while(t--){
        cin>>n;
        vector<int> nums(n);
        nums[0] = 6;
        nums[1] = 15;
        nums[2] = 10;
        set<int> st;
        st.insert(6);
        st.insert(15);
        st.insert(10);
        int idx = 0;
        int base = nums[0]*2;
        for(int i = 3;i<n;i++){
            if(base<=10000){
                while(st.count(base)){
                    base+=nums[idx];
                }
                st.insert(base);
                nums[i] = base;
            }
            else{
                idx++;
                base = nums[idx]*2;
            }
        }
        for(auto c:nums)cout<<c<<" ";
        cout<<endl;
        bool flag = true;
        for(int i = 0;i<n;i++){
            for(int j = i+1;j<n;j++){
                if(nums[i]==nums[j])flag = false;
                if(__gcd(nums[i],nums[j])==1)flag = false;
            }
        }
        int gcd = 0;
        for(int i = 0;i<n;i++)
            gcd = __gcd(nums[i],gcd);
        if(gcd !=1)flag = false;
        assert(flag ==true);
    }
    return 0;
}  

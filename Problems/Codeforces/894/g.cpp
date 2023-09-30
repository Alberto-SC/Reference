#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n;
    cin>>T;
    while(T--){
        cin>>n;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
      

        multiset<int> st; 
        multiset<int> diffs;

        for(int i = 0;i<n;i++){
            st.insert(nums[i]);
        }

        int last = *st.begin();
        for(auto c:st){
            diffs.insert(c-last);
            last = c; 
        }

        int q;
        cin>>q;

        while(q--){
            int idx,x;
            cin>>idx>>x;

            idx--;

            auto it = st.lower_bound(nums[idx]);
            it++;
            if(it != st.end()){
                int diff = *it - nums[idx];
                diffs.erase(diffs.find(diff));
            }
            it--;
            if(it != st.begin()){
                it--;
                int diff = nums[idx] - *it;
                diffs.erase(diffs.find(diff));
                it++;
            }
            if(it != st.begin()){
                auto it2 = it; 
                it2++;
                auto it3 = it;
                it3--;
                if(it2 != st.end()){
                    int diff = *it2 - *it3;
                    diffs.insert(diff);
                }
            }
            st.erase(it);
 

            st.insert(x);
            nums[idx] = x;
            it = st.lower_bound(x);


            it++;
            if(it != st.end()){
                int diff = *it - nums[idx];
                diffs.insert(diff);
            }
            it--;
            if(it != st.begin()){
                it--;
                int diff = nums[idx] - *it;
                diffs.insert(diff);
                it++;
            }
            if(it != st.begin()){
                auto it2 = it; 
                it2++;
                auto it3 = it;
                it3--;
                if(it2 != st.end()){
                    int diff = *it2 - *it3;
                    diffs.erase(diffs.find(diff));
                }
            }



            int mx = *st.rbegin();
            int mxDiff = *diffs.rbegin();
            cout<<mx+mxDiff<<" ";
        }
        cout<<endl;

    }
    return 0;
}
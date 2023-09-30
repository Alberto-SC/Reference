#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){
	lli t= 1,n,w;
    cin>>t;
    while(t--){
        cin>>n>>w;
        vector<int> nums(n);
        lli sum = 0;
        for(auto &c:nums)cin>>c,sum+=c;
        lli l = (w/2)+(w%2);
        // cout<<sum<<" "<<l<<endl;
        if(*min_element(nums.begin(),nums.end())>w || sum<l)cout<<-1<<endl;
        else{
            vector<pair<int,int>> s(n);
            set<int> st;
            for(int i = 0;i<n;i++)
                s[i] = {nums[i],i},st.insert(i);
            sort(s.begin(),s.end());
            int r = n-1;
            while(sum>w && r>=0){
                // cout<<sum<<" "<<s[r].first<<endl;
                if(sum-s[r].first>w)
                    sum-=s[r].first,st.erase(s[r].second);
                else if(sum-s[r].first>=l){
                    st.erase(s[r].second);
                    sum-=s[r].first;
                    break;
                }
                r--;
            }
            if(sum>w || sum<l)cout<<-1<<endl;
            else{
                cout<<st.size()<<endl;
                for(auto c:st)cout<<c+1<<" ";
                cout<<endl;
            }
            
        }
    }

    return 0;
}  


#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
	lli t= 1,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<lli> nums(2*n);
        for(auto &c:nums)cin>>c;
        map<lli,lli> mp;
        for(lli i = 0;i<2*n;i++){
            mp[nums[i]]++;
        }
        bool flag = true;
        vector<lli> a;
        for(auto c:mp){
            if(c.second!=2)flag = false;
            if(c.first&1 )flag = false;
            a.push_back(c.first);
        }
        if(!flag)
            cout<<"NO"<<endl;
        else{
            vector<lli> ans;
            reverse(a.begin(),a.end());
            lli cont = n;
            lli sum = 0;
            for(lli i = 0;i<n;i++){
                // cout<<a[i]-sum<<endl;
                if(a[i]-sum<=0|| (a[i]-sum)&1){
                    flag = false;
                    break;
                }
                if((a[i]-sum)%cont){
                    flag = false; 
                    break;
                }
                ans.push_back((a[i]-sum)/(cont*2));
                sum+= (a[i]-sum)/cont;
                cont--;
            }
            if(ans.size()==n){
                for(int i = 0;i<n;i++){
                    ans.push_back(-ans[i]);
                }
                set<lli> st(ans.begin(),ans.end());
                if(st.size()!=2*n)flag = false;
                // for(auto c:ans)cout<<c<<" ";
                // cout<<endl;
                // vector<lli> b(2*n);
                // for(int i = 0;i<2*n;i++){
                //     for(int j = 0;j<2*n;j++){
                //         b[i] += abs(ans[i]-ans[j]);
                //     }
                // }
                // for(auto c:b)cout<<c<<" ";
                // cout<<endl;
            }
            if(flag){
                cout<<"YES"<<endl;
            }
            else cout<<"NO"<<endl;
        }
    }
    return 0;
}  


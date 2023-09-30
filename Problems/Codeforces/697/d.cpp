#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
signed main(){__
	int t= 1,n,m;
    cin>>t;
    while(t--){
        cin>>n>>m;
        vector<int> nums(n);
        vector<int> a(n);
        vector<int> a1;
        vector<int> a2;
        for(auto &c:nums)cin>>c;
        for(auto &c:a)cin>>c;
        for(int i = 0;i<n;i++){
            if(a[i]==1)
                a1.push_back(nums[i]);
            else 
                a2.push_back(nums[i]);
        }
        sort(a1.rbegin(),a1.rend());
        sort(a2.rbegin(),a2.rend());
        vector<int> ac2;
        for(int i = 0;i<a2.size();i++){
            if(i == 0)  
                ac2.push_back(a2[i]);
            else ac2.push_back(a2[i]+ac2.back());
        }
        int mn =(n+7)*2;
        int sum = 0;
        for(int i = 0;i<=a1.size();i++){
            if(i)
                sum+=a1[i-1];
            if(sum>=m)
                mn = min(mn,i);
            else {
                if(ac2.size()==0)continue;
                int idx = lower_bound(ac2.begin(),ac2.end(),m-sum)-ac2.begin();
                if(idx ==ac2.size())idx--;
                if(sum+ ac2[idx]<m)continue;
                else{
                    mn = min(mn,i+((idx+1)*2));
                }
            }
        }
        if(mn == (n+7)*2)cout<<-1<<endl;
        else 
            cout<<mn<<endl;
    }
    return 0;
}  


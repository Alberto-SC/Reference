#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n,m,c,s;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        vector<int> diff(n-1);
        c = -1,m = -1;
        int c2 = -1;
        for(int i = 1;i<n;i++){
            diff[i-1]= abs(nums[i]-nums[i-1]);
            if(nums[i]>nums[i-1])c = diff[i-1];
            else 
                c2 = diff[i-1];
        }
        if(n<=2){cout<<0<<endl;continue;};
        vector<int> u;
        u = diff;
        sort(u.begin(),u.end());
        u.erase(unique(u.begin(),u.end() ),u.end());
        // cout<<u.size()<<" "<<c<<" "<<c2<<endl;
        if(u.size()>2){cout<<-1<<endl;continue;}
        if(u.size()==1 &&(c2==-1|| c==-1)){cout<<0<<endl;continue;}
        if(u.size()==2 &&c2==-1){cout<<-1<<endl;continue;}
        m = c+c2;
        bool flag = true;
        if(nums[0]>=m)flag = false;
        for(int i = 1;i<n;i++)
            if(nums[i]!= (nums[i-1]+c)%m)flag = false;
        if(flag)cout<<m<<" "<<c<<endl;
        else cout<<-1<<endl;
    }
    return 0;
}  

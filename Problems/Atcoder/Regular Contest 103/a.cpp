#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
	int t= 1,n;
    while(t--){
        cin>>n;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        vector<int> even(100007);
        vector<int> odd(100007);
        for(int i = 0;i<n;i++){
            if(i%2 ==0)odd[nums[i]]++;
            else even[nums[i]]++;
        }
        int mx = 0,mxn = 0; 
        for(int i = 1;i<=100000;i++){
            if(odd[i]>mx)
                mx = odd[i],mxn =i;
        }
        int mx2 = 0,mxn2 = 0;
        for(int i = 1;i<=100000;i++){
            if(even[i]>mx2)
                mx2 = even[i],mxn2 =i;
        }
        int sz = n/2;
        int ans1 = 0,ans2 = 0;
        if(mxn != mxn2)
            cout<<(sz-mx)+(sz-mx2);
        
        else{
            int ans1 = 0,ans2 = 0;
            ans1 = sz-mx;
            even[mxn2] = 0;
            int mx22 = 0;
            for(int i = 1;i<=100000;i++)
                mx22 = max(even[i],mx22);
            ans1+=sz-mx22;

            ans2 = sz-mx2;
            odd[mxn] = 0;
            int mx12 = 0;
            for(int i = 1;i<=100000;i++)
                mx12 = max(odd[i],mx12);
            ans2+= sz-mx12;
            cout<<min(ans1,ans2)<<endl;
        }
    }
    return 0;
}  


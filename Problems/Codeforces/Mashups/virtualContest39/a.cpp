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
        map<int,int> mp1;
        map<int,int> mp2;
        for(int i = 0;i<n;i++)
            cin>>nums[i],mp1[nums[i]]++;
        for(int i = 0;i<n-1;i++)
            cin>>nums[i];
        for(int i = 0;i<n-2;i++)
            cin>>nums[i],mp2[nums[i]]++;

        for(auto c:mp1){
            if(c.second!= mp2[c.first]){
                cout<<c.first<<endl;
                if(c.second-2==mp2[c.first])
                    cout<<c.first<<endl;
            }
        }
    }
    return 0;
}  

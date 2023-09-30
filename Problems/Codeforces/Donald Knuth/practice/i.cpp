#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n,k;
    cin>>t;
    while(t--){
        cin>>n>>k;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        int cont = 0;
        for(int i = 0;i<n;i++){
            if(nums[i]== i+1)continue;
            while(nums[i]!=i+1){
                swap(nums[i],nums[nums[i]-1]);
                cont++;
            }
        }
        if(cont>k)cout<<"No"<<endl;
        else cout<<(((k-cont)%2==0)?"Yes":"No")<<endl;
    }
    return 0;
}  

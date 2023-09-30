#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n,id = 1;
	cin>>t;
    while(t--){
        cin>>n;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        int cont = 0;
        for(int i = 0;i<n-1;i++){
            int mn =n+1,idx;
            for(int j = i;j<n;j++){
                if(nums[j]<mn){
                    idx = j;
                    mn = nums[j];
                }
            }
            reverse(nums.begin()+i,nums.begin()+idx+1);
            cont+= (idx-i)+1;
        }
        cout<<"Case #"<<id<<": "<<cont<<endl;
        id++;
    }
    return 0;
}  

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n;
    cin>>n;
    vector<int> nums(n);
    iota(nums.begin(),nums.end(),1);
    int cont = 0;
    vector<int> count(n+1);
    do{
        bool flag = true;
        for(int i = 0;i<n;i++){
            if(nums[i]%nums[(i+1)%n]>2)flag = false;
        }
        if(flag){
            for(auto c:nums)cout<<c<<" ";
            cout<<endl;
            cont++;        
            count[nums[0]]++;
        }
    }while(next_permutation(nums.begin(),nums.end()));
    cout<<cont<<endl;
    for(auto c:count)cout<<c<<" ";
    cout<<endl;
    return 0;
}  



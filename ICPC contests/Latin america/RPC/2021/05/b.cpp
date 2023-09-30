#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

bool is_triangle(int a,int b,int c){
    if (a+b<=c)
        return false;
    else
        return true;   
}

struct triangle{
    int a,b,c;
};

int binomial_Coeff(int n, int k){ 
    vector<int> C(k+1,0); 
    C[0] = 1;   
    for (int i = 1; i <= n; i++) { 
        for (int j = min(i, k); j > 0; j--) 
            C[j] = C[j] + C[j-1]; 
    } 
    return C[k]; 
} 
signed main(){__
	int t= 1,n;
    while(t--){
        cin>>n;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        sort(nums.begin(),nums.end());
        int ans = 0;
        for(int i = 0;i<n;i++){
            for(int j= i+1;j<n;j++){
                int cont = 0;
                for(int k =0;k<n;k++){
                    if(nums[k]>nums[j]&& nums[k]<nums[i]+nums[j])cont++;
                }
                for(int k = 1;k<=cont;k++){
                    ans+=binomial_Coeff(cont,k);
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}  

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
    lli t,n,m;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        sort(nums.begin(),nums.end());
        int i;
        bool flag = true;
        vector<int> aux(n);
        for(i = 1;i<=1023;i++){
            flag = true;
            for(int j = 0;j<n;j++){
                aux[j]= nums[j]^i;                
            }   
            sort(aux.begin(),aux.end());
            for(int j = 0;j<n;j++)
                if(nums[j]!= aux[j])flag = false;
            if(flag)break;
        }
        if(flag)cout<<i<<endl;
        else cout<<-1<<endl;
    }
    return 0;
}
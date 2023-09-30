#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

signed main(){__
    int t = 1,n,k;
    cin>>t;
    while(t--){ 
        cin>>n;
        vector<int> nums(n);
        iota(nums.begin(),nums.end(),1);
        int cont = 0;
        do{
            vector<int> copy = nums;
            reverse(copy.begin(),copy.end());
            bool flag = true;
            for(int i = 2;i<n;i++){
                if(copy[i]== copy[i-1]+copy[i-2])flag = false;
            }
            if(flag){
                for(auto c:copy)cout<<c<<" ";
                cout<<endl;
                cont++;
            }
            if(cont==n)break;
        }while(next_permutation(nums.begin(),nums.end()));
    }   
    return 0;
}
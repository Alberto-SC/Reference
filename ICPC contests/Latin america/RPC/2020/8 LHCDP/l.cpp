#define _GLIBCXX_DEBUG 1
#define _GLIBCXX_DEBUG_PEDANTIC 1
#define _FORTIFY_SOURCE 2
#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
    lli t,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<bool> nums(32,false);
        int num = 0;
        // bitset<32> bits(n);
        for(int i = 0;i<5;i++)
            num|= ((n>>i)&1)<<i;
        nums[num]= true;
        for(int i = 5;i<37;i++){
            num>>=1;
            num|= ((n>>(i%32))&1)<<4;
            // cout<<i<<" "<<num<<endl;
            nums[num] =true;
        }
        bool flag = true;
        for(int i = 0;i<32;i++){
            if(!nums[i])flag = false;
        }
        if(flag)cout<<"yes"<<endl;
        else cout<<"no"<<endl;
        // cout<<num<<endl;
        // cout<<bits<<endl;
    }
    return 0;
}
#include <bits/stdc++.h>
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

using namespace std;

signed main(){__
    int T,n;
    cin>>T;
    while(T--){
        cin>>n;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
 
        sort(nums.rbegin(),nums.rend());
        int a = nums[0],b = nums[1];

        bool flag = true;

        for(int i = 0;i<(n/2)-1;i++){
           if((a-b)<=b){   
                int temp = a-b;
                a = b;
                b = temp;
           }
           else{
                flag = false;
                break; 
           }
        }
        vector<int> v;
        v.push_back(a);
        v.push_back(b);
        int ansa = a,ansb = b;
        for(int i = 0;i<(n/2)-1;i++){
            int nmx = a+b;
            if(nmx>nums[0]){
                flag = false;
                break;
            }
            v.push_back(nmx);
            v.push_back(a-b);
            b = a;
            a = nmx;
        }
        
        sort(v.rbegin(),v.rend());
        if(v!= nums)flag = false;
        if(!flag)cout<<"NO"<<endl;
        else cout<<"YES"<<endl<<ansa<<" "<<ansb<<endl; 
        
    
    }
    return 0;
}

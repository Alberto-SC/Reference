#define _GLIBCXX_DEBUG 1
#define _GLIBCXX_DEBUG_PEDANTIC 1
#define _FORTIFY_SOURCE 2
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
    int t,n,x;
    cin>>t;
    while(t--){
        cin>>n>>x;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        int im =0,par = 0;
        for(int i = 0;i<n;i++){
            if(nums[i]&1) im++;
            else par++;
        }
        if(im == 0){cout<<"No"<<endl;continue;}
        if(x<=im  && x%2 == 0 && par == 0)cout<<"No"<<endl;
        else if(im&1)cout<<"Yes"<<endl;
        else if(x == n && im%2 == 0)cout<<"No"<<endl;
        else cout<<"Yes"<<endl;
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

int main(){__
    int t = 1,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        bool turn = false;
        for(int i = 0;i<n-1;i++){
            if(nums[i]>1)break;
            else turn = !turn;
        }
        if(!turn)cout<<"First"<<endl;
        else cout<<"Second"<<endl;
    }
    return 0;
} 
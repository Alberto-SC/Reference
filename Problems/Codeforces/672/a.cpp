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
        vector<int> copy(n);
        vector<int> copy2(n);
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        copy = nums;
        copy2 = nums;
        sort(copy.rbegin(),copy.rend());
        sort(copy2.begin(),copy2.end());
        if(nums == copy2)cout<<"YES"<<endl;
        else if(copy == nums){
            bool flag = true;
            for(int i = 1;i<n;i++){
                if(copy[i] == copy[i-1])flag = false;
            }
            if(flag)
                cout<<"NO"<<endl;
            else 
                cout<<"YES"<<endl;
        }
        else cout<<"YES"<<endl;
    }
    return 0;
}


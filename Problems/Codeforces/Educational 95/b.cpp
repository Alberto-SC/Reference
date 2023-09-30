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
        vector<int> lock(n);
        vector<int> a;
        for(auto &c:nums)cin>>c;
        for(int i = 0;i<n;i++){
            cin>>lock[i];
            if(!lock[i])
                a.push_back(nums[i]);
        }
        sort(a.rbegin(),a.rend());
        for(int i = 0,j = 0;i<n;i++){
            if(!lock[i])
                nums[i] = a[j++];
        }
        for(auto c:nums)cout<<c<<" ";
        cout<<endl;

    }
    return 0;
}


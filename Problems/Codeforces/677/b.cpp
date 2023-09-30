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
        int last = 0,first;
        for(int i = 0;i<n;i++)
            if(nums[i]== 1)last = i;

        for(int i = n-1;i>=0;i--)
            if(nums[i] == 1)first = i;

        int zeros = 0;
        for(int i = first;i<last;i++)
            if(nums[i]== 0)zeros++;
        cout<<zeros<<endl;

    }
    return 0;
}


#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);  
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        vector<int> b(n+1,0);
        for(int i = 0;i<n;i++)
            b[nums[i]]++;
        int same =0,who = 0;
        for(int i = 0;i<n+1;i++)
            if(b[i]>same)same =b[i],who= i;
        int uniques = 0;
        b[who] = 0;
        for(int i = 0;i<n+1;i++)
            if(b[i]>0)uniques++;
        int ans = max(min(uniques,same),min(uniques+1,same-1));
        cout<<ans<<endl;

    }
    return 0;
}
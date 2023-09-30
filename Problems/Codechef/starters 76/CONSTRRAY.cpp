#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n;
    cin>>T;
    while(T--){
        cin>>n;
        if(n&1){
            cout<<-1<<endl;
            continue;
        }
        vector<int> nums(n);
        int l = 0,r = n-1;
        int CR = 2*n,CL = (2*n)-1,turn = 0;
        while(l<r){
            if(!turn){
                nums[l] = CR;
                nums[r] = CL;
            }
            else{
                nums[l] = CL;
                nums[r] = CR;
            }
            turn ^=1;
            l++;
            r--;
            CR++;
            CL--;
        }
        for(auto c:nums)cout<<c<<" ";
        cout<<endl;
        vector<int> p(n);
        vector<int> s(n);
        p[0] = nums[0];
        for(int i = 1;i<n;i++)
            p[i] = nums[i]+p[i-1];

        s[n-1] = nums[n-1];
        for(int i= n-2;i>=0;i--)
            s[i] = nums[i]+s[i+1];
        
        // reverse(s.begin(),s.end());

        // for(int i = 0;i<n;i++){
        //     cout<<(p[i]>s[i])<<" ";
        // }
        // cout<<endl;
    }
    return 0;
}
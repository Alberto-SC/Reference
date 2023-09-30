#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n,k;
    cin>>T;
    while(T--){
        cin>>n>>k;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;

        int last1 = -1,last2 = -1;
        int cont1 = 0,cont2 = 0;
        for(int i = 0;i<n;i++){
            if(nums[i]== nums[0])cont1++;
            if(cont1 == k){
                last1 = i;
                break;
            }
        }

        for(int i = n-1;i>=0;i--){
            if(nums[i]== nums[n-1])cont2++;
            if(cont2 == k){
                last2 = i;
                break;
            }
        }

        if(last1 == -1 || last2 == -1)cout<<"NO"<<endl;
        else if(last1<last2 || nums[0] == nums[n-1])cout<<"YES"<<endl;
        else cout<<"NO"<<endl;

    }
    return 0;
}
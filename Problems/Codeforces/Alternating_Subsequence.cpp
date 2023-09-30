#include <bits/stdc++.h>
using namespace std;
const int inf = -1000000007;
typedef long long int lli;
int main(){
    int t,n;
    cin>>t;
    while(t--){
        cin >> n;
        lli ans = 0;   
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        int j ;
        int ant = nums[0];
        for(int i = 0;i<n;i=j){
            j = i;
            int mx = nums[i];
            while(j<n&& ant<0 == nums[j]<0){
                mx = max(mx,nums[j]);
                j++;
            }
            ans+=mx;
            ant = nums[j];
        }
        cout << ans << endl;
        ans = 0;
    }
    return 0;
}
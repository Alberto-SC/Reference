#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);


int main(){
    int n;
    cin>>n;
    vector<lli> nums(n);
    lli ans = 0;
    for(auto &c:nums)cin>>c;
    vector<int> b(23);
    for(int i = 0;i<n;i++){
        for(int j = 0;j<20;j++){
            if((nums[i]>>j) &1)b[j]++;
        }
    }
    for(int i = 0;i<n;i++){
        lli x = 0;
        for(int j = 0;j<20;j++){
            if(b[j]){
                x |= 1<<j;
                b[j]--;
            }
        }
        ans+= x*x;
    }
    cout<<ans<<endl;

    return 0;
}
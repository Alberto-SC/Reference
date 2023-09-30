#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define x first
#define y second
int main(){
    int n;
    cin>>n;
    vector<lli> nums(n);
    for(auto &c:nums)cin>>c;
    vector<pair<lli,lli>> prizes(5);
    for(int i = 0;i<5;i++)cin>>prizes[i].x,prizes[i].y = i;
    sort(prizes.begin(),prizes.end());
    lli z = 0;
    vector<lli> ans(5);
    for(int i = 0;i<n;i++){
        z+=nums[i];
        for(int i = 4;i>=0;i--){
            if(z>=prizes[i].x){
                ans[prizes[i].y]+=z/prizes[i].x;
                z-=(z/prizes[i].x)*prizes[i].x;
            }
        }
    }
    for(auto c:ans)cout<<c<<" ";
    cout<<endl;
    cout<<z<<endl;
    return 0;
}
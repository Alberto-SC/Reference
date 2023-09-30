#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
	int t= 1,n;
    cin>>n;
    vector<int> nums(n);
    for(auto &c:nums)cin>>c;
    int mx = 0;
    int idx = 0;
    for(int i = 0;i<(1<<n);i++){
        vector<int> a1;
        vector<int> a2;
        for(int j = 0;j<n;j++){
            if((i>>j)&1)
                a1.push_back(nums[j]);
            else 
                a2.push_back(nums[j]);
        }
        int ans = 0;
        for(int j = 0;j<a1.size();){
            int k = j;
            while(k<a1.size() && a1[j]== a1[k]){
                k++;
            }
            ans++;
            j = k;
        }
        for(int j = 0;j<a2.size();){
            int k = j;
            while(k<a2.size() && a2[j]== a2[k]){
                k++;
            }
            ans++;
            j = k;
        }
        if(ans>mx){
            idx = i;
            mx = max(ans,mx);
        }
    }
    // for(int j = 0;j<n;j++){
    //     if((idx>>j)&1)
    //         cout<<1<<" ";
    //     else 
    //         cout<<0<<" ";
    // }
    // cout<<endl;
    // cout<<idx<<endl;
    cout<<mx<<endl;
    return 0;
}  


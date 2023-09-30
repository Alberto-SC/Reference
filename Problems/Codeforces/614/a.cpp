#include <bits/stdc++.h>
using namespace std;

int main(){
    int t,n,s,k;
    cin>>t;
    while(t--){
        cin>>n>>s>>k;
        vector<int> nums(k);
        for(auto &c:nums)cin>>c;
        for (int i=0; i<=k; i++) {
		    if (s-i >= 1 && find(nums.begin(), nums.end(), s-i) == nums.end()) {cout << i << endl; break;}
		    if (s+i <= n && find(nums.begin(), nums.end(), s+i) == nums.end()) {cout << i << endl; break;}
        }
    }
    return 0;
}
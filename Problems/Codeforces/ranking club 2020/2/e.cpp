#include <bits/stdc++.h>
using namespace std; 
const int inf = 1<<30;
int main() {
    int n;
    cin>>n;
    vector<int> nums(n);
    for(auto &c:nums)cin>>c;
	int cont=1;
    int ans = -inf;
	for(int i=1;i<n;i++)
        if(nums[i]>=nums[i-1])
            cont++;
        else ans=max(ans,cont),cont=1;
	ans=max(ans,cont);
    cout<<ans<<endl;
	return 0;
}
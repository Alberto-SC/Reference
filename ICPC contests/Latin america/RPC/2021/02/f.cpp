#include <bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
int main(){__
    int n;
    cin>>n;
    vector<int> nums(n);
    vector<int> p(n);
    for(auto &c:nums)cin>>c;
    for(int i=0; i<n; i++) 
        p[i] = i+1;
    int curr = 0;
    while (n > 1) {
        int next = (curr + nums[curr] - 1)%n;
        for(int i=next+1; i<n; i++) 
            nums[i-1] = nums[i],p[i-1] = p[i];
        
        n--;
        curr = next%n;
    }
    cout<<p[0]<<endl;
}
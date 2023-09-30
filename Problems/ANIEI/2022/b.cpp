#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'


signed main(){
    int n,b;
    while(cin>>n>>b){
        if(n == 0&& b ==0)break;
        vector<int> nums(n);
        int sum = 0;
        for(auto &c:nums)cin>>c,sum+=c;
        cout<<b/sum<<endl;
    }
    return 0;
}

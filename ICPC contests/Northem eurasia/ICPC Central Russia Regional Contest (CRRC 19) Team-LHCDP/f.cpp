#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

map<pair<string,int>,int>> DP;

int DP(string s,int turn){
    if(s== ""){
        return !turn;
    }
    if(DP.count{s,turn})return DP[{s,turn}];
}

int main(){__
	int t= 1,n;
    while(t--){
        cin>>n;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
    }
    return 0;
}  


#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

int solve(vector<int> &A,int b){
    if(b<0)return 0;
    vector<int> l,r;
    for(int i = 0;i<A.size();i++){
        if((A[i]>>b) &1)l.push_back(A[i]);
        else r.push_back(A[i]);
    }
    if(l.size()== 0)
        return solve(r,b-1);
    if(r.size() == 0)
        return solve(l,b-1);
    return min(solve(l,b-1),solve(r,b-1))+ (1<<b);
}


int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(auto &c:nums)cin>>c;
    cout<<solve(nums,30)<<endl;
    return 0;
}

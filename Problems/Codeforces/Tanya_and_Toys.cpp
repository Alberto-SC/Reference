#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<int> nums(n);
    vector<int> ans;
    vector<bool> b(1000007);
    for(auto &c:nums)cin>>c,c<=1000000?b[c]=true:b[0] = false;
    int cont = 0;
    for(int i = 1;i<=1000000;i++){
        if(b[i])continue;
        else if(m-i>=0)cont++,m-=i,ans.push_back(i);
        else break;
    }
    cout<<cont<<endl;
    for(auto c:ans)cout<<c<<" ";
    cout<<endl;
    return 0;
}
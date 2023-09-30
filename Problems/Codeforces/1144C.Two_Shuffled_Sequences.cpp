#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    vector<int> bk(200007);
    for(auto &c:nums)cin>>c,bk[c]++;
    vector<int> a;
    vector<int> b;
    bool flag = true;
    for(int i = 0;i<200007;i++){
        if(bk[i]>2)flag = false;
        else if(bk[i] == 2)a.push_back(i),b.push_back(i);
        else if(bk[i] == 1)a.push_back(i);
    }
    sort(a.begin(),a.end());
    sort(b.rbegin(),b.rend());
    if(!flag)return cout<<"NO"<<endl,0;
    cout<<"YES"<<endl;
    cout<<a.size()<<endl;
    for(auto c:a)cout<<c<<" ";
    cout<<endl;
    cout<<b.size()<<endl;
    for(auto c:b)cout<<c<<" ";
    cout<<endl;
    return 0;
}

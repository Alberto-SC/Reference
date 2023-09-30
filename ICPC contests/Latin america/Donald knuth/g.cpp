#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
bool comp(string s,string t){
    if(s[0]== t[0]){
        int i;
        if(s.size()==1)return 1;
        else if(t.size()==1)return 0;
        for(i = 0;i<s.size()&& i<t.size();i++){
            if(s[i]!= t[i])break;
        }
        if(i== s.size())return 1;
        else if(i == t.size())return 0; 
        return s[i]>t[i];
    }
    return s[0]>t[0];
}
int main(){
    int n;
    cin>>n;
    vector<string> nums(n);
    for(auto &c:nums)cin>>c;
    bool flag = false;
    for(int i = 0;i<n;i++){
        if(nums[i].size()>1)flag = true;
        sort(nums[i].rbegin(),nums[i].rend());
    }
    for(auto c:nums)cout<<c<<endl;
    cout<<endl;
    if(!flag){
        sort(nums.rbegin(),nums.rend());
        for(auto c:nums)cout<<c;
        cout<<endl;
    }
    else{
        sort(nums.begin(),nums.end(),comp);
        // for(auto c:nums)cout<<c<<" ";
        // cout<<endl;
        for(int i = 0;i<n;i++)
            cout<<nums[i];
        cout<<endl;
    }
    return 0;
}
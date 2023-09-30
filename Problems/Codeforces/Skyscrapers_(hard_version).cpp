#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define print(A) for(auto c:A)cout<<c<<" ";cout<<endl;
#define x first 
#define y second
int main(){
    lli n;
    cin>>n;
    vector<lli> nums(n);
    for(auto &c:nums)cin>>c;
    vector<lli> l(n);
    vector<lli> r(n);
    stack<pair<lli,lli>> s;
    lli mn = 1000000007;
    for(lli i = 0;i<n;i++){
        if(nums[i]<mn){
            mn = nums[i];
            s.push({nums[i],i});
            l[i] = (i+1)*nums[i];
        }
        else{
            while(!s.empty() && s.top().x>nums[i]){s.pop();}
            l[i] = l[s.top().y]+((i-s.top().y)*nums[i]);
            s.push({nums[i],i});
        }
    }
    mn = 1000000007;
    vector<lli> copy = nums;
    stack<pair<lli,lli>> t;
    reverse(copy.begin(),copy.end());
    for(lli i = 0;i<n;i++){
        if(copy[i]<mn){
            mn = copy[i];
            t.push({copy[i],i});
            r[i] = (i+1)*copy[i];
        }
        else{
            while(!t.empty() && t.top().x>copy[i]){t.pop();}
            r[i] = r[t.top().y]+((i-t.top().y)*copy[i]);
            t.push({copy[i],i});
        }
    }
    lli peak,mx = -1;
    reverse(r.begin(),r.end());
    for(lli i = 0;i<n;i++){
        if(l[i]+r[i]-nums[i]>mx){
            mx = l[i]+r[i]-nums[i];
            peak = i;
        }
    }
    mn = nums[peak];
    for(lli i = peak-1;i>=0;i--)nums[i]>mn?nums[i] = mn:mn = min(mn,nums[i]);
    mn = nums[peak];
    for(lli i = peak+1;i<n;i++)nums[i]>mn?nums[i] = mn:mn = min(mn,nums[i]);
    print(nums);
    return 0;   
}
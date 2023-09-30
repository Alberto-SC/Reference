#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main(){
    string s;
    vector<lli> nums;
    lli x;
    while(cin>>x){
        nums.push_back(x);
    }
    x = 144381670;
    // x = 127;
    vector<lli> pref;
    pref.push_back(0);
    map<lli,lli> mp;
    lli mn = x+1;
    lli mx = 0;
    for(int i= 0;i<nums.size();i++){
        pref.push_back(nums[i]+pref.back());
        cout<<pref.back()<<endl;
        mp[pref.back()] = i;
        if(mp.count(pref.back()-x)){
            int idx = mp[pref.back()-x];
            cout<<"IDX: "<<idx<<endl;
            for(int j = idx;j<=i;j++)
                mn = min(mn,nums[j]),mx = max(mx,nums[j]);
            break;
        }
    }
    cout<<mn+mx<<" "<<mx<<endl;
    return 0;
}
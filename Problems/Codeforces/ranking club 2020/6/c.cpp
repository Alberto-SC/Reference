#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main(){
    lli n;
    cin>>n;
    vector<string> s(n);
    for(lli i = 0;i<n;i++)
        cin>>s[i];
    map<lli,lli> m;
    vector<lli> nums(n);
    for(lli i = 0;i<n;i++){
        bitset<27> mask;
        for(lli j = 0;j<(lli)s[i].size();j++)
            mask[s[i][j]-'a'] = !mask[s[i][j]-'a'];
        // cout<<mask<<endl;
        lli num = (lli)(mask.to_ulong());
        if(m.find(num)==m.end())m[num] = 1;
        else m[num]++;
        nums[i] = num;
    }
    lli ans = 0;
    for(auto c:m){
        lli num = c.first;
        ans += c.second * (c.second - 1);
        for (lli i = 27; i >=0; i--) {
            lli newn = (num ^ (1 << i));
            if (!m.count(newn)) 
                continue;
            ans += c.second * m[newn];
        }
    }
    cout<<ans/2<<endl;
    return 0;
}
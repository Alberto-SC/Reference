#include <bits/stdc++.h>
using namespace std;

#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
int main(){__
    int n;
    cin>>n;
    int sum = 0;
    int s = 1000000;
    vector<int> nums(n);
    vector<int> b(s+7);
    vector<bool> sett(s+7,false);
    for(int i = 0;i<n;i++){
        int x;
        cin>>x;
        nums[i] = x;
        sum+=x-1;
        b[x]++; 
    }
    int l = 1,r = s;
    vector<int> ans;
    for(int i = 0;i<n;i++){
        int c = s-(nums[i]-1);
        if(sett[nums[i]])continue;
        if(b[c]){
            while(b[l]||b[r]){
                l++,r--;
            }
            if(l)
            ans.push_back(l);
            ans.push_back(r);
            b[l] = 1;
            b[r] = 1;
            sett[nums[i]] = true;
            sett[c] = true;
        }
        else { 
            sett[nums[i]] = true;
            b[c] = 1;
            ans.push_back(c);
        }

    }
    int sum2 = 0;
    cout<<ans.size()<<endl;
    for(auto c:ans)cout<<c<<" ",sum2+=s-c;
    cout<<endl;
    // cout<<sum<<" "<<sum2<<endl;
    return 0;
}
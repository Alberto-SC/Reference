#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

signed main(){__
    int t,n,k;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> nums(n);
        int s = 0;
        for(auto &c:nums)cin>>c,s+=c; 
        vector<int> divs;
        for(int i = 1;i*i<=abs(s);i++){
            if(s%i == 0){
                if(i<=n)
                    divs.push_back(i);
                if((s/i)!=i && (s/i)<=n && s>0)divs.push_back(s/i);
            }
        }
        if(s== 0)divs.push_back(0);
        sort(divs.rbegin(),divs.rend());
        cout<<s<<endl;<  
        for(int i = 0;i<divs.size();i++){
            int target;
            if(divs[i]== 0)
                target = 0;
            else target = s/divs[i];
            cout<<target<<endl;
            int x = 0,cont = 0;
            for(int j = 0;j<n;j++){
                x+=nums[j];
                if(x ==target)
                    x=0,cont++;
            }
            if(divs[0]== 0){
                cout<<n-cont<<endl;
                break;
            }
            else if(cont ==divs[i]){
                cout<<n-divs[i]<<endl;
                break;
            }
        }
    }
    return 0;
}
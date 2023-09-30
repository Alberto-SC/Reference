#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n;
    while(t--){
        cin>>n;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        vector<int> pref(n);

        for(int i = 0;i<n;i++)
            pref[i] = nums[i]+(i?pref[i-1]:0);
        int x = pref[n-1];
        if(x%3){
            cout<<0<<endl;
            continue;
        }

        int y = (x/3)*2;
        int k = x/3;
        vector<int> b;
        for(int i = 1;i<n-1;i++)
            if(pref[i]==y)b.push_back(i);
        
        int cont = 0;
        for(int i = 0;i<n-1;i++){
            if(pref[i]== k){
                int idx = upper_bound(b.begin(),b.end(),i)-b.begin();
                cont+=b.size()-idx;
            }
        }
        cout<<cont<<endl;
    }
    return 0;
}  

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> nums(n);
        int x = 0;
        for(auto &c:nums)cin>>c,x^=c;
        int y = 0;
        bool flag = false;
        for(int i = 0;i<n;i++){
            y^=nums[i];
            if((x^y) ==y)flag = true;
        }
        int pref = 0;
        for(int i = 0;i<n;i++){
            bool f = true;
            pref^=nums[i];
            int cont = 1;
            for(int j = i+1;j<n;){
                if(nums[j]== pref){j++;cont++;continue;}
                x = nums[j];
                int k = j+1;
                while(k<n && x!=pref){
                    x^=nums[k];
                    k++;
                }
                j = k;
                if(x==pref)cont++;
                if(x!=pref && x!= 0){
                    f = false;
                    break;
                }
            }
            if(f&& cont>1){
                flag = true;
                break;
            }
        }
        if(flag)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}  



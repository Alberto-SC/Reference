#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n,w;
    cin>>t;
    while(t--){
        cin>>n>>w;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        vector<int> p2(31);
        for(int i = 0;i<n;i++){
            for(int j = 30;j>=0;j--)
                if((nums[i]>>j)&1)
                    p2[j]++;
        }
        int h = 0;
        // for(auto c:p2)cout<<c<<" ";
        // cout<<endl;
        bool flag = false;
        while(1){
            int num = 0;
            flag = false;
            for(int i = 30;i>=0;i--){
                if(p2[i]==0)continue;
                int cont = 0;
                for(int j = 0;j<p2[i];j++){
                    if(num+(1<<i)<=w)
                        cont++,num+=(1<<i);
                    else 
                        break;
                }
                p2[i]-=cont;
                flag = true;
            }
            if(!flag)break;
            h++;
        }
        cout<<h<<endl;
    }
    return 0;
}  

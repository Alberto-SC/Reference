#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);


signed main(){
    int T = 1,n;
    while(T--){
        cin>>n;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;

        vector<int> badI,badP;
       // for(int i= 0;i<n;i++){
       //     if((nums[i]&1)== (i&1)){
       //         int x = i;
       //         while(i+2<n){
       //             ans.push_back({'B',i});
       //             i+=2;
       //         }
       //         if(i&1)badI.push_back(i);
       //         else badP.push_back(i);
       //     }
       // }
        
        int z = 0;
        int l = 0,r = 0;
        vector<pair<char,int>> ans;
        for(int i = 0;i<(int)badI.size();i++){
            if(badI[l]>badP[r])
                swap(badI[l],badP[r]);

            while((badI[l]+2)<badP[r]){
                ans.push_back({'B',badI[l]});
                swap(nums[badI[l]],nums[badI[l]+2]);
                badI[l]+=2;
            }
            swap(nums[badI[l]],nums[badP[r]]);
            ans.push_back({'A',badI[l]});
            l++,r++;
        }
        // for(auto c:nums)cout<<c<<" ";
        // cout<<endl;
        vector<int> pos(n+1);
        for(int i  = 0;i<n;i++){
            pos[nums[i]] = i;
        }
        int current = n;
        for(int i = n-1;i>=0;i--){
            while(pos[current]!=i){
                ans.push_back({'B',pos[current]});
                int nxt = nums[pos[current]+2];
                int nxtId = pos[current]+2;
                pos[nxt] = pos[current];
                swap(nums[pos[current]],nums[nxtId]);                    
                pos[current]+=2;
            
            }
            current--;
        }
        cout<<ans.size()<<endl;
        for(auto c:ans)
            cout<<c.first<<" "<<c.second+1<<endl;
        
    }
    return 0;
}

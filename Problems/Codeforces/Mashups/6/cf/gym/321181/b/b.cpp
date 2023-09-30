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
        vector<int> pos(n+1);
        for(int i = 0;i<n;i++)
            pos[nums[i]] = i;
        vector<pair<int,int>> moves;
        int l = n/2;
        // for(int i = 1;i<=n/2;i++){
        //     if(pos[i]<n/2){
        //         while(l<n && nums[l]<=n/2){
        //             l++;
        //         }
        //         moves.push_back({pos[i]+1,l+1});
        //         swap(nums[pos[i]],nums[l]);
        //     }
        // }
        for(int i = n/2;i<n;i++)
            pos[nums[i]] = i;
           
        for(int i = 1;i<=n/2;i++){
            if(2*(abs(pos[i]-(i-1)))<n){
                moves.push_back({1,pos[i]+1});
                swap(nums[0],nums[pos[i]]);
                moves.push_back({1,n});
                swap(nums[0],nums[n-1]);
                moves.push_back({i,n});
                swap(nums[i-1],nums[n-1]);
                moves.push_back({1,pos[i]+1});
                swap(nums[0],nums[pos[i]]);
                pos[nums[n-1]] = pos[i];
            }
            else{
                moves.push_back({i,pos[i]+1});
                swap(nums[i-1],nums[pos[i]]);
            }
        }

        for(int i = n/2;i<n;i++)
            pos[nums[i]] = i;

        for(int i = (n/2)+1;i<=n;i++){
            if(pos[i]+1 == i)continue;
            int num = nums[i-1];
            swap(nums[0],nums[pos[i]]);
            moves.push_back({1,pos[i]+1});
            swap(nums[0],nums[i-1]);
            moves.push_back({1,i});
            swap(nums[0],nums[pos[i]]);
            moves.push_back({1,pos[i]+1});
            pos[num] = pos[i];
        }
        for(auto c:nums)cout<<c<<" ";
        cout<<endl;

        cout<<moves.size()<<endl;
        for(auto c:moves)cout<<c.first<<" "<<c.second<<endl;
        cout<<endl;
        
    }
    return 0;
}  

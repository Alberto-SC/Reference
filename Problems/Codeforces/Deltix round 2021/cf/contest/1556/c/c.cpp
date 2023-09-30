#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define x first
#define y second

signed main(){__
	int t= 1,n;
    while(t--){
        cin>>n;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        vector<pair<int,int>> v;
        for(int i = 0;i<n;i+=2){
            if(i+1<n)
                v.push_back({nums[i],nums[i+1]});
        }
        int N = v.size();
        int ans = 0;
        int b =-1; 
        stack<pair<int,int>> last;
        vector<int> dist(N,1);
        for(int i = 0;i<N;i++){
            int diff = v[i].x-v[i].y;
            int lst = -1;
            if(diff>0)
                last.push({diff,i});
            else{
                while(!last.empty() && diff<0){
                    auto tp = last.top();
                    int z = min(tp.x,abs(diff));
                    tp.x-=z;
                    diff+=z;
                    last.pop();
                    if(tp.x>0){
                        ans+=z;
                        last.push(tp);
                    }
                    else{
                        ans+=z;
                        if(tp.y-1>=0 && tp.y-1>b){
                            ans+=dist[tp.y-1];
                        }
                    }
                    lst = tp.y;
                }
            }
            if((v[i].x-v[i].y)<=0){
                if(b!= i-1)
                    ans+=min(v[i].x,v[i].y)+dist[i-1];
                else 
                    ans+=min(v[i].x,v[i].y);
                if(diff<0)
                    b = i;
                else if((v[i].x-v[i].y<0)){
                    if(!last.empty() && last.top().y==lst)
                        dist[i] = 1;
                    else 
                        dist[i] +=lst?dist[lst-1]:0;
                }
                else if(i)
                    dist[i] +=dist[i-1];
            }
            else{
                ans+=min(v[i].x,v[i].y);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}  

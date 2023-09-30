#include <bits/stdc++.h>
using namespace std;
#define x first 
#define y second
#define printP(A)for(auto c:A)cout<<"("<<c.x<<","<<c.y<<")  ";cout<<endl;
int main(){
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>> q;
        q.push({n,{1,n}});
        int cont = 1;
        vector<int> nums(n+1,0);
        while(!q.empty()){
            auto p = q.top();
            if(p.x== 0)break;
            q.pop();
            // cout<<p.x<<" "<<p.y.x<<" "<<p.y.y<<endl;
            vector<pair<int,int>> vec;
            vec.push_back({p.y.x,p.y.y});
            while(!q.empty() && q.top().x == p.x){
                
                vec.push_back({q.top().y.x,q.top().y.y});
                q.pop();
            }
            sort(vec.begin(),vec.end());
            // printP(vec)
            for(int i = 0;i<vec.size();i++){
                if(((vec[i].y-vec[i].x)+1)% 2== 0){
                    int idx = (vec[i].x+vec[i].y-1)/2;
                    nums[idx]= cont;
                    q.push({idx-1-vec[i].x+1,{vec[i].x,idx-1}});
                    q.push({(vec[i].y-(idx+1))+1,{idx+1,vec[i].y}});
                }
                else {
                    int idx = (vec[i].x+vec[i].y)/2;
                    nums[idx] = cont;
                    q.push({idx-1-vec[i].x+1,{vec[i].x,idx-1}});
                    q.push({(vec[i].y-(idx+1))+1,{idx+1,vec[i].y}});
                }
                cont++;
            }
        }
        for(int i = 1;i<=n;i++)cout<<nums[i]<<" ";
        cout<<endl;

    }
    return 0;
}
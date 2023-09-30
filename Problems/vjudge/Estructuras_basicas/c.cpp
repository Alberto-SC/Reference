#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m,d,k,z = 0;
    cin>>n>>m;
    vector<int> dish(n);
    vector<int> cost(n);
    priority_queue<pair<int,int>>cost2;
    for(auto &c:dish)cin>>c;
    for(auto &c:cost){cin>>c;cost2.push({c*-1,z++});};
    vector<int> ans(m,0);
    bool flag = false;
    // while(!cost2.empty()){
    //     pair<int,int>p = cost2.top();
    //     cost2.pop();
    //     cout<<p.first<<" "<<p.second<<endl;
    // }
    
    for(int i = 0;i<m;i++){
        cin>>d>>k;
        d--;
        while(k){
            ans[i]+=cost[d]*min(dish[d],k);
            // cout<<"dds"<<ans[i]<<endl;
            k-=min(k,dish[d]);
            dish[d]-= min(dish[d],k);
            int index = cost2.top().second;            
            if(dish[index]== 0 && k>0 && cost2.size()==1){ans[i] = 0;flag = false;break;}
            cost2.top();
            d = index;
        }
    
        // cout<<ans[i];
        if(flag)break;
    }
    for(auto c:ans)cout<<c<<endl;
    return 0;
}
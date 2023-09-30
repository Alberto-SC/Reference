#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
int main(){
    int n,up,down;
    cin>>n;
    vector<pair<int,int>> points;
    pair<int,int> pos = {0,0};
    for(int i = 0;i<n;i++){
        cin>>up>>down;
        pos = make_pair(pos.x+up,pos.y+up);
        points.push_back(pos),
        pos = make_pair(pos.x+down, pos.y-down);
    }
    // for(auto c:points)cout<<c.first<<" "<<c.second<<endl;
    cout<<0<<endl;
    for(int i = 1;i<n;i++){
        pos = points[i];
        pair<int,int> pos1 = points[i-1];
        double pendiente = (double)(pos.y-pos1.y)/(pos.x-pos1.x);
        vector<int> ans ;
        ans.push_back(i);
        for(int j = i-2;j>=0;j--){
            pair<int,int> pos2 = points[j];
            double pendiente2 = (double)(pos.y-pos2.y)/(pos.x-pos2.x);
            // cout<<"pendiente "<<pendiente<<" "<<pendiente2<<endl;
            if(pendiente2<pendiente){
                ans.push_back(j+1);
                pendiente = pendiente2;
            }
        }
        cout<<ans.size()<<" ";
        sort(ans.begin(),ans.end());
        for(auto c:ans)cout<<c<<" ";
        cout<<endl;
    }
    return 0;
}
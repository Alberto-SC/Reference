#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){
	int t= 1,type,m;
    cin>>t;
    priority_queue<pair<int,int>> p1;
    priority_queue<pair<int,int>> p2;
    vector<bool> used(500007,false);
    int id = 1;
    while(t--){
        cin>>type;
        if(type ==1){
            cin>>m;
            p1.push({m,-id});
            p2.push({-id,m});
            id++;
        }   
        else if(type == 2){
            while(used[-p2.top().first]){
                p2.pop();
            } 
            auto x = p2.top();
            cout<<-x.first<<" ";
            used[-x.first] = true;
            p2.pop();
        }
        else{
            while(used[-p1.top().second]){
                p1.pop();
            }
            auto x = p1.top();
            // cout<<x.first<<" "<<x.second<<endl;
            cout<<-x.second<<" ";
            used[-x.second] = true;
            p1.pop();
        }
    }
    cout<<endl;
    return 0;
}  


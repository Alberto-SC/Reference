#include <bits/stdc++.h>
using namespace std;
const int maxn = 100007;
vector<pair<int,int>> graph[maxn];
map<string,pair<int,int>> names;
map<string,int> times;
int main(){
    int D,I,S,V,F,P,u,v,L;
    cin>>D>>I>>S>>V>>F;
    string name;
    vector<vector<string>> ins(I);
    vector<vector<string>> outs(I);
    map<string,vector<int>> better_green;
    map<pair<int,int>,string> namee;
    for(int i = 0;i<S;i++){
        cin>>u>>v>>name>>L;
        graph[v].push_back({u,L});
        names[name] = {u,v};
        times[name] = L;
        namee[{u,v}] = name;
        ins[v].push_back(name);
        outs[u].push_back(name);
        better_green[name] = vector<int> (D);
    } 
    vector<vector<string>> cars(V);
    for(int i = 0;i<V;i++){
        cin>>P;
        for(int j = 0;j<P;j++){
            cin>>name;            
            cars[i].push_back(name);
        }
    }
    sort(cars.begin(),cars.end(),[&](vector<string> car1,vector<string> car2){
        int time1 = 0;
        for(int i = 0;i<car1.size();i++){
            time1+=times[car1[i]];
        }
        int time2 = 0;
        for(int i = 0;i<car2.size();i++){
            time2+=times[car2[i]];
        }
        return time1<time2;
    });
    map<string,map<int,int>> in_streets; 
    map<string,queue<pair<int,int>>> streets;
    vector<pair<string,int>> positions(V);
    // for(int i = 0;i<V;i++){
    //     for(int j = 0;j<cars[i].size();j++){
    //         streets[cars[i][j]].push({i,times[cars[i][j]]});
    //         if(j == 0){
    //             positions[i] = {cars[i][j],times[cars[i][j]]};
    //         }
    //     }
    // }
    // map<string,int> times;
    // vector<int> current_street(V);
    // for(int i = 0;i<D;i++){
    //     for(int j = 0;j<I;j++){
    //         int mx = 0;
    //         string who;
    //         for(auto street:ins[j]){
    //             if(streets[street].size()>mx){
    //                 mx = streets[street].size();
    //                 who = street;
    //             }
    //         }
        
    //         for(auto street:ins[j]){
    //             if(street == who)
    //                 better_green[street][i]=1;
    //         }
    //     }   
    //     for(int j = 0;j<V;j++){
    //         if(better_green[positions[j].first].back()){
    //             if(streets[positions[j].first].front().first == j){
    //                 current_street[j]++;
    //                 if(current_street[j]>=cars[j].size())continue;
    //                 positions[j].first = cars[j][current_street[j]];
    //                 positions[j].second = 1;
    //                 in_streets[cars[j][current_street[j]]][j] = 1;
    //             }
    //         }
    //         else if(in_streets[positions[j].first].count(j)){
    //             in_streets[positions[j].first][j]++;
    //             if(in_streets[positions[j].first][j]==times[positions[j].first]-streets[positions[j].first].size()){
    //                 streets[positions[j].first].push({j,positions[j].second});
    //                 in_streets[positions[j].first].erase(j);
    //                 positions[j].second++;
    //             }
    //             else{
    //                 positions[j].second++;
    //             }
    //         }
    //     }
    // }
    // vector<vector<pair<string,int>>> ans;
    // vector<int> indices;
    // for(int i = 0;i<I;i++){
    //     int who = 0;
    //     int idx = 0;
    //     vector<pair<string,int>> res;
    //     int last = 0;
    //     while(idx < D){
    //         for(auto v:graph[i]){
    //             if(better_green[namee[{v.first,i}]][idx]){
    //                 who = v.first;
    //             }
    //         }
    //         last = idx;
    //         while(last<better_green[namee[{who,i}]].size() && better_green[namee[{who,i}]][last]){
    //             last++;
    //         }
    //         if(last == idx)break;
    //         idx = last;
    //         res.push_back({namee[{who,i}],(last-idx)+1});
    //     }
    //     if(res.size()>0){
    //         indices.push_back(i);
    //         ans.push_back(res);
    //     }
    // }
    cout<<I<<endl;
    int id = 0;
    for(int i = 0;i<I;i++){
        cout<<i<<endl;
        cout<<graph[i].size()<<endl;
        for(auto d:graph[i]){
            cout<<namee[{d.first,i}]<<" "<<D/graph[i].size()<<endl;
            // cout<<d.first<<" "<<d.second<<endl;
        }
    }
    return 0;
}


/*
 o-o  o-o  o-o [X]

 o_o _ _ _ _ | o-o  o-o  o-o [X]
 

 o_o _ _ _ | o-o  o-o  [x] o-o
 
o_o _ | [X] o-o o-o o-o [x]
 | [X] o_o o-o o-o o-o [x]

*/


















































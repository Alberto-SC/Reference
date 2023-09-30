#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<int> Plotsx;
    vector<int> Plotsy;
    vector<pair<int,int>> Plots;
    set<pair<int, int> > s;
    int x,y;
    for(int i = 0;i<3;i++){
        cin>>x>>y;

        Plotsx.push_back(x);
        Plotsy.push_back(y);
        Plots.push_back({x,y});
    }
    sort(Plotsx.begin(),Plotsx.end());
    sort(Plotsy.begin(),Plotsy.end());
    sort(Plots.begin(),Plots.end());
    cout<< (Plotsx[2]-Plotsx[0]) + (Plotsy[2]-Plotsy[0]) +1 <<endl;

    for (int i = Plots[0].first; i <= Plots[1].first; i++) s.insert({i, Plots[0].second});	
    for (int i = Plotsy[0]; i <=Plotsy[2]; i++) s.insert({Plots[1].first, i});
    for (int i = Plots[1].first + 1; i <= Plots[2].first; i++) s.insert({i, Plots[2].second});
    for(auto a:s){
        cout<<a.first<<" "<<a.second<<endl;
    }
    return 0;
}
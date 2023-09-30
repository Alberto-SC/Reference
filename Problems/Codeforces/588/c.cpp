#include <Bits/stdc++.h>
using namespace std;
vector<pair<int,int>> Graph[1000];
set<pair<int,pair<int,int>>> Dom = { {1,{1,1}},{1,2},{1,3},{1,4},{1,5},{1,6}
                            ,{2,2},{2,3},{2,4},{2,5},{2,6},
                            {3,3},{3}}
int main(){
    int n,a,b;
    for(int i = 0;i<n;i++){
        cin>>a>>b;
        Graph{a}.push_back({b,1});
        Graph{b}.push_back({a,1);
    }
    for(int i)
    return 0;
}
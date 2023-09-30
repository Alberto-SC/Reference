#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
int infinite = INT_MAX;
int main(){
    int hb,hs,hc,r;
    string recipe;
    cin>>recipe;
    vector<int> res(3);
    vector<int> has(3);
    vector<int> prices(3);
    for(int i = 0;i<recipe.size();i++){
        if(recipe[i] =='B')res[0]++;
        if(recipe[i] =='S')res[1]++;
        if(recipe[i] =='C')res[2]++;
    }
    cin>>has[0]>>has[1]>>has[2];
    cin>>prices[0]>>prices[1]>>prices[2];
    cin>>r;

}
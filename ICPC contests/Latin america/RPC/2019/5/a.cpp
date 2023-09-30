#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,c;
    cin>>n>>c;
    vector<int>cc(c);
    for(int i = 0;i<c;i++){
        cin>>cc[i];
    }
    vector<pair<int,int>> costc(n);
    for(int i = 0;i<n;i++){
        cout<<i+1<<" ";
        costc[i] = {cc[i],i+1};
    }
    for(int i = n;i<c;i++){
        int min = -100;
        int index = 0;
        for(int j = 0;j<n;j++){
            if(costc[j].first<min){
                min = costc[j].first;
                index = j;
            }
        }
        cout<<costc[index].second<<" ";
        costc[index].first = cc[i];
    }
    return 0;
}
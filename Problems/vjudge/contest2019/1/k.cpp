#include <bits/stdc++.h>
using namespace std;
#define print(A) for(auto c:A)cout<<c<<" ";
int main(){
    int n,h,l;
    cin>>n;
    vector<pair<int,int>> dominos;
    for(int i = 0;i<n;i++){
        cin>>h>>l;
        dominos.push_back(make_pair(h%2,l%2));
    }  
    int sumh = 0;
    int suml = 0;  
    for(auto a:dominos){
        sumh+= a.first;
        suml+= a.second;
    }
    //cout<<sumh<<" "<<suml<<endl;
    if(sumh%2 == 0 && suml%2 ==0)cout<<0;
    else if(sumh%2 != suml%2)cout<<-1;
    else{
        for(int i = 0;i<n;i++){
            if(dominos[i].first != dominos[i].second){cout<<1;return 0; }
        }
        cout<<-1;
    }
    return 0;   
}
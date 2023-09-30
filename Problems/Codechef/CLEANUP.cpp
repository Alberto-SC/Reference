#include <bits/stdc++.h>
using namespace std;
int main(){
    int t,n,m,ca;
    cin>>t;
    while(t--){
        cin>>n>>m;
        vector<int> c(n,0),chef,assitant;
        int turn =  0;
        for(int i = 0;i<m;i++){
            cin>>ca;
            c[ca-1] = 1;
        }
        for(int i = 0;i<n;i++){
            if(c[i] == 1)continue;
            if(!turn)chef.push_back(i+1);
            else assitant.push_back(i+1);
            turn = !turn;
        }
        for(int j = 0;j<chef.size();j++)cout<<chef[j]<<" ";
        cout<<"\n";
        for(int j = 0;j<assitant.size();j++)cout<<assitant[j]<<" ";
        cout<<"\n";
    }
    return 0;
}
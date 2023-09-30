#include <bits/stdc++.h>
using namespace std;
int main(){
    int t,n,points;
    string s,u;
    cin>>t;
    while(t--){
        points = 0;
        cin>>n>>s>>u;
        vector<int> discart(n,0);
        for(int i = 0;i<s.size();i++){
            if(s[i]== u[i] && discart[i] == 0){points++;}
            if(s[i]!= u[i] && discart[i] == 0 && u[i]!= 'N')discart[i+1]=1;
        }
        cout<<points<<"\n";
    }
    return 0;
}
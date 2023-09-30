#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    vector<string> ss;
    while(cin>>s){
        ss.push_back(s);
    }
    vector<pair<int,int>>xy;
    xy.push_back({1,1});
    xy.push_back({3,1});
    xy.push_back({5,1});
    xy.push_back({7,1});
    xy.push_back({1,2});
    int x = 0,y = 0;
    long long int ans = 1;
    for(int i = 0;i<5;i++){
        int cont = 0;
        x = 0,y = 0;
        while(x<ss.size()){
            if(ss[x][y%ss[0].size()] =='#')cont++;
            x+=xy[i].second; 
            y+=xy[i].first;
        }
        cout<<cont<<endl;
        ans*=cont;
    } 
    cout<<ans<<endl;
    return 0;
}
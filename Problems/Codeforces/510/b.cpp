#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,p;
    string s;
    cin>>n;
    vector<pair<int,int>> j(n);
    for(int i = 0;i<n;i++){
        cin>>p>>s;
        int val = 0;
        for(int j = 0;j<s.size();j++){
            if(s[j]=='A')val+= 4;
            if(s[j]=='B')val+= 2;
            if(s[j]=='C')val+= 1;
        }
        j[i] = {val,p};
    }
    sort(j.begin(),j.end());
    int ind = 0;
    map<int,int> e;
    for(int i = 0;i<n;){
        e[j[i].first] = j[i].second;
        int aux = j[i].first;
        i++;
        while(j[i].first == aux){i++;}
    }
    int ans = 1000000000;
    for(auto c:e){
        if(c.first== 7)ans = min(ans,c.second);
        else{
            for(auto d:e){
                if(c.first|d.first == 7)ans = min(ans,c.second+d.second);
                else{
                    for(auto a:e){
                        if(c.first|d.first|a.first == 7)ans = min(ans,c.second+d.second+a.second);
                    }
                }
            }
        }
    }
    if(ans ==1000000000)cout<<-1<<endl;
    else 
        cout<<ans<<endl;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int new_game(vector<list<int>> p){
    map<vector<list<int>>,bool> vis;
    while(!p[0].empty() && !p[1].empty()){
        int p0 = p[0].front();
        int p1 = p[1].front();
        if(vis[p]) return 0;
        else vis[p] = true;
        p[0].pop_front();
        p[1].pop_front();
        if(p[0].size()>=p0 && p[1].size()>=p1){
            vector<list<int>> np(2);
            int cont = 0;
            for(auto k:p[0]){
                if(cont>=p0)break;
                np[0].push_back(k);
                cont++;
            }
            cont = 0;
            for(auto k:p[1]){
                if(cont>=p1)break;
                np[1].push_back(k);
                cont++;
            }
            if(new_game(np)){
                p[1].push_back(p1);
                p[1].push_back(p0);
            }
            else{
                p[0].push_back(p0);
                p[0].push_back(p1);
            }
        }
        else if(p0>p1){
            p[0].push_back(p0);
            p[0].push_back(p1);
        }
        else{
            p[1].push_back(p1);
            p[1].push_back(p0);
        }
    }
    if(p[0].empty())
        return 1;
    return 0;
}
int main(){__
    vector<list<int>> p(2);
    int num;
    string line;
    int idx = -1;
    while(getline(cin,line)){
        if(line[0] == 'P'){
            idx++;
            continue;
        }
        if(line[0] == 13)continue;
        p[idx].push_back(stoi(line));
    }
    while(!p[0].empty() && !p[1].empty()){
        int p0 = p[0].front();
        int p1 = p[1].front();
        p[0].pop_front();
        p[1].pop_front();
        if(p[0].size()>=p0 && p[1].size()>=p1){
            vector<list<int>> np(2);
            int cont = 0;
            for(auto k:p[0]){
                if(cont>=p0)break;
                np[0].push_back(k);
                cont++;
            }
            cont = 0;
            for(auto k:p[1]){
                if(cont>=p1)break;
                np[1].push_back(k);
                cont++;
            }
            if(new_game(np)){
                p[1].push_back(p1);
                p[1].push_back(p0);
            }
            else{
                p[0].push_back(p0);
                p[0].push_back(p1);
            }
        }
        else if(p0>p1){
            p[0].push_back(p0);
            p[0].push_back(p1);
        }
        else{
            p[1].push_back(p1);
            p[1].push_back(p0);
        }
    }
    lli ans = 0;
    if(p[0].empty()){
        int mult = p[1].size();
        for(auto c:p[1]){
            cout<<c<<" ";
            ans+=c*mult;
            mult--;
        }
        cout<<endl;
    }
    else{
        int mult = p[0].size();
        for(auto c:p[0]){
            cout<<c<<" ";
            ans+=c*mult;
            mult--;
        }
        cout<<endl;
    }
    cout<<ans<<endl;
    return 0;

}  


#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
vector<vector<int>> pos; 
vector<pair<pair<int,char>,int>> ps;
bool comp(pair<pair<int,char>,int> A,pair<pair<int,char>,int> B){
    return pos[A.y].size()>pos[B.y].size();
}
bool comp2(pair<pair<int,char>,int> A,pair<pair<int,char>,int> B){
    return A.x.x<B.x.x;
}
bool comp3(pair<pair<int,char>,int> A,pair<pair<int,char>,int> B){
    return pos[A.y].size()<pos[B.y].size();
}
int main(){
    int n;
    string s;
    cin>>n;
    pair<int,char> p;
    map<pair<int,char>,vector<int>>mp;
    vector<string> strings;
    for(int i = 0;i<n;i++){
        cin>>s;
        char last;
        int cont = 0;
        for(int i = 0;i<s.size();i++){
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
                cont++;
                last = s[i];
            }
        }
        p = {cont,last};
        mp[p].push_back(i);
        vector<pair<pair<int,int>,int>> all; 
        strings.push_back(s);
    }
    int i = 0;
    for(auto c:mp){
        // cout<<c.x.x<<" "<<c.x.y<<" "<<endl;
        // for(auto d:c.y)cout<<d<<" ";
        // cout<<endl;
        ps.push_back({c.x,i});
        pos.push_back(c.y);
        i++;
    }
    sort(ps.begin(),ps.end(),comp);
    int k = 0;
    // cout<<pos.size()<<" "<<endl;
    // cout<<k<<endl;
    while(k<ps.size() &&pos[ps[k].y].size()>1)k++;
    vector<pair<pair<int,char>,int>> ones; 
    vector<pair<pair<int,char>,int>> two;
    for(int i = 0;i<k;i++)
        two.push_back(ps[i]);
    vector<vector<string>> ans;
    for(int i = 0;i<k;i++)
        if(pos[ps[i].y].size()&1)ones.push_back(ps[i]);
    for(int i = k;i<ps.size();i++)
        ones.push_back(ps[i]);
    // cout<<ones.size()<<" "<<two.size()<<endl;
    if(two.size()== 0)return cout<<0<<endl,0;
    sort(ones.begin(),ones.end(),comp2);
    sort(two.begin(),two.end(),comp3);
    // for(int j = 0;j<ones.size();j++)cout<<ones[j].x.x<<" "<<ones[j].x.y<<" "<<ones[j].y<<endl;
    // cout<<endl<<endl;
    // for(int j = 0;j<two.size();j++)cout<<two[j].x.x<<" "<<two[j].x.y<<" "<<two[j].y<<endl;
    int x = 0,z;
    i = 0;
    int sz =pos[two[0].y].size();
    while(i<ones.size()){
        sz = pos[two[x].y].size();
        z= 0;
        while(sz&& i<ones.size()){
            if(i+1<ones.size() && ones[i].x.x == ones[i+1].x.x){
                ans.push_back(vector<string>(4,"a"));
                ans[ans.size()-1][0] = strings[pos[two[x].y][z]];
                ans[ans.size()-1][1] = strings[pos[ones[i].y][pos[ones[i].y].size()-1]];
                ans[ans.size()-1][2] = strings[pos[two[x].y][z+1]];
                ans[ans.size()-1][3] = strings[pos[ones[i+1].y][pos[ones[i+1].y].size()-1]];
                i+=2;
                sz-=2;
                z+=2;
            }
            else i++;
        }
        if(i>=ones.size())break;
        x++;
    }
    // cout<<x<<" "<<sz<<endl;
    int j = 0;
    for(int i = x;i<two.size();i++){
        if(sz>=4){
            int z = pos[two[x].y].size()-sz;
            int how = sz/4;
            while(how--){
                ans.push_back(vector<string>(4,"a"));
                ans[ans.size()-1][0] = strings[pos[two[x].y][z]];
                ans[ans.size()-1][1] = strings[pos[two[x].y][z+1]];
                ans[ans.size()-1][2] = strings[pos[two[x].y][z+2]];
                ans[ans.size()-1][3] = strings[pos[two[x].y][z+3]];
                sz-=4;
                z+=4;
            }
        }
    }
    cout<<ans.size()<<endl;
    for(int i = 0;i<ans.size();i++){
        cout<<ans[i][1]<<" "<<ans[i][0]<<endl<<ans[i][3]<<" "<<ans[i][2]<<endl;
    }
    // for(int j = k;j<n;j+=2){
    //     if(z>=pos[ps[x].y])z = 0,x++;
    //  

    // }
    // while()
    return 0;
}
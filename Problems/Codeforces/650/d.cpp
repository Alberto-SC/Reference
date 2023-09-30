#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
int main(){
    int t,n;
    string s;
    cin>>t;
    while(t--){
        cin>>s;
        cin>>n;
        vector<int> b(n);
        for(auto &c:b)cin>>c;
        sort(s.rbegin(),s.rend());
        string t(n,'a');
        int idx = 0;
        bool flag = true;
        vector<bool> used(n,false);
        vector<vector<int>> ans;
        while(true){
            vector<int> zeros;
            for(int i = 0;i<n;i++){
                if(b[i]== 0 && !used[i]){
                    zeros.push_back(i);
                    used[i]= true;
                }    
            }
            for(int i = 0;i<n;i++){
                if(b[i]!= 0){
                    for(auto c:zeros){
                        b[i] -= abs((i+1)-(c+1));
                    }
                }
            }
            if(zeros.size()== 0)break;
            ans.push_back(zeros);
        }
        map<char,int>  mp;
        for(auto c:s)mp[c]++;
        auto it = mp.rbegin();
        for(auto c:ans){
            while(it->y<c.size())it++;
            for(auto d:c){
                t[d] = it->x;
            }
            it++;
        }
        cout<<t<<endl;
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'
int maxDepth(string S){
    int current_max = 0; 
    int max = 0; 
    int n = S.length();
    for (int i = 0; i < n; i++){
        if (S[i] == '('){
            current_max++;
            if (current_max > max)
                max = current_max;
        }
        else if (S[i] == ')')
        {
            if (current_max > 0)
                current_max--;
            else
                return -1;
        }
    }
    if (current_max != 0)
        return -1;
    return max;
}
signed main(){__
    int t,n;
    string s;
    getline(cin,s);
    n = s.size();
    int c = 0,ans = 0;
    vector<pair<int,int>> P;
    for(int i = 0;i<n;i++){
        if(s[i]== ' ')continue;
        if(s[i]== ')')continue;
        int c = 1;
        for(int j = i+1;j<n;j++){
            if(s[j] == ' ')continue;
            if(s[j]== '(')c++;
            if(s[j]== ')')c--;
            if(c== 0){P.push_back({i,j});break;}
        }
    }
    for(auto d:P){
        bool f = false;
        string x = s.substr(d.first+1,(d.second-d.first)-1);
        for(int i = d.first+1;i<d.second;i++)
            if(s[i]!= ' ')f = true;
        if(!f){ans++;continue;}
        ans+=maxDepth(x)+1;
    }
    cout<<ans<<endl;
} 



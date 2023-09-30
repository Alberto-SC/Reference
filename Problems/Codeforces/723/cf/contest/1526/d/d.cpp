#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

map<char,int> id = {{'A',0},{'N',1},{'T',2},{'O',3}};

signed main(){__
	int t= 1,n;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        n = s.size();
        vector<vector<int>> changes(4,vector<int> (4));
        vector<int> b(4);
        for(int i = 0;i<n;i++)
            b[id[s[i]]]++;
        for(int i = 0;i<4;i++){
            int c = 0;
            for(int j = 0;j<n;j++){
                changes[i][id[s[j]]]+=c;
                if(id[s[j]]==i)c++;
            }
        }
        int best = -1;
        vector<int> v = {0,1,2,3};
        vector<int> ans;
        do{
            int x = 0;
            for(int i = 0;i<4;i++){
                for(int j = i+1;j<4;j++){   
                    x += changes[v[j]][v[i]];
                }
            }
            if(x>best){
                best = x;
                ans = v;
            }
        }while(next_permutation(v.begin(),v.end()));
        string z = "ANTO";
        for(int i = 0;i<4;i++){
            for(int j = 0;j<b[ans[i]];j++)
                cout<<z[ans[i]];
        }       
        cout<<endl;
    }
    return 0;
}  

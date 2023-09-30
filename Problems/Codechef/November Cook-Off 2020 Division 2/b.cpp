#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
	int t= 1,n;
    cin>>t;
    while(t--){ 
        string s,t;
        cin>>s>>t;
        n = s.size();
        vector<int> odds;
        vector<int> evens;
        for(int i = 0;i<n;i++){
            if(i&1)odds.push_back(s[i]==t[i]);
            else evens.push_back(s[i]==t[i]);
        }
        // for(auto c:odds)cout<<c<<" ";
        // cout<<endl;
        // for(auto c:evens)cout<<c<<" ";
        // cout<<endl;
        int cont = 0;
        for(int i = 0;i<odds.size();){
            if(odds[i]==1){i++;continue;}
            int j = i;
            while(j<odds.size() && odds[j]== 0){
                j++;
            }
            i = j;
            cont++;
        }
        for(int i = 0;i<evens.size();){
            if(evens[i]==1){i++;continue;}
            int j = i;
            while(j<evens.size() && evens[j]== 0){
                j++;
            }
            i = j;
            cont++;
        }
        cout<<cont<<endl;
    }
    return 0;
}  


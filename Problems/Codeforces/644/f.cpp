#define _GLIBCXX_DEBUG 1
#define _GLIBCXX_DEBUG_PEDANTIC 1
#define _FORTIFY_SOURCE 2
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;

int main(){
    int t,n,m;
    cin>>t;
    while(t--){
        cin>>n>>m;
        vector<string> s(n);
        for(auto &c:s)cin>>c;
        string nw;
        bool flag = true;
        for(int i =0;i<m;i++){
            for(int j = 0;j<26;j++){
                // if((char)(j+'a') == s[0][i])continue;
                nw = s[0];
                // cout<<nw<<" ";
                nw[i] = (char)(j+'a');
                flag = true;
                // cout<<nw<<endl;
                for(int k = 0;k<n;k++){
                    int cont = 0;
                    for(int l = 0;l<m;l++){
                        if(nw[l] != s[k][l])cont++;
                    }
                    if(cont >1){flag = false;break;}
                } 
                if(flag){break;}
            }
            if(flag)break;
        }
        if(flag == false)cout<<-1<<endl;
        else 
        cout<<nw<<endl;
    }
    return 0;
}
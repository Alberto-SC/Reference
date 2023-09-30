#include <bits/stdc++.h>
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

using namespace std;

bool valid(string s){
    int x = 0;
    for(auto c:s){
        if(c=='X')x++;
        else x--;
        if(x<0)return false;
    }
    if(x ==0)return true;
    return false;
}

signed main(){__
    int T,n;
    cin>>T;
    while(T--){
        cin>>n;
        string s;
        cin>>s;
        int x = 1;
        while(x--){
        for(int sz = 2;sz<=2*n;sz+=2){
            for(int sz2 = 2;sz2<=2*n;sz2+=2){
                for(int i = 0;i<2*n;i++){
                    if((i+(sz+sz2))-1>=2*n)break;
                    string str1 = s.substr(i,sz);
                    string str2 = s.substr(i+sz,sz2);
                    if(valid(str1) && valid(str2)){
                        string nw = s.substr(0,i)+str2+str1+s.substr(i+sz+sz2);
                        if(nw<s)s = nw;
                    }
                }
            }
        }
        }
        cout<<s<<endl;
    }
    return 0;
}

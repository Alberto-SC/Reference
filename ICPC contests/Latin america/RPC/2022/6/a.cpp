#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'
//  ~~~~~~~~~~~~~~~~~~~~   
signed main(){ //__
    int t = 1,n;
    while(t--){
        string s;
        getline(cin,s);
        int x = 0;
        int cont = 0;
        for(char c:s){
            if(c >= 32 && c <= 126){
                x += (int)c;
                cont++;
            }
        }
        x/=cont;
        if(x>=32 && x<= x<=126)
            printf("%c\n", x);
    }
}   
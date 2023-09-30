#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
	int t= 1,n;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        n = s.size();
        int cont = 0,bo = 0,co = 0;
        for(int i = 0;i<n;i++){
            if(s[i]=='(')bo++;
            else if(s[i]== ')' && bo)bo--,cont++;
            else if(s[i] == '[')co++;
            else if(s[i]== ']' &&co)co--,cont++;
        }        
        cout<<cont<<endl;
    }
    return 0;
}  


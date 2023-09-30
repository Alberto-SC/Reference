#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
	int t= 1,n;
    cin>>t;
    while(t--){
        cin>>n;
        string s;
        cin>>s;
        string b(n,'1');
        int last = (s[0]-'0')+1;
        for(int i = 1;i<n;i++){
            if(s[i] == '1'){
                if(last== 2)
                    b[i] = '0',last = 1;
                else    
                    b[i] = '1',last = 2;
            }
            else{
                if(last == 1)
                    b[i] ='0',last = 0;
                else 
                    b[i] = '1',last = 1; 
            }
        }
        cout<<b<<endl;
    }
    return 0;
}  


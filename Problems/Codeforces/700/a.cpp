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
        for(int i = 0;i<n;i++){
            if(i&1){
                if(s[i]== 'z')s[i] = 'y';
                else s[i] = 'z';
            }
            else {
                if(s[i]== 'a')s[i] = 'b';
                else s[i] = 'a';
            }
        }
        cout<<s<<endl;
    }
    return 0;
}  


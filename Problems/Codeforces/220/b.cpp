#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
	int n;
    string s;
    cin>>s;
    n = s.size();
    lli ans = 1;
    for(int i = 0;i<n;){
        int j = i+1;
        if(s[i]!= '9'){
            int cont = 0;
            // cout<<'9'-s[j-1]<<" "<<s[j]<<endl;
            while(j<n && s[j] == char('9'-s[j-1]+'0')){
                j++;
                cont++;
            }
            if(cont%2== 0 && cont>1)ans*=(cont/2)+1;
            else if(cont>=1)ans*=1;
            // cout<<j<<" "<<cont<<endl;
        }
        i = j;
    }
    cout<<ans<<endl;
    return 0;
}  


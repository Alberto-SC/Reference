#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
	int t= 1,n;
    while(t--){
        cin>>n;
        string s;
        cin>>s;
        int ans = 1e9;
        for(int i = 0;i<200;i++){
            int aux = i;
            bool flag = true;
            for(int j = 0;j<s.size();j++){
                if(s[j]== '+')aux++;
                if(s[j]== '-'){
                    if(aux>0)aux--;
                    else{
                        flag = false;
                        break;
                    }
                }
            }
            if(flag)
                ans = min(ans,aux);
        }
        cout<<ans<<endl;
    }
    return 0;
}  


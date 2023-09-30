#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n;
    cin>>n;
    string s;
    cin>>s;
    int l = 0;
    int ans = 0;
    for(int i = 1;i<=n;i++){
        vector<int> digits;
        int aux = i;
        while(aux){
            digits.push_back(aux%10);
            aux/=10;
        }
        bool flag = true;
        reverse(digits.begin(),digits.end());
        for(int j = 0;j<digits.size();j++){
            if(digits[j]!=(s[l]-'0')){
                flag = false;
                break;
            }
            else l++;
        }
        if(!flag){
            ans = i;
            break;
        }
    }
    cout<<ans<<endl;
    return 0;
}  

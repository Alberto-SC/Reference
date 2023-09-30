#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
    int t = 1,n;
    string s;
    cin>>t;
    while(t--){
        cin>>n;
        cin>>s;
        int ans = 0;
        int ans2 = 0;
        for(int i = 0;i<n;){ 
            int j = i;
            if(s[i]== '1'){
                int cont =0;
                while(j<n && s[j]== '1'){
                    cont++;
                    j++;
                }
                // cout<<cont<<endl;
                ans+=cont-1;
            }
            else {
                int cont = 0;
                while(j<n && s[j] == '0'){
                    cont++;
                    j++;
                }
                ans2+=cont-1;
            }
            i = j;
        }
        cout<<max(ans,ans2)<<endl;
    }
    return 0;
}


#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define x first 
#define y second
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
    lli t = 1,n;
    cin>>t;
    while(t--){
        string s;
        cin>>n;
        cin>>s;
        vector<bool> bads(n);
        for(int i = 0;i<n;i++){
            if(s[i]== 'L'){
                if(s[(i+1)%n] == 'R' && s[((i-1)+n)%n] == 'L') bads[i] = true;
                else if(s[(i-1)%n] == 'R')bads[i] = true;
                else bads[i] = false;
            }
            else {
                if(s[(i+1)%n] == 'R' && s[((i-1)+n)%n]== 'L') bads[i] = true;
                else if(s[(i+1)%n] == 'L')bads[i] = true;
                else bads[i] = false;
            }
        }
        // for(auto c:bads)cout<<c<<" ";
        // cout<<endl;
        int ans = 0;
        vector<int> used(n,false);
        for(int i = 0;i<n;i++){
            if(used[i]||bads[i])continue;
            if(i== 0){
                int j = n-1;
                int cont = 1;
                while(j>0 && !used[j]  && bads[j] == bads[i]){
                    cont++;
                    used[j] = true;
                    j--;
                }
                j = i+1;
                while(j<n && !used[j] && bads[j] == bads[i]){
                    cont++;
                    used[j] = true;
                    j++;
                }
                if(cont== 1)ans++;
                else
                    ans+=cont/2;
            }
            else {
                int cont = 1;
                int j = i+1;
                while(j<n && !used[j] && bads[j] == bads[i]){
                    cont++;
                    used[j] = true;
                    j++;
                }
                if(cont == 1)ans++;
                else
                    ans+= cont/2;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}


#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){
	int t= 1,n;
    cin>>t;
    while(t--){
        cin>>n;
        string s,t;
        cin>>s;
        int cont =0;
        for(int i = 0;i<n-1;i++){
            if(s[i]==s[i+1]&& s[i]!='?')
                cont++;
        }
        for(int i = 0;i<n;){
            int j = i;
            if(s[i]!='?'){
                i++;
                continue;
            }
            while(j<n && s[j]== '?'){
                j++;
            }
            if(i){
                char last = s[i-1];
                for(int k = i;k<j;k++)
                    s[k] = last=='B'?'R':'B',last = s[k];
            }
            else if(j==n){
                char last = 'B';
                for(int k = i;k<j;k++)
                    s[k] = last=='B'?'R':'B',last = s[k];
            }
            else {
                char last = s[j];
                for(int k = j-1;k>=i;k--)
                    s[k] = last=='B'?'R':'B',last = s[k];
            }
            i = j;
        }
        cout<<s<<endl;
    }
    return 0;
}  

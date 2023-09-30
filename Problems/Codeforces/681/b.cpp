#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
    int t = 1,n,a,b;
    cin>>t;
    while(t--){
        cin>>a>>b;
        string s;
        cin>>s;
        n = s.size();
        int first = -1,last = -1;
        for(int i = 0;i<n;i++){
            if(s[i] =='1')last = i;
        }
        for(int i =n-1;i>=0;i--){
            if(s[i] == '1')first =i;
        }

        lli ans = 0;
        for(int i = first;i<last;){
            int j = i;
            int cont = 0;
            if(s[i]== '0' ){
                while(j<n && s[j]== '0'){
                    cont++;
                    j++;
                }
                // cout<<j<<" "<<cont<<endl;
                if((cont*b)+a<=(2*a)){
                    for(int k = i;k<j;k++){
                        s[k] = '1';
                    }
                    ans+=(cont*b);
                }
            }
            else j++;
        
            i = j;
        }
        int cont = 0;
        for(int i = first;i<last;){
            int j = i;
            if(s[i] == '0'){
                while(j<n && s[j] == '0'){
                    j++;
                }
                cont++;
            }
            else j++;
            i = j;
        } 
        ans+=(cont+1)*a;
        if(first ==-1)cout<<0<<endl;
        else
        cout<<ans<<endl;
    }
    return 0;
}


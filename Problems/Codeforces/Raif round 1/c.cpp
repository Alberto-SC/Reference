#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
    int t = 1,n;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        n = s.size();
        int A = 0;
        int B = 0;
        int ans = 0;
        for(int i = 0;i<n;){
            int j = i;
            int cont = 0;
            B = 0;
            if(s[i]== 'A'){
                while(j<n && s[j]== 'A'){
                    cont++;
                    j++;
                }
                A +=cont;
            }
            else{
                while(j<n && s[j] == 'B'){
                    cont++;
                    j++;
                }
                B =cont;
            }
            if(A){
                int aux = min(A,B);
                A-=aux;
                B-=aux;
                if(B) A = 0;
            }
            ans+=B;
            i = j;
        }
        // cout<<A<<endl<<ans<<endl;
        ans = ans&1;
        ans+=A;
        cout<<ans<<endl;
    }
    return 0;
}


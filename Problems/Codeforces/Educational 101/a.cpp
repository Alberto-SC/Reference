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
        n  = s.size();
        bool flag = true;
        int idx1,idx2,cont =0;
        for(int i = 0;i<n;i++){
            if(s[i]== ')') idx1 = i;
            if(s[i]== '(') idx2 = i;
            if(s[i]== '?')cont++;
        }
        if(idx1>idx2&& cont%2 ==0){
            cout<<"YES"<<endl;
        }
        else if(idx1>idx2 && cont&1){
            cout<<"NO"<<endl;
        }
        else{
            int cont1 = 0,cont2 =0;
            for(int i = 0;i<idx1;i++){
                cont1++;
            }
            for(int i= n-1;i>idx2;i--){
                cont2++;
            }
            if(cont1>0 && cont2>0 && (cont-(2))%2 ==0)
                cout<<"YES"<<endl;
            else 
                cout<<"NO"<<endl;
        }
    }
    return 0;
}  


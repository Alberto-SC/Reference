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
        cin>>n;
        cin>>s;
        string aux = s;
        sort(aux.begin(),aux.end());
        int ls = 0,gt = 0,m = 0;
        for(int i = 0;i<n;i++){
            if(s[i]== '<')ls++;
            else if(s[i] == '>')gt++;
            else m++;
        }

        if(aux[0] == aux.back()|| ls && !gt || gt && !ls)cout<<n<<endl;
        else {
            int cont = 0;
            for(int i = 0;i<n;i++){
                if(s[((i-1)+n)%n] == '-')cont++;
                else if(s[i]== '-')cont++;
            }    
            cout<<cont<<endl;
        }
            
    }
    return 0;
}


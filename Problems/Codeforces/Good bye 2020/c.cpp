#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

int main(){__
	int t= 1,n;
    cin>>t;
    string s; 
    while(t--){
        cin>>s;
        int n = s.size();
        int cont = 0;
        for(int i = 0;i<n-1;i++){
            if(s[i]== '#')continue;
            if(s[i]== s[i+1])s[i+1] = '#',cont++;
            if(i+2<n && s[i]== s[i+2])s[i+2] = '#',cont++;
        }
        cout<<cont<<endl;
    }
    return 0;
}  


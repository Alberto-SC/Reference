#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
	int t= 1,n;
    cin>>t;
    while(t--){
        cin>>n;
        string s(n,'0');
        s[0] = '9';
        int num = 8;
        for(int i = 1;i<n;i++){
            s[i] = char(num+'0');
            num++;
            if(num ==10)num =0;
        }
        cout<<s<<endl;
    }
    return 0;
}  


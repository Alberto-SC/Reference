#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
bool fair(lli n){ 
    string s = to_string(n);
    // cout<<s<<endl;
    for(int i = 0;i<s.size();i++){
        if(s[i]== '0')continue;
        if(n%(s[i]-'0'))return false;
    }
    return true;
}

int main(){
	lli t= 1,n;
    cin>>t;
    while(t--){
        cin>>n;
        int cont = 0;
        while(!fair(n)){
            n++;
            cont++;
        }
        cout<<n<<endl;
        // cout<<"C: "<<cont<<endl;
    }
    return 0;
}  


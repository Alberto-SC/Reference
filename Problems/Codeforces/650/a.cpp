#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

int main(){
    int t = 1,n;
    string s;
    cin>>t;
    while(t--){
        cin>>s;
        n = s.size();
        for(int i = 0;i<n;i+=2){
            cout<<s[i];
        }
        cout<<s[n-1];
        cout<<endl;
    }
    return 0;
}
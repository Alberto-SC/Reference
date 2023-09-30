#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    int n = s.size();
    vector<int> os;
    int acum=0;
    int cont =0;
    for(int i = 0;i<n;){
        cont =0;
        while(s[i]=='v' &&i<n){
            i++;
            cont++;
        }
        cont >1?cont -=1:cont=0;    
        acum+=cont;
        if(i==n)os.push_back(acum);
        while(s[i]=='o'&&i<n){
            i++;
            os.push_back(acum);
        }
    }
    long long ans = 0;
    for(int i = 0;i<os.size();i++)
        ans+= 1lli*os[i]*(os[os.size()-1]-os[i]);
    cout<<ans<<endl;
    return 0;
}
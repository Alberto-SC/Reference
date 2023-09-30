#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    string t;
    cin>>n>>k;
    cin>>t;
    int ind = -1;
    for(int i = n-1;i>=0;i--){
        string suffix = t.substr(i);
        for(int j = 0;j<n;j++){
            string preffix = t.substr(0,j);
            if(suffix==preffix){ind = j;break;}
        }
    }
    string ans = "";
    if(ind == -1){
        while(k--)ans+=t;
    }
    else{
        ans = t.substr(0,ind);
        while(k--){ans+=t.substr(ind);}
    }
    cout<<ans<<endl;

}
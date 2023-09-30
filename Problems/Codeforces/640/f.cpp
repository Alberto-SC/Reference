#include <bits/stdc++.h>
using namespace std;
int main(){
    int t,a,b,c;
    cin>>t;
    while(t--){
        cin>>a>>b>>c;
        string sa = "00";
        string sb = "01";
        string sb2 = "10";
        string sc = "11";
        string ans = "";
        for(int i = 0;i<a;i++){
            ans+=sa;
        }
        if(b&1){
            bool turn = 1;
            for(int i = 0;i<b;i++){
                turn?ans+=sb:ans+=sb2;
                turn = !turn;
            }
            for(int i = 0;i<c;i++)
                ans+=sc;
            cout<<ans[0]<<ans[1];
            for(int i =3;i<ans.size();i+=2)
                cout<<ans[i];
        }
        else{
            bool turn = 1;
            for(int i = 0;i<b-1;i++){
                turn?ans+=sb:ans+=sb2;
                turn = !turn;
            }
            if(b-1>0)
                ans  = sb2+ans;
            for(int i = 0;i<c;i++)
                ans+=sc;

            cout<<ans[0]<<ans[1];
            for(int i =3;i<ans.size();i+=2)
                cout<<ans[i];
        }
        cout<<endl;
    }
    return 0;
}
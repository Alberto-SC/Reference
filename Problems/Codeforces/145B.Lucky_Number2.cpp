#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,a,b,c,d;
    cin>>a>>b>>c>>d;
    if(abs(c-d)>1)return cout<<-1<<endl,0;
    int cont4 = 0,cont7 = 0;
    string s;
    if(c>d){
        for(int i = 0;i<c;i++){
            s+="47";
            cont4++;
            cont7++;
        }
    }
    if(c<d){
        for(int i = 0;i<d;i++){
            s+="74";
            cont4++;
            cont7++;
        }
    }
    else if(c == d){
        if(a>c){
            for(int i = 0;i<c;i++){
                s+="47";
                cont4++;
                cont7++;
            }
            cont4++;
            s+="4";
        }
        else {
            for(int i = 0;i<c;i++){
                s+="74";
                cont4++;
                cont7++;
            }
            cont7++;
            s+="7";
        }
        
    }
    // cout<<s<<endl;
    if(cont4>a)return cout<<-1<<endl,0;
    if(cont7>b)return cout<<-1<<endl,0;
    string ans = s;
    if(a-cont4){
        string s4 = string(a-cont4,'4');
        for(int i = 0;i<s.size();i++){
            if(s[i]== '4'){
                ans = s.substr(0,i)+s4+s.substr(i);
                break;
            }
        }
    }
    string ans2 = ans;
    if(b-cont7){
        string s7 = string(b-cont7,'7');
        for(int j = ans.size();j>=0;j--){
            if(ans[j]== '7'){
                ans2 = ans.substr(0,j)+s7+ans.substr(j);
                break;
            }
        }
    }
    cout<<ans2<<endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
int main(){
    string s,t;
    cin>>s>>t;
    vector<int> needa(26);
    vector<int> needA(26);
    vector<int> hadA(26);
    vector<int> hada(26);
    for(int i = 0;i<s.size();i++){
        if(s[i]>='a'&& s[i]<='z')needa[s[i]-'a']++;
        else needA[s[i]-'A']++;
    }
    for(int i = 0;i<t.size();i++){
        if(t[i]>='a'&& t[i]<='z')hada[t[i]-'a']++;
        else hadA[t[i]-'A']++;
    }
    int yei = 0,whoops = 0;
    for(int i = 0;i<26;i++){
        if(needA[i]>0){
            int how =min(needA[i],hadA[i]);
            yei+=how;
            needA[i]-=how;
            hadA[i]-=how;
        }
        if(needa[i]>0){
            int how =min(needa[i],hada[i]);
            yei+=how;
            needa[i]-=how;
            hada[i]-=how;
        }
        if(needA[i]>0 && needa[i]>0)continue;
        else if(needA[i]>0)whoops+=min(hada[i],needA[i]);
        else if(needa[i]>0)whoops+=min(hadA[i],needa[i]);
    }
    cout<<yei<<" "<<whoops<<endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){

        string s;
        cin>>s;
        int i = 0,j,count = 0;
        for(i = 0;i<s.size();i++)
            if(s[i]== '1')break;
        for(j = s.size()-1;j>=0;j--)
            if(s[j] == '1')break;
        for(int k = i;k<j;k++)
            if(s[k] == '0')count++;
        cout<<count<<endl;
    }
    return 0;
}  
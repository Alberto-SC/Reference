#include <bits/stdc++.h>
using namespace std;
int main(){
    string a,b;
    cin>>a>>b;
    if(a.size()!= b.size())cout<<"NO";
    else{
        for(int i = 0;i<a.size();i++){
            if( ((a[i]== 'a'|| a[i] == 'e'|| a[i] == 'i' || a[i]== 'o'|| a[i] == 'u')&& (b[i]== 'a'|| b[i] == 'e'|| b[i] == 'i' || b[i]== 'o'|| b[i] == 'u') ) )continue;
            else if((a[i]!= 'a'&& a[i] != 'e'&& a[i] != 'i' && a[i]!= 'o'&& a[i] != 'u'&& b[i]!= 'a' && b[i] != 'e'&& b[i] != 'i' && b[i]!= 'o'&& b[i] != 'u') ) continue;
            else{cout<<"NO"; return 0;}
        }
        cout<<"YES";
    }
    return 0;
}
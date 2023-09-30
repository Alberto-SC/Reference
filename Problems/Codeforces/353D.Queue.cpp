#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    string s;
    cin>>s;
    n = s.size();
    int last = -1,pos,final = 0;
    for(int i = 0;i<n;i++){ 
        if(s[i]=='F'){
            if(last==-1)
                last=i;
            else
                last=max(i-final,last==0?0:last+1);
            pos=i;
            final++;
        }
    }
    if(last == -1)cout<<0<<endl;
    else cout<<last<<endl;
    return 0;
}
 
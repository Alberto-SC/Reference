#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,p;
    cin>>n>>p;
    string s;
    cin>>s;
    if(n == 1 && p == 1)return cout<<"NO"<<endl,0;  
    bool flag = false;
    for(int j = s[n-1]-'a'+1;j<p;j++){    
        flag = true;
        if(n-2>=0 && char(j+'a')== s[n-2])flag = false;
        if(n-3>=0 && char(j+'a')== s[n-3])flag = false;
        if(flag){s[n-1] = char(j+'a');break;}
    }
    if(flag)cout<<s<<endl;
    else {
        if(n == 1)return cout<<"NO"<<endl,0;
        flag = false;
        for(int j = s[n-2]-'a'+1;j<p;j++){    
            flag = true;
            if(n-3>=0 && char(j+'a')== s[n-3])flag = false;
            if(n-4>=0 && char(j+'a')== s[n-4])flag = false;
            if(n-1>=0 && char(j+'a')== s[n-1])flag = false;
            if(flag){s[n-2] = char(j+'a');break;}
        }
        if(flag)cout<<s<<endl;
        else{
            int idx = n-1;
            while(idx-1>=0 && s[idx]<s[idx-1]){
                idx--;
            }
            if(idx== 0)return cout<<"NO"<<endl,0;
            s[idx-1] = s[idx];
            flag = false;
            for(int j =0;j<p;j++){
                flag = true;    
                if(idx-1>=0 && char(j+'a')== s[idx-1])flag = false;
                if(idx-2>=0 && char(j+'a')== s[idx-2])flag = false;
                if(idx+1<n && char(j+'a')== s[idx+1])flag = false;
                if(idx+2<n && char(j+'a')== s[idx+2])flag = false;
                if(flag){s[idx] = char(j+'a');break;}
            }
            flag = true;    
            if(idx-2>=0 && s[idx-1]== s[idx-2])flag = false;
            if(idx-3>=0 && s[idx-1]== s[idx-3])flag = false;
            if(idx<n && s[idx-1]== s[idx])flag = false;
            if(idx+1<n && s[idx-1]== s[idx+1])flag = false;
            if(!flag)cout<<"NO"<<endl;
            else {
                for(int i = idx+1;i<n;i++){
                   for(int j = 0;j<p;j++){
                       flag = true;
                       if(i-1>=0 && char(j+'a')== s[i-1])flag = false;
                       if(i-2>=0 && char(j+'a')== s[i-2])flag = false;
                       if(flag){s[i] = char(j+'a');break;}
                   }
                }
                   cout<<s<<endl;
            }
        }

    }
    return 0;
}
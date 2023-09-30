#include <bits/stdc++.h>
using namespace std;
int main(){ 
    string x;
    vector<string> ss;
    while(cin>>x){
        ss.push_back(x);
    }
    int mx = 0;
    vector<int> v;
    vector<bool> b(127*8+1);
    for(auto s:ss){
        int l = 0,r = 127;
        for(int i = 0;i<7;i++){
            if(s[i]== 'F')
                r = (l+r)>>1;
            else
                l = (l+r)>>1;
        }

        int cl = 0,cr = 7;
        for(int i = 0;i<3;i++){
            if(s[7+i]== 'R')
                cl = (cl+cr)>>1;
            else
                cr = (cl+cr)>>1;
        }
        b[(r*8)+cr] = true;
        mx = max((r*8)+cr,mx);
        cout<<(r*8)+cr<<endl;
        // cout<<l<<" "<<r<<" "<<cl<<" "<<cr<<endl;
    }
    cout<<mx<<endl;
    for(int i = 2;i<=127*8;i++){
        if(b[i-1] && b[i+1] && !b[i]){cout<<i<<endl;break;}
    }
    return 0;
}

182

 107 108


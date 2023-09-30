#include <bits/stdc++.h>
using namespace std;
int main(){
    string a,b,c;
    cin>>a>>b>>c;
    vector<int>m(10,0),p(10,0),s(10,0);
    if(a[1] == 'm')m[a[0]-'0']++;
    else if(a[1] == 'p')p[a[0]-'0']++;
    else if(a[1] == 's')s[a[0]-'0']++;
    if(b[1] == 'm')m[b[0]-'0']++;
    else if(b[1] == 'p')p[b[0]-'0']++;
    else if(b[1] == 's')s[b[0]-'0']++;
    if(c[1] == 'm')m[c[0]-'0']++;
    else if(c[1] == 'p')p[c[0]-'0']++;
    else if(c[1] == 's')s[c[0]-'0']++;
    int mn = 50;
    for(int i = 0;i<10;i++){
        if(m[i]==3||p[i]==3||s[i]== 3){mn =min(mn,0); }
        else if(m[i]==2||p[i]==2||s[i]==2){
            if(i-1>=0 && i+1<10 && 
            ((m[i]>0 && m[i-1]>0 && m[i+1]>0)||
            (p[i]>0 && p[i-1]>0 && p[i+1]>0)||
            (s[i]>0 && s[i-1]>0 && s[i+1]>0))){
                cout<<0<<endl; return 0;}

            else if(i-1>=0 && i+1<10 && i+2<10 &&i-2>=0&&
            ((m[i]>0 && (m[i-1]>0  || m[i+1]>0 || m[i+2]>0 ||m[i-2]>0))
            ||(p[i]>0 && (p[i-1]>0 || p[i+1]>0 || p[i+2]>0 ||p[i-2]>0))
            ||(s[i]>0 && (s[i-1]>0 || s[i+1]>0 || s[i+2]>0 ||s[i-2]>0)))){mn =min(mn,1);}
            
            else {cout<<1<<endl;return 0;}
        }
        else if(m[i]==1||p[i]==1||s[i]==1){
            if(i-1>=0 && i+1<10 &&
            ((m[i]>0 && m[i-1]>0 && m[i+1]>0)
            ||(p[i]>0 && p[i-1]>0 && p[i+1]>0)
            ||(s[i]>0 && s[i-1]>0 && s[i+1]>0))){mn =min(mn,0);}
            
            else if(i-1>=0 && i+1<10 && i+2<10 && i-2>=0&&
            ((m[i]>0 && (m[i-1]>0  || m[i+1]>0 || m[i+2]>0 || m[i-2]>0))
            ||(p[i]>0 && (p[i-1]>0 || p[i+1]>0 || p[i+2]>0 || p[i-2]>0))
            ||(s[i]>0 && (s[i-1]>0 || s[i+1]>0 || s[i+2]>0 || s[i-2]>0)))){mn =min(mn,1);}

            else{mn =min(mn,2);}
        }
    }
    cout<<mn<<endl;
    return 0;
}
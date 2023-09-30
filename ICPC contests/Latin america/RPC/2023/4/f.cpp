#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ld long double
signed main(){__
    string s,t;
    cin>>s>>t;
    ld s1 = 0,s2 = 0;
    int n = s.size();
    int m = t.size();
    
    string sa,ta;

    if(s.size()>=2){
        sa = s.substr(n-2);
        if(sa == "NE")
            s1= 45;
        else if(sa == "SE")
            s1 = 135;
        else if(sa == "SW")
            s1 = 225;
        else if(sa == "NW")
            s1 = 315;
    }
    else{
        if(s == "N")
            s1 = 0;
        else if(s == "S")
            s1 = 180;
        else if(s == "E")
            s1 = 90;
        else if(s == "W")
            s1 = 270;
    }

    if(t.size()>=2){
        ta = t.substr(m-2);
        if(ta == "NE")
            s2= 45;
        else if(ta == "SE")
            s2 = 135;
        else if(ta == "SW")
            s2 = 225;
        else if(ta == "NW")
            s2 = 315;
    }
    else{
        if(t == "N")
            s2 = 0;
        else if(t == "S")
            s2 = 180;
        else if(t == "E")
            s2 = 90;
        else if(t == "W")
            s2 = 270;
    }

 
    ld x = 22.5;
    map<string,int> mp = {{"N",0},{"NE",1},{"E",2},{"SE",3},{"S",4},{"SW",5},{"W",6},{"NW",7}};

    for(int i = s.size()-3;i>=0;i--){
        if(mp[string(1,s[i])] < mp[sa])
            s1-=x;
        else 
            s1+=x;
        x/=2;
    }

    x = 22.5;
    for(int i = t.size()-3;i>=0;i--){
        if(mp[string(1,t[i])] < mp[ta])
            s2-=x;
        else 
            s2+=x;
        x/=2;
    }    

    if(s1>s2)swap(s1,s2);
    ld ans = min(s2-s1,360+s1-s2);

    cout<<fixed<<setprecision(10)<<ans<<endl;
    
    return 0;
}


#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
bool isLeap(int y){
    if(y%4 == 0 && y%100)return true;
    if(y%4 == 0 && y%400==0)return true;
    return false;
}
vector<int> M = {0,31,28,31,30,31,30,31,31,30,31,30,31}; 

int getDays(int y,int m,int d){
    int days = 0;
    int years = y-1900;
    days+= years*365;
    y--;
    int last4 = y-(y%4);
    if(last4>=1904)
        days+=((last4-1904)/4)+1;
    int last100 = y-(y%100);
    if(last100>=2000)
        days-=((last100-2000)/100)+1;
    int last400 = y-(y%400);
    if(last400>=2000)
        days+=((last400-2000)/400)+1;

    if(isLeap(y+1))M[2] = 29;
    else M[2] = 28;

    for(int i = 0;i<m;i++)
        days+=M[i];
    days+=d;
    return days;
}



signed main(){__
    int t;
    cin>>t;
    while(t--){
        int y1,y2,m1,m2,d1,d2; 
        cin>>y1>>m1>>d1;
        cin>>y2>>m2>>d2;
        int fd = getDays(y1,m1,d1)-1;
        int ed = getDays(y2,m2,d2)-1;
        int currenday = fd%7;
        bool leap = isLeap(y1);
        if(leap)M[2] = 29;
        else M[2] = 28;
        int ans = 0;
        while(fd<=ed){
            if(d1==1 && currenday==6)
                ans++;
            
            d1++;
            currenday++;
            currenday%=7;
            fd++;
            if(d1>M[m1]){
                d1 = 1;
                m1++;
            }
            if(m1>12){
                m1 =1;
                y1++;
                leap = isLeap(y1);
                if(leap)M[2] = 29;
                else M[2] = 28;

            }
        }
        cout<<ans<<endl; 
        
    }
    
    return 0;
}

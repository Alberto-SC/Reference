#include <bits/stdc++.h>
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define endl '\n'

using namespace std;

signed main(){__
    int T;
    cin>>T;
    while(T--){
        int n,m,x0,y0,x1,y1;
        string d;
        cin>>n>>m>>x0>>y0>>x1>>y1>>d;
        x0--,y0--,x1--,y1--; 

        int ans = 0;
        bool flag = false;


        int mx = (n*2 )+ (m*2)+100;
        while(mx--){
            int Ax = x0-x1;
            int Ay = y0-y1;
                

            /* cout<<x0<<" "<<y0<<" "<<d<<endl; */

            if(d == "DL"){
                if(Ax<=0 && Ay>=0 && abs(Ax)== abs(Ay)){
                    flag = true;
                    break;
                }    
                int dx = n-1-x0;
                int dy = y0;
                int mv = min(dx,dy);
                x0 += mv;
                y0 -= mv;

            }
            else if(d == "DR"){
                if(Ax<=0 && Ay<=0 && abs(Ax)== abs(Ay)){
                    flag = true;
                    break;
                }    
                int dx = n-1-x0;
                int dy = m-1-y0;
                int mv = min(dx,dy);
                x0 += mv;
                y0 += mv;

            }
            else if(d == "UL"){
                if(Ax>= 0 && Ay>=0 && abs(Ax)== abs(Ay)){
                    flag = true;
                    break;
                }    
                int dx = x0;
                int dy = y0;
                int mv = min(dx,dy);
                x0 -= mv;
                y0 -= mv;

            }
            else if(d == "UR"){
                if(Ax>=0 && Ay<=0 && abs(Ax)== abs(Ay)){
                    flag = true;
                    break;
                }    
                int dx = x0;
                int dy = m-1-y0;
                int mv = min(dx,dy);
                x0 -= mv;
                y0 += mv;
            }

            if(y0 == m-1 || y0 == 0){
                if(d[1]=='L')d[1] = 'R';
                else d[1] = 'L';
            }
            if(x0 == n-1 || x0 == 0){
                if(d[0]=='D')d[0] = 'U';
                else d[0] = 'D';
            }

            if(x0 == 0 && y0 == 0)
                d = "DR";
            else if (x0 == 0 && y0 == m-1)
                d = "DL";
            else if (x0 == n-1 && y0 == 0)
                d = "UR";
            else if (x0 == n-1 && y0 == m-1)
                d = "UL";

            ans++;
        }
        if(flag)
            cout<<ans<<endl;
        else cout<<-1<<endl;

    }
    return 0;
}


#include <bits/stdc++.h>
#define print(A)for(auto c:A)cout<<c<<" ";
#define printM(A)for(auto c:A){print(c);cout<<"\n";}
using namespace std;
int main(){
    int t,n,x,y,f1,f2,f3,f4;
    cin>>t;
    while(t--){
        cin>>n;
        int xtarget,xtarget2,ytarget,ytarget2;
        vector<vector<int>>robot(n);
        bool yes = false;
        for(int i = 0;i<n;i++){ 
            cin>>x>>y>>f1>>f2>>f3>>f4;
            robot[i].push_back(x);
            robot[i].push_back(y);
            robot[i].push_back(f1);
            robot[i].push_back(f2);
            robot[i].push_back(f3);
            robot[i].push_back(f4);
        }
        for(int i = 0;i<n;i++){
            if(robot[i][2] == 0){
                xtarget = robot[i][0];
                yes = true;
                break;
            }
        }
        if(yes){
            for(int i = 0;i<n;i++)
                if(robot[i][2] == 0)
                    xtarget = max(robot[i][0],xtarget);
            
        }
        else xtarget = -100000;
        yes = false;
        for(int i = 0;i<n;i++){
            if(robot[i][4] == 0){
                xtarget2= robot[i][0];
                yes = true;
                break;
            }
        }
        if(yes){
            for(int i = 0;i<n;i++)
                if(robot[i][4] == 0)
                    xtarget2 = min(robot[i][0],xtarget2);
            
        }
        else xtarget2 = 100000;
        if(xtarget2<xtarget)cout<<0<<"\n";


        else{
            for(int i = 0;i<n;i++){
                if(robot[i][3] == 0){
                    ytarget = robot[i][1];
                    yes = true;
                    break;
                }
            }
            if(yes){
                for(int i = 0;i<n;i++)
                    if(robot[i][3] == 0)
                        ytarget = min(robot[i][1],ytarget);
                
            }else ytarget = 100000;

            yes = false;
            for(int i = 0;i<n;i++){
                if(robot[i][5] == 0){
                    ytarget2 = robot[i][1];
                    yes = true;
                    break;
                }
            }
            if(yes){
                for(int i = 0;i<n;i++)
                    if(robot[i][5] == 0)
                        ytarget2 = max(robot[i][1],ytarget2);
                
            }
            else ytarget2 = -100000;
            if(ytarget2>ytarget)cout<<0<<"\n";
            else cout<<1<<" "<<xtarget<<" "<<ytarget<<"\n";
        }
    }
    return 0;
}
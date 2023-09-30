#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,k,p1,p2;
    string m1,m2;
    while(1){
        cin>>n;
        if(!n)break;
        cin>>k;
        vector<pair<int,int>> p(n,{0,0});
        for(int i = 0;i<(n*k*(n-1))/2;i++){
            cin>>p1>>m1>>p2>>m2;
            if(m2 == "paper"&& m1 == "rock")p[p2-1].first++,p[p1-1].second++;
            else if(m2 == "paper" && m1 == "scissors")p[p2-1].second++,p[p1-1].first++;
            else if(m2 == "rock" && m1 == "scissors")p[p2-1].first++,p[p1-1].second++;
            else if(m2 == "rock" && m1 == "paper")p[p2-1].second++,p[p1-1].first++;
            else if(m2 == "scissors" && m1 == "paper")p[p2-1].first++,p[p1-1].second++;
            else if(m2 == "scissors" && m1 == "rock")p[p2-1].second++,p[p1-1].first++;
        }
        double r;
        cout<<fixed<<setprecision(3);
        if(n == 1)cout<<"-\n";
        else{
            for(int i = 0;i<n;i++){
                if(p[i].first+p[i].second == 0){cout<<"-\n";continue;}
                r = (1.0*p[i].first)/(p[i].first+p[i].second);
                cout<<r<<endl;
            }
        }
        cout<<endl;
    }
    return 0;
}
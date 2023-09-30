#include <bits/stdc++.h>
using namespace std;
vector<int> days = {31,28,31,30,31,30,31,31,30,31,30,31};
int getday(int m,int d){
    int day = 0;
    for(int i = 0;i<m-1;i++)
        day+=days[i];
    return day+=d;
}
void  getDate(int d){
    string Date = "";
    for(int i =0;i<10;i++){
        d-=days[i];
        if(d == 0){
            if(i+1>=10)cout<<i+1<<"-"<<days[i]<<endl;
            else cout<<"0"<<i+1<<"-"<<days[i]<<endl;
            i = 11;
        }
        else if(d<0){
            d+=days[i];
            if(i+1>=10)cout<<i+1<<"-";
            else cout<<"0"<<i+1<<"-";
            if(d>=10)cout<<d<<endl;
            else cout<<"0"<<d<<endl;
            i = 11;
        }
    }
}
int main() {
    int n,m,d;
    string s;
    cin>>n;
    vector<int> dates;
    for(int i = 0;i<n;i++){
        cin>>s;
        scanf("%d-%d",&m,&d);
        int day = getday(m,d);
        dates.push_back(day);
    }
    int dateact = getday(10,27);
    sort(dates.begin(),dates.end());
    for(auto c:dates)cout<<c<<" ";
    cout<<endl;
    int max = -1;
    vector<int> sol;
    int distmin = 1000;
    int sm = 1000,ss;
    for(int i = 0;i<n;i++){
        int sp;
        cout<<"DATES : "<<dates[i]<<"   ";
        getDate(max);cout<<endl;
        if(i == n-1){
            sp = 365-dates[i]+ dates[0];
            if(sp> max) {
                if(dates[0]==1){
                    max = 365;
                    sol.push_back(max);
                }
                else{
                    max = dates[0]-1;
                }
                     int dist;
        if(max<dateact){
            dist = 365-dateact+max;
            if(dist<sm&& dist>0){sm = dist;ss = max;}
        }
        else{
            dist = max-dateact;
            if(dist<sm&& dist>0){sm = dist;ss = max;}
        }
            }
        }
        else{
            sp = dates[i+1]-dates[i];
            if(sp>= max){
                max = dates[i+1]-1;
            }
                 int dist;
        if(max<dateact){
            dist = 365-dateact+max;
            if(dist<sm&& dist>0){sm = dist;ss = max;}
        }
        else{
            dist = max-dateact;
            if(dist<sm&& dist>0){sm = dist;ss = max;}
        }
        }
        cout<<"SOL: "<<max<<"   ";
        getDate(max);cout<<endl;
    }

    getDate(ss);
    return 0;
}
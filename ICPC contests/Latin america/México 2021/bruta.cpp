#include <bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define int long long 
#define endl '\n'

map<string,int> D= {{"Mon",0}, {"Tue",1}, {"Wed",2}, {"Thu",3}, {"Fri",4}, {"Sat",5},{"Sun",6}};



signed main(){
    int n;
    string s;
    cin>>s;
    cin>>n;
    vector<int> days(n);
    for(auto &c:days)cin>>c;
    int mx = *max_element(days.begin(),days.end());
    vector<int> number_of_day(n);
    int x = (((D[s]-mx)%7)+7)%7;

    for(int i = 0;i<n;i++){
        number_of_day[i] = x+1+(mx-days[i]);
    }
    int currentDay = x+1+mx;
    int ans = 1e15;
    vector<int> DS[5];
    for(int i = 0;i<n;i++){
        int day = number_of_day[i];
        do{
            day+=30; 
            if(day%7==6)day+=2;
            if(day%7==0)day++;

        }while(day<currentDay);
        ans = min(ans,day-currentDay);
    }
    cout<<ans<<endl;
    return 0;
}
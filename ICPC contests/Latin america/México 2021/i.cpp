#include <bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define int long long 
#define endl '\n'

map<string,int> D= {{"Mon",0}, {"Tue",1}, {"Wed",2}, {"Thu",3}, {"Fri",4}, {"Sat",5},{"Sun",6}};

int currentDay;
int processMon(int day){
    int dist = currentDay-day;
    int x = dist/91;
    day +=x*91;
    if(day>=currentDay)return day-currentDay;
    day+=30;
    if(day>=currentDay)return day-currentDay;
    day+=30;
    if(day>=currentDay)return day-currentDay;
    day+=31;
    if(day>=currentDay)return day-currentDay;
    return -1;
}
int processTue(int day){
    int next = day+30;
    if(next>=currentDay)return next-currentDay;
    next+=32;
    if(next>=currentDay)return next-currentDay;
    return processMon(next);
}
int processWed(int day){
    int next = day+30;
    if(next>=currentDay)return next-currentDay;
    next+=31;
    if(next>=currentDay)return next-currentDay;
    return processMon(next);
}
int processThu(int day){
    int next = day+32;
    if(next>=currentDay)return next-currentDay;
    return processMon(next);
}
int processFri(int day){
    int next = day+31;
    if(next>=currentDay)return next-currentDay;
    return processMon(next);
}

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
    currentDay = x+1+mx;
    int ans = 1e15;
    vector<int> DS[5];
    for(int i = 0;i<n;i++){
        if(number_of_day[i]%7== 1){
            if(days[i]==0 && s == "Mon")ans = min(ans,30ll);
            else ans = min(processMon(number_of_day[i]),ans);
        }
        if(number_of_day[i]%7== 2)
            ans = min(processTue(number_of_day[i]),ans);
        if(number_of_day[i]%7== 3)
            ans = min(processWed(number_of_day[i]),ans);
        if(number_of_day[i]%7== 4)
            ans = min(processThu(number_of_day[i]),ans);
        if(number_of_day[i]%7== 5)
            ans = min(processFri(number_of_day[i]),ans);  
        // cout<<i<<" "<<ans<<" "<<days[i]<<" "<<number_of_day[i]<<endl;
    }
    cout<<ans<<endl;
    return 0;
}
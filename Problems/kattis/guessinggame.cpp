#include <bits/stdc++.h>
using namespace std;
int main(){
    string s,s1;
    int n;
    vector<int> nums(10+1,-1);
    while(1){
        cin>>n;
        if(n == 0)break;
        cin>>s1>>s;
        int high = 100,low = -1;
        if(s1 != "right"){
            if(s =="high")high = min(high,n);
            else low = max(low,n);
            while(1){
                cin>>n>>s1>>s;
                if(s1!="right"){
                    if(s == "high")high = min(high,n);
                    else low = max(low,n);
                }
                else{
                    if(n<high&& n>low && low<high)cout<<"Stan may be honest"<<endl;
                    else cout<<"Stan is dishonest"<<endl;
                    break;
                }
            }
        }
        else 
            cout<<"Stan may be honest"<<endl;
    }
    return 0;
}
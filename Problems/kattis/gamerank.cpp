#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    int n = s.size(),consecutive = 0,rank = 25,stars = 0;
    for(int i = 0;i<n;i++){
        if(s[i] == 'W'){
            stars++;
            if(rank>=6)consecutive++;
            else consecutive = 0;
            if(consecutive>=3)stars++;
            if(rank>=21&& rank<=25&& stars>2)stars -= 2,rank--;
            else if(rank>=16&& rank<=20&& stars>3)stars -= 3,rank--;
            else if(rank>=11&& rank<=15&& stars>4)stars -= 4,rank--;
            else if(rank>=1&& rank<=10&& stars>5)stars -= 5,rank--;
        }
        else{
            consecutive = 0;
            if(rank<=20){
            stars--;
            if(stars==-1){
                if(rank == 20)stars = 0;
                else{
                    rank++;
                    if(rank>=16&& rank<=20 )stars = 2;
                    else if(rank>=11&& rank<=15)stars = 3;
                    else if(rank>=1&& rank<=10)stars = 4;
                }
            }
            }
        } 
        if(rank == 0)return cout<<"Legend"<<endl,0;
            // cout<<stars<<" "<<rank<<"  "<<consecutive<<" "<<s[i]<<endl;
    }
    cout<<rank<<endl;
    return 0;
}
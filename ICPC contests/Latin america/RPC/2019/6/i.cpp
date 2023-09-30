#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long n,sum = 1,zeros = 1,unos = 1,a;
    while(cin>>n){
        sum = 1;
        zeros = 1;
        unos = 1;
        bool no = false;
        while(sum%n!= 0){
            if(zeros>=100000){
                no = true;
                break;
            }
            a = 1;
            for(int i = 0;i<zeros;i++){ 
                a*=10%n;
            }
            a%=n;
            sum+=a;
            zeros++;
            unos++;
        }
        if(no)cout<<-1<<endl;
        else
        cout<<unos<<endl;
    }
    return 0;
}
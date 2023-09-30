#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'
#define ld double

const ld ERROR = 1e-9;

#define EQ(a, b) (fabs((a) - (b)) < ERROR)

int get10(int x){
    return pow(10,floor(log10(x)));
}
int getNext10(int x){
    return pow(10,ceil(log10(x)));
}
int N = 100000000;

signed main(){
    ld x;
    cin>>x;
    cout<<fixed<<setprecision(4);
    int i = ceil(10/x);
    if(i==1){return cout<<99999991<<endl,0;}
    ld current = i*x;
    int cont = 0;

    while(i*x<=N){
        if(floor(i*x)!= ceil(i*x)){
            i++;
            continue;
        }
        int first = i/get10(i);
        // int second = ((i*10)/get10(i))%10;
        // if(second<first){
            // i++;
            // continue;
        // }

        if(first*x>=10){
            i = getNext10(i);
        }
        int y = (i*10) +(i/get10(i));
        y-=first*get10(y);
        // cout<<i<<" "<<y<<" "<<current<<endl;
        if(y>i && EQ(i*x,y)){
            cont++;
            cout<<i<<endl;
        }
        i++;
    }
    if(cont==0)cout<<"No solution"<<endl;
    // cout<<cont<<endl;

}  

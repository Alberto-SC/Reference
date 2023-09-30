#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,check,x0,xi,left,right;
    cin>>n>>x0;
    if(n==1){
        cout<<0;
        return 0;
    }
    vector<int> coord(n);
    for(int i = 0;i<n;i++)
        cin>>coord[i];
    
    sort(coord.begin(),coord.end());
    if(x0 >= coord[n-1])
        cout<<abs(x0-coord[1]);
    else if(x0 <= coord[0])
        cout<<abs(x0-coord[n-2]);
    else{
        if(x0<=coord[1])
            left= abs(x0-coord[n-1]);
        else{
            int sleft = abs(x0-coord[1]);
            int rem = abs(x0-coord[n-1]);
            left= sleft + rem + min(sleft,rem);
        }

        if(x0>=coord[n-2])
            right=abs(x0-coord[0]);
        else{
            int sright = abs(x0-coord[n-2]);
            int rem = abs(x0-coord[0]);
            right = sright + rem + min(sright,rem);
        }
        cout<<min(left,right);
    }
    


}
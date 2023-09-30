#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);  
    int n; 
    cin>>n;
    long long a;
    long long min = 100000000000,max=-10000000000;
    for(int i =0;i<n;i++){
        cin>>a;
        if(a>max)max =a;
        if(a<min)min =a;
        cout<<min+max<<"\n";
    }
    return 0;
}
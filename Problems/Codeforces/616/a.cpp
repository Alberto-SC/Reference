#include <bits/stdc++.h>
using namespace std;
int main(){
    int t,n;
    string num;
    cin>>t;
    while(t--){
        cin>>n;
        cin>>num;
        int imp = 0;
        for(int i = 0;i<n;i++)if(num[i]&1)imp++;
        int i;
        for(i = n-1;i>=0;i--)if(num[i]&1)break;
        n=i;
        if(i==-1 || imp == 1 ||imp == 0)cout<<-1<<endl;
        else if(imp%2 == 0)cout<<num.substr(0,i+1)<<endl;
        else{
            for(i = 1;i<n;i++)if(num[i]&1)break;
            cout<<num.substr(0,i)<<num.substr(i+1,n-i)<<endl;
        }
    }
    return 0;
}
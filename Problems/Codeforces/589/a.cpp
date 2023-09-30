#include <bits/stdc++.h>
using namespace std;
int main(){
    int l,r;
    cin>>l>>r;
    for(int i = l;i<=r;i++){
        int copy =  i;
        set<int> ss;
        bool flag = true;
        while(copy){
            if(ss.find(copy%10)!= ss.end())flag = false;
            ss.insert(copy%10);
            copy/=10; 
        }
        if(flag)return cout<<i<<"\n",0;
    }
    cout<<-1<<endl;

    return 0;
}
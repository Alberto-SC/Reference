#include <bits/stdc++.h>
using namespace std;
int main(){
    int s,k;
    cin>>s>>k;
    vector<int> fib;
    if(k >32)k =32;
    for(int i = 0;i<k-1;i++)
        fib.push_back(0);
    fib.push_back(1);
    for(int i= k;fib.back()<1000000007;i++){
        int cont = 0,x = 0;
        for(int j = i-1;cont<k;j--){
            cont++;
            x+=fib[j];
        }
        fib.push_back(x);
        // cout<<fib.back()<<endl;
    }
    vector<int> ans;
    while(s){
        int index = lower_bound(fib.begin(),fib.end(),s)-fib.begin();
        if(fib[index] == s){ans.push_back(fib[index]);break;}
        else {
            index--;
            s-=fib[index];
            ans.push_back(fib[index]);
        }
    }
    if(ans.size()==1)cout<<2<<endl<<0<<" "<<ans[0]<<endl;
    else{
        cout<<ans.size()<<endl;
        for(auto c:ans)cout<<c<<" ";
        cout<<endl;
    } 
    
    return 0;
}
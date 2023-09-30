#include <bits/stdc++.h>
using namespace std;
int main(){
    int t,n,d;
    cin>>t;
    while(t--){
        cin>>n>>d;
        int ai,s =0;
        int a[n];
        int pos[n];
        for(int i = 0;i<n;i++){
            cin>>ai;
            a[i]= ai;
            pos[ai]= i+1;
        }
        for(int i = 0;i<n;i++)
            cout<<a[i]<<" ";
        cout<<endl;
        for(int i = 0;i<n;i++){
            if(pos[i]==i+1)continue;
            else{
                if(i+1+d<=n && pos[i+d]==i+1){
                    s++;
                    swap(pos[i+d],pos[i]);
                    swap(a[i+d],a[i]);
                }
                else if(i+1-d>=0 && pos[i-d]==i+1){
                    s++;
                    swap(pos[i-d],pos[i]);
                    swap(a[i-d],a[i]);
                }
                else if(abs(a[i]-(i+1+d)==d)){
                    swap(pos[i],pos[a[i]]);
                    swap(pos[a[i]],pos[i+d]);
                    swap(a[i],a[a[i]]);
                    swap(a[a[i]],a[i+d]);
                    s+=2;
                }else if(abs(a[i]-(i+1-d)==d)){
                    swap(pos[i],pos[a[i]]);
                    swap(pos[a[i]],pos[i-d]);
                    swap(a[i],a[a[i]]);
                    swap(a[a[i]],a      [i-d]);
                    s+=2;
                }
            }
        }
        for(int i = 0;i<n;i++)
            cout<<a[i]<<" ";
        cout<<endl;
        bool yes  = true;
        for(int i = 0;i<n;i++)
            if(a[i]!=i+1)yes = false;
        if(yes)
            cout<<s<<endl;
        else cout<<-1<<endl;    
    }
    return 0;
}
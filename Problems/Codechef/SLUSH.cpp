#include<bits/stdc++.h>
using namespace std;
#define print(a)for(auto c:a)cout<<c<<" ";\
cout<<"\n";
#define printp(a)for(auto c:a)cout<<c.first<<","<<c.second<<"  ";\
cout<<"\n";
int main(){
    int t,n,m,d,f,b,c;
    cin>>t;
    while(t--){
        cin>>n>>m;
        vector<int> fl(m+1);
        vector<int> ans;
        for(int i = 1;i<=m;i++)cin>>fl[i];
        int pr = 0;
        for(int i = 0;i<n;i++){
            cin>>d>>f>>b;
            if(fl[d]>0){
                ans.push_back(d);
                pr+=f;
                fl[d]--;
            }
            else{
                pr+=b;
                int maxc = -1000000;
                int index;
                for(int i = 1;i<=m;i++){
                    if(fl[i]>maxc){
                        maxc = fl[i];
                        index = i;
                    }
                }
                ans.push_back(index);
                fl[index]--;
            }

        }
        cout<<pr<<"\n";
        for(int i = 0;i<ans.size();i++) 
            cout<<ans[i]<<" ";
        cout<<"\n";
    }
    return 0;
}
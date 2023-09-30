#include <bits/stdc++.h>
using namespace std;
#define print(A)for(auto c:A)cout<<c<<" ";
#define printm(A) for(auto c:A){print(c);cout<<"\n";}
int main(){
    int n,m,a,b;
    cin>>n>>m;
    vector<vector<int>> C(n);
    for(int i = 0;i<n;i++){
        C[i].push_back(0);
        C[i].push_back(10000);
    }
    for(int i = 0;i<m;i++){
        cin>>a>>b;
        C[a-1][0]++;
        if(b<a)b+=n;
        if((b-a)<C[a-1][1])C[a-1][1] = b-a;
    }

    for(int i = 0;i<n;i++){
        int ans = 0;
        for(int j = 0;j<n;j++){
            int time = 0;
            if(C[j][0] == 0)continue;
            if(C[j][0] ==1)time = C[j][1];
            else time += ((C[j][0]-1)*n)+C[j][1];
            if(j>=i)time += j-i;
            else time += (j+n)-i;
            //cout<<"I_____"<<i<<"   J_____"<<j<<"  "<<time<<endl;
            ans = max(ans,time);
        }
        cout<<ans<<" ";
    }
    //cout<<endl;
    //printm(C);
    return 0;
}
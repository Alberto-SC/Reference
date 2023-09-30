#include <bits/stdc++.h>
using namespace std;
struct Cup{
    int v;
    int index;
};
bool cmp(Cup a,Cup b){
    return a.v<b.v;
}
int main(){
    int n,j,sol,count;
    double sum;
    cin>>n;
    Cup Cups[n+1];
    sum=0;
    for(int i=1;i<=n;i++){
        cin>>Cups[i].v;
        Cups[i].index=i;
        sum+=double(Cups[i].v);
    }
    sol= int(sum/n);
    if(sol == sum/n){
        count=0;
        for(int i=1;i<=n;i++){
            if(Cups[i].v == sol)
            count+=1;
        }
        if(count==n)
        cout<<"Exemplary pages."<<endl;
        else{
            sort(Cups+1,Cups+n+1,cmp);
            int a = 0;
            for(int i=1;i<=n/2;i++){
                if(((Cups[i].v+Cups[n-i+1].v)/2==sol) && (Cups[i].v!=sol && Cups[n-i+1].v!=sol))
                    a+=1;
            }
            if(a==1){
                for(int i=1;i<=n/2; i++){
                    if(((Cups[i].v+Cups[n-i+1].v)/2==sol) && (Cups[i].v !=sol && Cups[n-i+1].v !=sol)){
                        cout<<(Cups[n-i+1].v-Cups[i].v)/2<<" ml. from cup #"<<Cups[i].index<<" to cup #"<<Cups[n-i+1].index<<'.'<<endl;
                        break;
                    }
                }
            }
            else
            cout<<"Unrecoverable configuration."<<endl;
        }
    }
    else
    cout<<"Unrecoverable configuration."<<endl;
}
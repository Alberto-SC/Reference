#include <bits/stdc++.h>
using namespace std;
int main(){
    long long  n,q,x,y,ans;
    cin>>n>>q;
    // for(int i = 1;i<=n;i++)
    //     for(int j = 1;j<=n;j++)
    //         cout<<i+j<<" \n"[j == n];    
    
    for(int i = 0;i<q;i++){
        cin>>x>>y;
        if(!(n&1)){
            if ((x+y)&1){
                ans = ceil((n*n)/2) +  ((n/2)*(x-1)) + ((x+y) -((((x+1)/2)-1)*2)) /2 ;
                cout<<ans<<endl;
            }
            else{
                ans = ((n/2)*(x-1)) + ((x+y) -((x/2)*2))  /2 ;
                cout<<ans<<endl;
            }
        } 
        else{
            if ((x+y)&1)
                if(x&1){
                    ans = (n*n)/2 + 1 + ( (((x-1)/2)*n/2)  + (((x-1)/2)*((n/2)+1)) )    + ((x+y) -((((x+1)/2)-1)*2)) /2;
                    cout<<ans<<endl;
                }
                
                else{
                    ans = (n*n)/2 + 1 + ( ((x/2)*(n/2))  + ( ((x-1)/2) * ((n/2)+1)) )    + ((x+y) -((((x+1)/2)-1)*2)) /2;
                    cout<<ans<<endl;
                }
                

            else{
                if(x&1){
                    ans =  ((((x-1)/2)*n/2)  + (((x-1)/2)*((n/2)+1)) )    + ((x+y) -((x/2)*2))/2;
                    cout<<ans <<endl;
                }
                else{
                    ans = ((((x-1)/2)*(n/2))  + ( (x/2) * ((n/2)+1)))     + ((x+y) -((x/2)*2))/2;
                    cout<< ans <<endl;
                }

            }
        }
    }

    return 0;
}
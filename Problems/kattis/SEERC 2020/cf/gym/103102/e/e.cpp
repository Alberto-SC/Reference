#include<bits/stdc++.h>
 
using namespace std;
 
int main(){
    int N, res=0;
    cin>>N;
    int dp[N+1][3][3]={0}; //indice - acumulado - peso
    vector<int>nums(N);
    int aux;
    for(int i=1; i<=N; i++){
        cin>>aux;
        nums[i]=aux;
        dp[i][aux%3][0]=1;
        for(int acu=0; acu<3; acu++){
            for(int peso=0; peso<3; peso++){
                int newAcu = (acu+nums[i])%3;
                int newPeso = (peso+nums[i]*acu)%3;
                dp[i][newAcu][newPeso]+=dp[i-1][acu][peso];
            }
        }
        for(int acu=0; acu<3; acu++) //peso 0 mod 3
            res+=dp[i][acu][0];
 
    }
 
    cout<<res<<"\n";
 
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define print(A)for(auto c:A)cout<<c<<" ";cout<<endl;

bool comp(int a,int b){
    return a>b;
}
int main(){
    int q,n,a,x,y,b,k;
    cin>>q;
    while(q--){ 
        cin>>n;
        vector<int> nums(n);
        for(auto &x:nums)cin>>x;
        sort(nums.begin(),nums.end(),comp);
        cin>>x>>a;
        cin>>y>>b;
        cin>>k;
        long long ans   = 0;
        vector<vector<int>> porcent(2,vector<int>(n));
        if(y>x){swap(x,y);swap(a,b);}
        porcent[0][0] = (nums[0]*x)/100;
        porcent[1][0] = (nums[0]*y)/100;
        for(int i = 1;i<n;i++ ){
            porcent[0][i] = ((nums[i]*x)/100)+porcent[0][i-1];
            porcent[1][i] = ((nums[i]*y)/100)+porcent[1][i-1];
        }
        for(int i = 0;i<2;i++)
            for(int j = 0;j<n;j++)
                cout<<porcent[i][j]<<" \n"[j == n-1];
        bool indm = 1;
        if(a>b)
            indm = 0;
        long long sumA = 0,sumB = 0,indA = 1,indB = 1;
        int indsofar = min(a,b);
        while(indA<=n && indsofar<=n && indB<=n){
            if(b<a){
                if(b*indB<=indsofar){
                    cout<<"A"<<endl;
                    indB = indsofar/b;
                    if(indB >n)indB = n;
                    sumB = porcent[!indm][indB-1];
                    cout<<sumB<<endl;
                    if(sumB>=k)break;
                    else{
                        sumA = porcent[indm][indA-1];
                        cout<<sumA<<endl;
                        if(sumA +sumB >= k){
                            indsofar = indA*a;
                            break;
                        }
                    }
                }
                else { 
                    cout<<"H"<<endl;
                    indB = indA;
                    sumB = porcent[!indm][indB-1];
                    if(sumB>=k)break;
                    else{
                        sumA = porcent[indm][indA-1];
                        if(sumA +sumB >= k){
                            indsofar = indA*a;
                            break;
                        }
                    }
                }
                indA++;
            }
            else{
                cout<<"HOLA"<<endl;
                if(a*indA<=indsofar){
                    cout<<"A"<<endl;
                    indA = indsofar/a;
                    if(indA>n)indA = n;
                    sumA = porcent[!indm][indA-1];
                    if(sumA>=k)break;
                    else{
                        sumB = porcent[indm][indB-1];
                        cout<<sumB<<endl;
                        if(sumA +sumB >= k){
                            indsofar = indB*b;
                            break;
                        }
                    }
                }
                else { 
                    indA = indB;
                    sumA = porcent[!indm][indA-1];
                    if(sumA>=k)break;
                    else{
                        sumB = porcent[indm][indB-1];
                        if(sumA +sumB >= k){
                            indsofar = indB*b;
                            break;
                        }
                    }
                }
                indB++;
            }
        }
        cout<<sumA<<" "<<sumB<<endl;
        if(indsofar>=n && sumA+sumB<k)cout<<-1<<endl;
        else 
            cout<<indsofar<<endl;

    }
    return 0;
}
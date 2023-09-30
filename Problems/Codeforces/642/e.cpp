#include <bits/stdc++.h>
using namespace std;
#define print(A) for(auto c:A)cout<<c<<" ";cout<<endl;
int main(){
    int t,n,k;
    cin>>t;
    while(t--){
        cin>>n>>k;
        string s;
        cin>>s;
        int last = -1;
        int first = -1;
        for(int i = 0;i<n;i++){
            if(s[i] == '1'){last = i;break;}
        }
        for(int i = n-1;i>=0;i--){
            if(s[i]== '1'){first = i;break;}
        }
        vector<int> vec(n+1,0);
        for(int i = 0;i<n;i++)
            if(s[i] == '1')vec[i+1]= 1;
        vector<int> ac(n+1,0);
        ac[1] = vec[1];

    
        for(int i = 1;i<=n;i++)ac[i] = ac[i-1]+vec[i];
        // print(vec);
        // print(ac);
        if(last == -1|| last == first)cout<<0<<endl;
        else {
            int mn = 1000000000;
            for(int i = last+1;i<=last+1+k;i++){
                int cont = 0;
                cont = ac[i-1];
                int j= 0;
                for(j = i;j<=n;j+=k){
                    if(j>first+1)cont++;
                    else if(vec[j] == 0){
                        if(j !=  i){
                            int x = ac[j-1]-ac[j-k];
                            cont+= x+1;
                        }
                        else cont++;
                    }
                    else if(vec[j] == 1 && j!=i)cont+=ac[j-1]-ac[j-k];

                if(j>first)break;   
                }
                if(j>n){
                    j-=k;
                    cont+=ac[n]-ac[j];
                }
                mn = min(cont,mn);
            }   
            cout<<mn<<endl;
        }


    }
    return 0;
}
// 1
// 7 3
// 1001010
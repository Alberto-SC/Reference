#include <bits/stdc++.h>
using namespace std;
#define f(a) a.first
#define s(a) a.second
int main(){ 
    pair<int,int> X,Y;
    int t;
    cin>>t;
    while(t--){
        char a,b;
        cin>>a>>b;
        X = {a-'A',b-'0'};
        cin>>a>>b;
        Y = {a-'A',b-'0'};
        // cout<<X.first<<" "<<X.second<<"    "<<Y.first<<" "<<Y.second<<endl;
        if(f(X)+s(X) %2 != f(Y)+s(Y))cout<<"Impossible"<<endl;
        else if(X == Y)cout<<0<<f(X)<<" "<<s(X)<<endl;
        else{
            for(int i = f(X),j = s(X);i>0,j<9;i--,j++){
                if(i == f(Y) && j ==s(Y)){cout<<1<<char(f(X)+'A')<<" "<<s(X)<<" "<<char(f(X)+'A')<<" "<<s(X)<<endl;return 0;}
                for(int k = i,l = j;k<9,l<9;k++,l++){
                    if(k == f(Y) && l ==s(Y)){cout<<1<<char(f(X)+'A')<<" "<<s(X)<<" "<<char(f(X)+'A')<<" "<<s(X)<<endl;return 0;}
                }
                for(int k = i,l = j;k>0,l>0;k--,l--){
                    if(k == f(Y) && l ==s(Y)){cout<<1<<char(f(X)+'A')<<" "<<s(X)<<" "<<char(f(X)+'A')<<" "<<s(X)<<endl;return 0;}
                }
            }
            for(int i = f(X),j = s(X);i>0,j>0;i--,j--){
                if(i == f(Y) && j ==s(Y)){cout<<1<<char(f(X)+'A')<<" "<<s(X)<<" "<<char(f(X)+'A')<<" "<<s(X)<<endl;return 0;}
                for(int k = i,l = j;k<9,l<9;k++,l++){
                    if(k == f(Y) && l ==s(Y)){cout<<1<<char(f(X)+'A')<<" "<<s(X)<<" "<<char(f(X)+'A')<<" "<<s(X)<<endl;return 0;}
                }
                for(int k = i,l = j;k>0,l>0;k--,l--){
                    if(k == f(Y) && l ==s(Y)){cout<<1<<char(f(X)+'A')<<" "<<s(X)<<" "<<char(f(X)+'A')<<" "<<s(X)<<endl;return 0;}
                }
            }
            for(int i = f(X),j = s(X);i<9,j>0;i++,j--){
                if(i == f(Y) && j ==s(Y)){cout<<1<<char(f(X)+'A')<<" "<<s(X)<<" "<<char(f(X)+'A')<<" "<<s(X)<<endl;return 0;}
                for(int k = i,l = j;k<9,l<9;k++,l++){
                    if(k == f(Y) && l ==s(Y)){cout<<1<<char(f(X)+'A')<<" "<<s(X)<<" "<<char(f(X)+'A')<<" "<<s(X)<<endl;return 0;}
                }
                for(int k = i,l = j;k>0,l>0;k--,l--){
                    if(k == f(Y) && l ==s(Y)){cout<<1<<char(f(X)+'A')<<" "<<s(X)<<" "<<char(f(X)+'A')<<" "<<s(X)<<endl;return 0;}
                }
            }
            for(int i = f(X),j = s(X);i<9,j<9;i++,j++){
                if(i == f(Y) && j ==s(Y)){cout<<1<<char(f(X)+'A')<<" "<<s(X)<<" "<<char(f(X)+'A')<<" "<<s(X)<<endl;return 0;}
                for(int k = i,l = j;k<9,l<9;k++,l++){
                    if(k == f(Y) && l ==s(Y)){cout<<1<<char(f(X)+'A')<<" "<<s(X)<<" "<<char(f(X)+'A')<<" "<<s(X)<<endl;return 0;}
                }
                for(int k = i,l = j;k>0,l>0;k--,l--){
                    if(k == f(Y) && l ==s(Y)){cout<<1<<char(f(X)+'A')<<" "<<s(X)<<" "<<char(f(X)+'A')<<" "<<s(X)<<endl;return 0;}
                }
            }
        }
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
int main(){
    int l,r;
    int bucket[10];
    while(cin>>l>>r){
        int cont =0;
        for(int i= l;i<=r;i++){
            int copy =i;
            for(int i =0;i<10;i++)bucket[i]=0;
            bool flag = true;
            while(copy){
                bucket[copy%10]++;
                copy/=10;
            }
            for(int i =0;i<10;i++){if(bucket[i]>1){flag =false;break;}}
            if(flag)cont++;
        }
        cout<<cont<<endl;
    }
    return 0;
}
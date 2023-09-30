#include <bits/stdc++.h>
using namespace std;

int main(){
    int matriz[500][500];
    for(int i = 0;i<500;i++)
        for(int j = 0;j<500;j++)
            matriz[i][j] = rand() % 100;
    for(int i = 0;i<500;i++){
        for(int j = 0;j<500;j++)
            cout<<matriz[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}
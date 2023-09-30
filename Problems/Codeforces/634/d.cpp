#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    int sudoku[9][9];
    while(t--){
        int num;
        for(int i = 0;i<9;i++){
            cin>>num;
            int j = 8;
            while(num){
                sudoku[i][j] = num%10;
                num/=10;
                j--;
            }
        }
        for(int i = 0;i<3;i++){
            for(int j = 0;j<3;j++){
                sudoku[(3*i)+j][(3*j)+i]=sudoku[(3*i)+j][(3*j)+i]+1;
                if(sudoku[(3*i)+j][(3*j)+i]==10)sudoku[(3*i)+j][(3*j)+i] = 1;
            }
        }
        for(int i = 0;i<9;i++){
            for(int j = 0;j<9;j++)
                cout<<sudoku[i][j];
            cout<<endl;
        }
        cout<<endl;
    }
    return 0;
}
// 976834152
// 351927864
// 482156379
// 548719236
// 629385417
// 137642985
// 895263741
// 714598623
// 263471598
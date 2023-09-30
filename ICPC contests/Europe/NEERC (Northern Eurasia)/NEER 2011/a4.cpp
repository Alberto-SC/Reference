#include <bits/stdc++.h>

using namespace std;

int main(){
    int r,c; cin >> r >> c;
    bool isInside = false;
    int borders = 0, dots = 0;
    char mat[r][c];

    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cin >> mat[i][j];
            if(mat[i][j] == '/' || mat[i][j] == '\\'){
                isInside = !isInside;
                borders++;
            }
            if(mat[i][j] == '.' && isInside)
                dots++;
        }
    }

    cout << (borders/2)+dots << endl;

    return 0;
}
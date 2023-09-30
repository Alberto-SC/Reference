#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);


int sudoku[9][9];

bool rule1(int x,int y){
    int sx = x/3;
    int sy = y/3;
    set<int> faltan;
    for(int i = 1;i<=9;i++)
        faltan.insert(i);
    for(int i= 0;i<3;i++){
        for(int j = 0;j<3;j++){
            faltan.erase(sudoku[(sx*3)+i][(sy*3)+j]);
        }
    }
    vector<int> poss;
    for(auto pos:faltan){
        bool flag = true;
        for(int i = 0;i<9;i++){
            if(sudoku[x][i]==pos)flag = false;
        }
        for(int i = 0;i<9;i++){
            if(sudoku[i][y]==pos)flag = false;
        }
        if(flag)poss.push_back(pos);
    }
    if(poss.size()==1){
        sudoku[x][y] = poss[0]; 
        return true;
    }
    return false;
}

bool Can_Place(int r, int c, int val){
    if(sudoku[r][c] != 0)
        return false;
        
    for(int cur_c = 0; cur_c < 9; cur_c++)
        if(sudoku[r][cur_c] == val)
        return false;
    for(int cur_r = 0; cur_r < 9; cur_r++)
        if(sudoku[cur_r][c] == val)
        return false;
    for(int box_r = (r/3)*3; box_r < (r/3)*3 + 3; box_r++)
        for(int box_c = (c/3)*3; box_c < (c/3)*3 + 3; box_c++){
            if(sudoku[box_r][box_c] == val)
            return false;
        }   
    return true;
}

bool rule2(int x,int y,int val){
    if(!Can_Place(x,y,val))return false;
    int sx = x/3;
    int sy = y/3;
    set<int> faltan;
    for(int i = 1;i<=9;i++)
        faltan.insert(i);
    for(int i= 0;i<3;i++){
        for(int j = 0;j<3;j++){
            faltan.erase(sudoku[(sx*3)+i][(sy*3)+j]);
        }
    }
    if(!faltan.count(val))
        return false;
    bool f1 = true;
    for(int i = 0;i<3;i++){
        for(int j = 0;j<3;j++){
            int nx = (sx*3)+i;
            int ny = (sy*3)+j;
            if(x==nx && y ==ny)continue;
            if(sudoku[nx][ny]!=0)continue;
            bool flag = true;
            for(int k = 0;k<9;k++){
                if(sudoku[nx][k]==val)flag = false;
            }
            for(int k = 0;k<9;k++){
                if(sudoku[k][ny]==val)flag = false;
            }
            if(flag)f1 = false;
        }
    }
    if(f1){
        sudoku[x][y] = val;
        return true;
    }
    else {
        bool flagrow = true,flagcolumn=true;
        for(int i = 0;i<9;i++){
            if(i!=x &&Can_Place(i,y,val))flagrow = false;
            if(i!=y &&Can_Place(x,i,val))flagcolumn = false;

        }
        if(flagrow||flagcolumn){
            sudoku[x][y] = val;
            return true;
        }
    }
    return false;
}
signed main(){__
    for(int i = 0;i<9;i++){
        for(int j = 0;j<9;j++){
            cin>>sudoku[i][j];
        }
    }
    while(1){
        bool flag = false;
        for(int i = 0;i<9;i++){
            for(int j = 0;j<9;j++){
                if(sudoku[i][j]==0)
                    if(rule1(i,j))flag = true;
                    else{
                        for(int k = 1;k<=9;k++){
                            if(rule2(i,j,k))flag = true;
                        }
                    }
            }
        }
        if(!flag)break;
    }
    bool easy = true;
    char ans[9][9];
    for(int i = 0;i<9;i++){
        for(int j = 0;j<9;j++){
            if(sudoku[i][j]==0)easy = false,ans[i][j] = '.';
            else ans[i][j] = sudoku[i][j]+'0';
        }
    }
    if(easy)
        cout<<"Easy"<<endl;
    else 
        cout<<"Not easy"<<endl;
    for(int i = 0;i<9;i++)
        for(int j = 0;j<9;j++)
            cout<<ans[i][j]<<" \n"[j==8];
    return 0;
}  

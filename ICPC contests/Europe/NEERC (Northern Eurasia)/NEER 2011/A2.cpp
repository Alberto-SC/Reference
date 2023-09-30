#include <bits/stdc++.h>
using namespace std;

int mv[][] = {{-1,0},{0,-1},{1,0},{0,1},{-1,-1},{1,-1},{1,1},{1,-1}};
int r,c,lines= 0, area;
vector<string> s;

int DFS(int x , int y , bool &borde)
{
    s[y][x] = 'X';
    int ac = 0;
    for(int i = 0 ; i < 8 ; i++)
    {
        int auxX = x+mov[i][0] , auxY = y+mov[i][1];
        if(auxX < 0 || auxY < 0 || auxX >=c || auxY >= r )
        {
            borde = true;
            continue;
        }
        if(s[auxY][auxX] == '.')
        {
            ac += DFS(auxX,auxY,borde);
        }
    }
    if(borde)
        return ac+1;
    else
        return 0;
}

int main(){

    int l = 0;
    cin>>r>>c;
    area = r*c;
    s.assing(r,string());
    for(int i =0;i<r;i++)
    {
        cin >> s[i];
        for(int j = 0 ; j < c ; j++)
        {
            if(s[i][j] == '\\' || s[i][j] == '/')
                lineas++;
        }
    }
    for(int i =0;i<r;i++)
    {
        for(int j = 0; j < s[i].size() ; j++)
        {
            if(s[i][j] == '.')
                area -= DFS(j,i,false);
        }
    }
    cout << area+lineas/2 << '\n';   
    return 0;
}
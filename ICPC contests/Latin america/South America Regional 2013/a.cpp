#include <bits/stdc++.h>
using namespace std;
#define MAX 100
char grid[MAX + 3][MAX+3];
int cols[MAX + 3][MAX + 3];
int fils[MAX + 3][MAX + 3];
int mark[MAX * MAX + 2], vis[ MAX * MAX + 2];
int graph[MAX*MAX/2+1][MAX*MAX/2+1];
int newFil, newCol;
int match(int nodo ){
  int x;
  if( vis[nodo] == 1 ) return 0;
  vis[nodo] = 1;
  for( x = 1; x <= newCol; x++)
    if( graph[nodo][x] == 1 && ( mark[ x ] == -1 || match( mark[ x ])) ){
       mark[x] = nodo;
       return 1;
    }
  return 0;
}

int main(){
    int r, c, cont, x, n;
    while(cin>>n){
        memset( cols, 0, sizeof( cols ) );
        memset( fils, 0, sizeof( fils ) );
        for( x = 1; x <= n; x++) cin>>grid[x]+1;
        newFil = newCol = 0;
        for( r = 1; r <= n; r++){
            for( c = 1; c <= n; c++){
                if(grid[r][c] != 'X'){
                    if(cols[r - 1][c] == 0 ) cols[r - 1][c] = ++newCol;
                    cols[r][c] = cols[r - 1][c];
            }
            }
        }
        for( r = 1; r <= n; r++){
        for( c = 1; c <= n; c++){
            if( grid[r][c] != 'X'){
            if( fils[r][c - 1] == 0 ) fils[r][c - 1] = ++newFil;
            fils[r][c] = fils[r][c - 1];
            }
        }
        }
        memset( graph, 0, sizeof( graph ) );
        for( r = 1; r <= n; r++){
        for( c = 1; c <= n; c++)
            if( grid[r][c] != 'X'){
                graph[fils[r][c]][cols[r][c]] = 1;
            }
        }
        memset( mark, -1, sizeof( mark ) );
        cont = 0;
        for(x=1;x<=newFil;x++){
            memset( vis, 0, sizeof( vis ) );
            if(match(x)) cont++;
        }
        printf("%d\n", cont);
    }
    return 0;
}
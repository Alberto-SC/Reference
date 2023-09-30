/**
 * Author: Alberto Silva
 * Source: Folklore
 * Description: Calculate submatrix sums quickly, given upper-left and lower-right corners (half-open).
 * Usage:
 * prefixSums(matrix);
 * sum2D(0, 0, 2, 2); // top left 4 elements
 * Time: O(N^2 + Q)
 * Status: Tested on Kattis
 */

vector<vector<long long>> sum;

void prefixSums(vector<vector<long long>> M){
    int n = M.size();
    int m = M[0].size();
    sum.assign(n,vector<int> (m,0));
    sum[0][0] = M[0][0];

    for(int i = 1;i<n;i++)
        sum[i][0] = sum[i-1][0]+ M[i][0]; 

    for(int i = 1;i<m;i++)
        sum[0][i] = sum[0][i-1] + M[0][i];

    for(int i = 1;i<n;i++){
        for(int j = 1;j<m;j++){
            sum[i][j] = sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+ M[i][j];
        }
    }
    
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            cout<<sum[i][j]<<" ";
        }
        cout<<endl;
    }
    
}




// Upper left corner and bottom right corner inclusive
int sum2D(int x0,int y0,int x1,int y1){
    int u = 0;
    int d = 0;
    int l = 0;

    if(x0 && y0)d = sum[x0-1][y0-1];
    if(y0) l = sum[x1][y0-1];
    if(x0) u = sum[x0-1][y1];

    return sum[x1][y1]-l-u+d;
}

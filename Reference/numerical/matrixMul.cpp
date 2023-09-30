vector<vector<ld>> mult(vector<vector<ld>> &A,vector<vector<ld>> &B){
    int n = A.size();
    vector<vector<ld>> C(n,vector<ld>(n));
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            for(int k = 0;k<n;k++){
                C[i][j] += (A[i][k] * B[k][j]);
            }
        }
    }
    return C;
}

vector<vector<ld>> pw(vector<vector<ld>> M,int n){
    int N = M.size();
    vector<vector<ld>> X(N,vector<ld> (N));
    
    for(int i = 0;i<N;i++)
        X[i][i] = 1.0;
    
    while(n){
        if(n&1)X = mult(M,X);
        M  = mult(M,M);
        n >>=1;
    }
    return X;
}

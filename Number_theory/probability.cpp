//_______________________COEFICIENTES BINOMIALES_______________//
long binomial_coefficient(int n,int m){
	int i,j;
	long bc[MAXN][MAXN];
	for (i=0; i<=n; i++) bc[i][0] = 1;
	for (j=0; j<=n; j++) bc[j][j] = 1;
	for (i=1; i<=n; i++)
	for (j=1; j<i; j++)
	bc[i][j] = bc[i-1][j-1] + bc[i-1][j];
	return bc[n][m];
}
//______________________COEFICIENTES BINOMIALES o(k)_____________//
int binomialCoeff(int n, int k)  {  
    int res = 1;  
    if ( k > n - k )  
        k = n - k;  
    for (int i = 0; i < k; ++i){  
        res *= (n - i);  
        res /= (i + 1);  
    }  
    return res;  
}
int binomialCoeff(int n, int k){ 
    vector<int> C(k+1,0); 
    C[0] = 1;  // nC0 is 1 
    for (int i = 1; i <= n; i++) { 
        for (int j = min(i, k); j > 0; j--) 
            C[j] = C[j] + C[j-1]; 
    } 
    return C[k]; 
} 
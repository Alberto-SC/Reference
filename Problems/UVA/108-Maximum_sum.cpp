#include <iostream>
using namespace std;
int matriz[101][101];
int main(){
	int n,v,j,k;
	long int sig,mt_c,max_ab,max_sum;
	for(int i = 0;i<101;i++){
		matriz[i][0] = 0;	
	}
	while((cin>>n) && n){

		for(int i = 1;i<=n;i++)
			for(int j = 1;j<=n;j++){
				cin>>v;
				matriz[i][j] = matriz[i][j-1] +v;
			}
		max_sum = matriz[1][1];
        for (j = 1; j <= n; j++)
            for (int i = j; i <= n; i++) {
                mt_c = matriz[1][i] - matriz[1][j-1];
                for (k = 2; k <= n; k++) {
                    sig = matriz[k][i] - matriz[k][j-1];

                    if (mt_c + sig > sig)
                        mt_c = mt_c + sig;
                    else
                        mt_c = sig;
                    if (mt_c > max_sum)
                        max_sum = mt_c;
                }
        	}

        cout << max_sum<< endl;

	}
	return 0;
}
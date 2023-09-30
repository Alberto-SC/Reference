#include <iostream>

using namespace std;


long long pow(long long a, long long n, long long m) {
    long long  resultado = 1;
    for (; n; n >>= 1) {
        if (n & 1) resultado = (resultado * a) % m;
        a = (a * a) % m;
    }
    return resultado;
}

int main(void)
{
	int T = 0;
	cin >> T;
	while(T--)
	{
		long long int N = 0;
		cin >> N;
		long long int X = pow(N, N + 1,1000000007) - (N -1);
		cout << X << endl;
	}	
} 
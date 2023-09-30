
//cout for __int128
ostream &operator<<(ostream &os, const __int128 & value){
	char buffer[64];
	char *pos = end(buffer) - 1;
	*pos = '\0';
	__int128 tmp = value < 0 ? -value : value;
	do{
		--pos;
		*pos = tmp % 10 + '0';
		tmp /= 10;
	}while(tmp != 0);
	if(value < 0){
		--pos;
		*pos = '-';
	}
	return os << pos;
}

//cin for __int128
istream &operator>>(istream &is, __int128 & value){
	char buffer[64];
	is >> buffer;
	char *pos = begin(buffer);
	int sgn = 1;
	value = 0;
	if(*pos == '-'){
		sgn = -1;
		++pos;
	}else if(*pos == '+'){
		++pos;
	}
	while(*pos != '\0'){
		value = (value << 3) + (value << 1) + (*pos - '0');
		++pos;
	}
	value *= sgn;
	return is;
}


//Random number generation in C++11
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

//Generate a random integer in [a, b], you can also use long long int
int aleatorio_int(int a, int b){
	uniform_int_distribution<int> dist(a, b);
	return dist(rng);
}

//Generate a random double in [a, b], you can also use long double
double aleatorio_double(double a, double b){
	uniform_real_distribution<double> dist(a, b);
	return dist(rng);
}
//Read from a file 
freopen("problemname.in", "r", stdin);
// the following line creates/overwrites the output file
freopen("problemname.out", "w", stdout);


int lcs(string & a, string & b){
	int m = a.size(), n = b.size();
	vector<vector<int>> aux(m + 1, vector<int>(n + 1));
	for(int i = 1; i <= m; ++i){
		for(int j = 1; j <= n; ++j){
			if(a[i - 1] == b[j - 1])
				aux[i][j] = 1 + aux[i - 1][j - 1];
			else
				aux[i][j] = max(aux[i - 1][j], aux[i][j - 1]);
		}
	}
	return aux[m][n];
}

//0:saturday, 1:sunday, ..., 6:friday
int dayOfWeek(int d, int m, lli y){
	if(m == 1 || m == 2){
		m += 12;
		--y;
	}
	int k = y % 100;
	lli j = y / 100;
	return (d + 13*(m+1)/5 + k + k/4 + j/4 + 5*j) % 7;
}

int LevenshteinDistance(string & a, string & b){
	int m = a.size(), n = b.size();
	vector<vector<int>> aux(m + 1, vector<int>(n + 1));
	for(int i = 1; i <= m; ++i)
		aux[i][0] = i;
	for(int j = 1; j <= n; ++j)
		aux[0][j] = j;
	for(int j = 1; j <= n; ++j)
		for(int i = 1; i <= m; ++i)
			aux[i][j] = min({aux[i-1][j] + 1, aux[i][j-1] + 1, aux[i-1][j-1] + (a[i-1] != b[j-1])});
	return aux[m][n];
}

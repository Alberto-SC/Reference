#include <bits/stdc++.h>
using namespace std;
#define x first 
#define y second
void B( int m, int n, string str1, string str2, int LL [] ){
	int k [2] [ n + 1 ] ;
    int i, j;
    for ( j = 0 ; j < ( n + 1 ); j++ )
		k [1] [j] = 0 ;
	for ( i = 0 ; i < m ; i++ ){
		for ( j = 0 ; j < ( n + 1 ) ; j++ )
			k [0] [j] = k [1] [j] ;
		for ( j = 1 ; j < ( n + 1 ) ; j++ ){
			if ( str1[ i ] == str2[ j - 1 ] ) {
				k [1] [j] = k [0] [j-1] + 1 ; 
			}
			else{
				k [1] [j] = max( k [1] [j-1] , k [0] [j] ) ;
			}
		}
	}
    for ( j = 0 ; j < ( n + 1 ); j++ )
		LL [j] = k [1] [j] ;
}
string Hirschberg(int m, int n, string str1, string str2, string lcs ){
	if ( m == 1 ){
		int found ;
		found = str2.find_first_of( str1[0] );
		if ( found != string::npos )
			lcs = str1[ 0 ] ;
		else
			lcs = "" ;
			return lcs ;
	}
	int l1[n+1], l2[n+1] ;
	int i = ( int ) ( m / 2 ) ;
	B( i, n, str1.substr( 0, i ), str2, l1 ) ;
	string str1_rev, str2_rev ;
	string::reverse_iterator rev_iter ;
	for ( rev_iter = str1.rbegin() ; rev_iter < str1.rend() ; rev_iter++ )
		str1_rev.push_back( *rev_iter );
	for ( rev_iter = str2.rbegin() ; rev_iter < str2.rend() ; rev_iter++ )
		str2_rev.push_back( *rev_iter );
    B( i + 1 , n, str1_rev.substr( 0, m - i ), str2_rev, l2 ); 
	int max = 0, k = 0 ;
	for ( int j = 0 ; j < ( n + 1 ) ; j++ ){
		if ( ( l1[ j ] + l2[ n - j ] ) > max ){
			max = l1[ j ] + l2[ n - j ] ;
			k = j ;
		}
	}
	string lcs1, lcs2 ;
	if ( i == 0 ) i++ ; 
	return Hirschberg( i, k, str1.substr( 0, i ), str2.substr( 0, k ), lcs1 ).append( Hirschberg( m - i , n - k , str1.substr( i, m ), str2.substr( k, n ), lcs2 ) ) ;
}

int main(){
    string a,b;
    cin>>a>>b;
	string s;
	s = Hirschberg(a.size(),b.size(),a,b,s);
	cout<<s.size()<<endl;
	int k= 0,j = 0;
	for(int i = 0;i<s.size();i++){
		// cout<<"HI"<<endl;
		while(a[k]!= s[i]){k++;}
		while(b[j]!= s[i]){j++;}
		cout<<k<<" "<<j<<endl;
		k++;
		j++;
	}
	// cout<<s<<endl;
	return 0;
}
#include <iostream>
#include <stdio.h>
using namespace std;

inline void getInt(long long  &n)  
{
  n = 0;
  int ch = getchar_unlocked();
  int sign = 1;
 
  while (ch<'0' || ch>'9')  
  {
    if (ch == '-')
    {
      sign = -1;
    }
    ch = getchar_unlocked();
  }
 
  while (ch >= '0' && ch <= '9')
  {
    n = (n << 3) + (n << 1) + ch - '0';  
    ch = getchar_unlocked();
  }
  
  n *= sign;  
}
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
    std::ios::sync_with_stdio(0);
    int i;
    long long sum = -1e15,sumc = 0,n;
    getInt(n);
    long long x;
   	for( i = 0; i<n; i++){
   			getInt(x);
   			sumc+= x;
   			if(sumc >sum)
   				sum = sumc;
   		    if(sumc <0) 
   				sumc = 0;
   			
   			
   	}
   	cout<<sum;
	return 0;
}
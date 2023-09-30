#include <iostream> 
int main(){long long p,k;std::cin>>p>>k;return std::cout<<(k>(p/2)+(p&1)?(k-((p/2)+(p&1)))*2:k*2-1),0;}  


#include <bits/stdc++.h>

using namespace std;
vector<bool> primes(28,false);




int main(){
	primes[3] = true;
	primes[5] = true;
	primes[7] = true;
	primes[11] = true;
	primes[13] = true;
	primes[17] = true;
	primes[19] = true;
	primes[23] = true;
	primes[27] = true;
	int n,t,cont = 1;
	bool y;
	cin>>t;
	while(t--){
		cin>>n;
		cout<<"Case "<<cont<<":"<<endl;
		cont++;

		int P[n/2];
		int In[(n/2)];
		
		for(int i= 2,k = 0;i<=n;i+=2,k++)
			P[k] = i;
		for(int i= 3,k = 0;i<=n;i+=2,k++)
			In[k] = i;

		if(n %2 == 0){
			do{
				for(int i= 3,k = 0;i<=n;i+=2,k++)
						In[k] = i;
				cout<<endl;
				do{
				    y = true;
					for(int i = 0;i<(n/2)-1;i++){	
						if(primes[P[i]+In[i]] && primes[In[i]+P[i+1]] && P[0]!= 8 && P[(n/2)-1] != 8 && P[(n/2)-1] != 14)continue;
						else{y = false;break;} 

					}
					if(y){
						cout<<"1 ";
						for(int i = 0;i<(n/2)-1;i++)
							cout<<P[i]<<" "<<In[i]<<" ";
						cout<<P[(n/2)-1]<<endl;
					}

				}while(next_permutation(In,In+(n/2)-1));
			}while(next_permutation(P,P+(n/2)) && P[0] != 14);
		}

		else{
			do{
				for(int i= 3,k = 0;i<=n;i+=2,k++)
						In[k] = i;
				cout<<endl;
				do{
					bool y = true;
					for(int i = 0;i<n/2;i++){	
						if(i != (n/2)-1){
							if(primes[P[i]+In[i]] && primes[In[i]+P[i+1]]  && P[0]!= 8 && P[(n/2)-1] != 8)continue;
							else{ y = false; break;} ;
						}
						else{
							if(primes[P[i]+In[i]])continue;
							else{  y = false;break;} ;
						}
					}

					if(y){
						cout<<"1 ";
						for(int i = 0;i<(n/2);i++)
							cout<<P[i]<<" "<<In[i]<<" ";
						cout<<endl;
					}

				}while(next_permutation(In,In+(n/2)));
			}while(next_permutation(P,P+(n/2)));
		}


	}

}
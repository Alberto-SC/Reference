#include <bits/stdc++.h>
using namespace std;
int main(){
    string n,t;
    int cont =1;
    while(cin>>n>>t){
        cout<<"Case "<<cont<<": ";
        if(n =="Db")cout<<"C# "<<t<<endl;
        else if(n =="C#")cout<<"Db "<<t<<endl;
        else if(n =="Eb")cout<<"D# "<<t<<endl;
        else if(n =="D#")cout<<"Eb "<<t<<endl;
        else if(n =="F#")cout<<"Gb "<<t<<endl;
        else if(n =="Gb")cout<<"F# "<<t<<endl;
        else if(n =="G#")cout<<"Ab "<<t<<endl;
        else if(n =="Ab")cout<<"G# "<<t<<endl;
        else if(n =="A#")cout<<"Bb "<<t<<endl;
        else if(n =="Bb")cout<<"A# "<<t<<endl;
        else cout<<"UNIQUE"<<endl;
        cont++;
    }
    return 0;
}
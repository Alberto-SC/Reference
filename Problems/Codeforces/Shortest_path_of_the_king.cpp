#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    int  x1,y1,x2,y2;
    char  cx1,cy1,cx2,cy2;
    cin>>cx1>>cy1>>cx2>>cy2;
    x1 = cx1-'a'+1;
    x2 = cx2-'a'+1;
    y1 = cy1-'0';
    y2 = cy2-'0';
    cout<<max(abs(x1-x2),abs(y1-y2))<<endl;
    if(x2<x1){
        if(y2<y1){
            while(y2!= y1 && x1!= x2){
                cout<<"LD"<<endl;
                x1--;
                y1--;
            }
        }
        if(y2>y1){
            while(y2!= y1 && x1 != x2){
                cout<<"LU"<<endl;
                x1--;
                y1++;
            }
        }
    }
    else if(x2>x1){
        if(y2<y1){
            while(y2!= y1 && x1 != x2){
                cout<<"RD"<<endl;
                x1++;
                y1--;
            }
        }
        if(y2>y1){
            while(y2!= y1 && x1 != x2){
                cout<<"RU"<<endl;
                x1++;
                y1++;
            }
        }
    }


    if(x1 == x2){
        if(y1>y2){
            while(y2!= y1){
                y1--;
                cout<<"D"<<endl;
            }
        }
        else if(y2>y1){
            while(y2 != y1){
                cout<<"U"<<endl;
                y1++;
            }
        }
    }
    else if(y1 == y2){
        if(x1>x2){
            while(x2!= x1){
                cout<<"L"<<endl;
                x1--;
            }
        }
        else if(x2>x1){
            while(x2 != x1){
                cout<<"R"<<endl;
                x1++;
            }
        }
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main(){
    int k = 3;
    int in;
    printf("+\n");
    fflush(stdout);
    scanf("%d",&in);
    if(in == 1){
        printf("+\n");
        fflush(stdout);
        scanf("%d",&in);
        printf("-\n");
        fflush(stdout);
        scanf("%d",&in);
        if(in == 1)cout<<"! ugly"<<endl;
        else {
            cout<<"-"<<endl;
            scanf("%d",&in);
            if(in == 1)cout<<"! good"<<endl;
            else cout<<"! bad"<<endl;
        }
        return 0;
    }
    bool mas = false;
    int temp;
    while(1){
        temp = k;
        while(temp--){
            if(mas){
                printf("+\n");
                fflush(stdout);
                scanf("%d",&in);
                if(in == 1){
                    printf("+\n");
                    fflush(stdout);
                    scanf("%d",&in);
                    printf("-\n");
                    fflush(stdout);
                    scanf("%d",&in);
                    if(in == 1)cout<<"! ugly"<<endl;
                    else {
                        printf("-\n");
                        fflush(stdout);
                        scanf("%d",&in);
                        if(in == 1)cout<<"! good"<<endl;
                        else cout<<"! bad"<<endl;
                    }
                    return 0;
                }
            }
            else{
                printf("-\n");
                fflush(stdout);
                scanf("%d",&in);
                if(in == 1){
                    printf("+\n");
                    fflush(stdout);
                    scanf("%d",&in);
                    printf("-\n");
                    fflush(stdout);
                    scanf("%d",&in);
                    if(in == 1)cout<<"! ugly"<<endl;
                    else {
                       printf("-\n");
                        fflush(stdout);
                        scanf("%d",&in);
                        if(in == 1)cout<<"! good"<<endl;
                        else cout<<"! bad"<<endl;
                    }
                    return 0;
                }
            }
        }
        mas = !mas;
        k *=k;
    }
    return 0;
}
/**************************************************************
WinFilter version 0.8
http://www.winfilter.20m.com
akundert@hotmail.com

Filter type: Low Pass
Filter model: Butterworth
Filter order: 1
Sampling Frequency: 44 KHz
Cut Frequency: 2.000000 KHz
Coefficents Quantization: float

Z domain Zeros
z = -1.000000 + j 0.000000

Z domain Poles
z = 0.749096 + j -0.000000
***************************************************************/
#define Ntap 10

float fir(float NewSample) {
    float FIRCoef[Ntap] = { 
        0.03441332707277614000,
        0.05735090719218852200,
        0.08096640544913560900,
        0.17620353154706628000,
        0.27673412637222528000,
        0.17620353154706628000,
        0.08096640544913560900,
        0.05735090719218852200,
        0.03441332707277614000,
        0.02539753110544155200
    };

    static float x[Ntap]; //input samples
    float y=0;            //d sample
    int n;

    //shift the old samples
    for(n=Ntap-1; n>0; n--)
       x[n] = x[n-1];

    //Calculate the new d
    x[0] = NewSample;
    for(n=0; n<Ntap; n++)
        y += FIRCoef[n] * x[n];
    
    return y;
}


int main(char arvg[],crah a){
    FILE * f;
    char* d= 
    f = fopen()

    return 0;   
}

#include <stdio.h>
#include <stdlib.h>
 
#define PUNTOS_X (6)
#define PUNTOS_H (4)
#define PUNTOS_Y ((PUNTOS_X) + (PUNTOS_H) - 1)
 
/* Los metodos tienen la misma interfaz:
    x, h ---> son las señales de entrada
       y ---> es la señal de salida        */
void input_side_conv(int *x, int *h, int *y)
{
    int i,j;
    for(i=0;i<PUNTOS_X; i++)
        for(j=0;j<PUNTOS_H;j++)
            y[i+j]=y[i+j]+x[i]*h[j];
}
 
void output_side_conv(int *x, int *h, int *y)
{
    int i,j;
 
    for(i=0;i<PUNTOS_Y; i++) {
        y[i]=0;
        for(j=0;j<PUNTOS_H;j++) {
            if(i-j<0 || i-j>=PUNTOS_X) continue;
            y[i] = y[i]+h[j]*x[i-j];
        }
    }
}
 
int main()
{
    int x[PUNTOS_X] = {0,-1,-1,2,1,1};
    int h[PUNTOS_H] = {1,0,-1,1};
    int y1[PUNTOS_Y] = {0,0,0,0,0,0,0,0,0};
    int y2[PUNTOS_Y] = {0,0,0,0,0,0,0,0,0};
 
    int i;
 
    //calculamos la convolucion por el primer metodo
    input_side_conv(x, h, y1);
    //calculamos la convolucion por el otro metodo
    output_side_conv(x, h, y2);
 
    //mostramos las dos respuestas
    printf("Input Side        Output Side\n");
    for(i=0;i<PUNTOS_Y;i++)
        printf("[%2d]              [%d]\n", y1[i], y2[i]);
  return 0;
}
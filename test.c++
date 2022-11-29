using namespace std;
#include<stdio.h>
#include<bits/stdc++.h>
#define MAXIN 3050

int main(){
    double fibo[1000];
    fibo[0] = 1;
    fibo[1] = 1;
    for(int i = 2; i < 1000; i++){
        fibo[i] = fibo[i-1] + fibo[i-2];
    }
    for(int i = 1; i < 1000; i++){
        printf("%f %f\n", fibo[i], fibo[i] - 1.618033988749894848204586 * fibo[i-1]);
    }


    return 0;
}
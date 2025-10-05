#include <stdio.h>
int main(int argc, char** argv) {
    double array[10];
    double sum = 0;
    double rounded = 0;
    for(int i = 0; i < 10; ++i) {
        scanf("%lf", &array[i]);
        sum +=array[i];
 }
    double ot = (sum/10);
    if (ot>=0){
        rounded = (int)(ot * 100 + 0.5) / 100.0;
    }
    else{
        rounded = (int)(ot * 100 - 0.5) / 100.0;
    }
    printf("%.2f", rounded);
    return 0;
}
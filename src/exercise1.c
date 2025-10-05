#include <stdio.h>
int main(int argc, char** argv) {
    double array[10];
    double sum = 0;
    int t = 1;
    for(int i = 0; i < 10; ++i) {
        scanf("%lf", &array[i]);
        sum +=array[i];
 }
    double ot = (sum/10);
    if(ot*1000>=5){
        ot+=0.01;
        t +=1;
    }
    printf("%.2f", ot);
    return 0;
}
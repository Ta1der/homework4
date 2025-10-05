#include <stdio.h>
int main(int argc, char** argv) {
    double array[10];
    float sum = 0;
    for(int i = 0; i < 10; ++i) {
        scanf("%lf", &array[i]);
        sum +=array[i];
 }
    float ot = sum/10;
    printf("%.2f", ot);
    return 0;
}

#include <stdio.h>
int main(int argc, char** argv) {
    double array[10];
    double sum = 0;
    for(int i = 0; i < 10; ++i) {
        scanf("%lf", &array[i]);
        sum +=array[i];
 }
    double ot = sum/10;
    printf("%.2f", ot + 0.0000001);
    return 0;
}

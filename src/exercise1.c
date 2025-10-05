#include <stdio.h>

int main() {
    double array[10], sum = 0;
    for(int i = 0; i < 10; i++) {
        scanf("%lf", &array[i]);
        sum += array[i];
    }
    double average = sum / 10;
    long long cents = (long long)(average * 1000 + 0.5);
    if (cents % 10 >= 5) {
        cents = cents / 10 + 1;
    } 
    else {
        cents = cents / 10;
    }

    double rounded = cents / 100.0;
    printf("%.2f\n", rounded);
    return 0;
}
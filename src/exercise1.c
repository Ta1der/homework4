#include <stdio.h>

int main() {
    double array[10], sum = 0;
    
    for(int i = 0; i < 10; i++) {
        scanf("%lf", &array[i]);
        sum += array[i];
    }
    double average = sum / 10;
    double rounded;
    if (average >= 0) {
        rounded = (long long)(average * 100 + 0.5) / 100.0;
    } else {
        rounded = (long long)(average * 100 - 0.5) / 100.0;
    }
    
    printf("%.2f", rounded);
    return 0;
}

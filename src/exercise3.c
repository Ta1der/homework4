#include <stdio.h>
#include <stdlib.h>
int main(int argc, char** argv) {
    int k = atoi(argv[1]);
    int array[10];
    for(int i = 0; i < 10; ++i) {
        scanf("%d", &array[i]);
 }
    for(int i = 0; i < 10; ++i) {
        printf("%d ", array[(i + (10 - k)) % 10]);
    }

}

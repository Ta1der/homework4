#include <stdio.h>
int main(int argc, char** argv) {
    int array[10];
    for(int i = 0; i < 10; ++i) {
        scanf("%d", &array[i]);
 }
    for(int i = 9; i >= 0; --i) {
        printf("%d ",array[i]);
     }
}

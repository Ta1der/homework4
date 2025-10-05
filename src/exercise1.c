#include <stdio.h>
int main(int argc, char** argv) {
 int array[5];
 printf("Введите пять целых чисел:\n");
 for(int i = 0; i < 5; ++i) {
 scanf("%d", &array[i]);
 }
 return 0;
}

#include <stdio.h>
int main(int argc, char** argv) {
    float array[10];
    float sum = 0;
    for(int i = 0; i < 10; ++i) {
        scanf("%f", &array[i]);
        sum +=array[i];
 }
    float ot = (sum/10);
    if (ot>0){
        ot = ((sum/10)*100+0.5)/100;
    }
    else{
        ot = ((sum/10)*100-0.5)/100;
    }
    printf("%.2f", ot);
    return 0;
}

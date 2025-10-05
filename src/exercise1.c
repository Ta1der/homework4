#include <stdio.h>
int main(int argc, char** argv) {
    double array[10];
    double sum = 0;
    for(int i = 0; i < 10; ++i) {
        scanf("%lf", &array[i]);
        sum +=array[i];
 }
    double ot = (sum/10);
    if (ot>0){
        ot = ((sum/10)*100+0.5)/100;
    }
    else{
        ot = ((sum/10)*100-0.5)/100;
    }
    printf("%.2f", ot);
    return 0;
}

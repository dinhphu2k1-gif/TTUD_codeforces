// bai 4.7
// #include <stdio.h>
// #include <math.h>
// #include <string.h>
// #include <stdlib.h>
// int main()
// {
//     int n;
//     double x;
//     double res = 0;

//     scanf("%d%lf", &n, &x);
//     if (n < 0){
//         printf("Error");
//         return 0;
//     }

//     for (int i = 0; i <= n; i++){
//         if (i % 2 == 1) res -= pow(x, i);
//         else res += pow(x, i);
//     }
//     printf("%lf", res);

//     return 0;
// }


#include <stdio.h>

int main(){
    int n;
    double x;
    scanf("%d%lf", &n, &x);
    if (n < 0){
        printf("Error");
        return 0;
    }

    double res = 1;
    double tuso = 1, mauso = 1;
    for (int i = 1; i <= n; i++){
        tuso *= x;
        mauso *= i;
        res += x/i;
    }
    printf("%lf", res);

    return 0;
}

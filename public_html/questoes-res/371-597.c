#include<stdio.h>
#include<math.h>

main(){
    float a,b,c;
    printf("Informe a: ");
    scanf("%f",&a);
    printf("Informe b: ");
    scanf("%f",&b);
    printf("Informe c: ");
    scanf("%f",&c);

    float delta = b*b - 4*a*c;

    if (a == 0)
        printf("Impossivel calcular");
    else if (delta < 0)
        printf("Impossivel calcular");
    else{
        float y1 = (-b + sqrt(delta))/(2*a);
        float y2 = (-b - sqrt(delta))/(2*a);
        printf("Raizes: %.1f, %.1f",y1,y2);
    }

}

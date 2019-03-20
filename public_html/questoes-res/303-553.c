#include<stdio.h>
#include<math.h>

struct ponto {
    float x,y;
};

float distancia(struct ponto p1, struct ponto p2){
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

float menordist(struct ponto v[], int n){
    int i, j;
    float menor;
    for (i=0 ; i<n ; i++){
        for (j=i+1 ; j<n ; j++){
            if (i==0 && j==1)
                menor = distancia(v[0], v[1]);
            else if (distancia(v[i], v[j]) < menor){
                menor = distancia(v[i], v[j]);
            }
        }
    }
    return menor;
}

main(){
    struct ponto p[10];
    int i;
    for (i=0 ; i<10 ; i++){
        scanf("%f %f",&p[i].x, &p[i].y);
    }
    printf("Dist: %.4f\n",menordist(p, 10));
}

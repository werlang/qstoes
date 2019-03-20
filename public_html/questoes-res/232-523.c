#include<stdio.h>

main(){
    int ent;
    scanf("%i",&ent);
    int i, contp=0;
    float renda, rico, total=0;
    for (i=0 ; i<ent ; i++){
        scanf("%f",&renda);
        total += renda;// total = total + renda;
        if (renda < 2.5)
            contp++;
        if (i==0 || renda > rico)
            rico = renda;
    }
    float porcp = (float)contp/ent*100;
    float porcr = rico/total*100;
    printf("%.1f%% estao abaixo da linha da pobreza\n",porcp);
    printf("O mais rico detem %.1f%% da renda total\n",porcr);
}
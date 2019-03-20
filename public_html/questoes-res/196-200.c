/**Escreva um programa que peça para o usuário
 entrar com o valor de cinco temperaturas diferentes,
  e mostre a média das temperaturas que forem maiores que 100 °C.**/
#include<stdio.h>
main(){
      float t1,t2,t3,t4,t5,x2,x3,x4,x5;
    printf("informe 5 temperaturas e te darei a media das temperaturas acima de 100c.\n");
    printf("informe a primeira:\n");
    scanf("%f",&t1);
        printf("informe a segunda:\n");
        scanf("%f",&t2);
            printf("informe a terceira:\n");
            scanf("%f",&t3);
                printf("informe a quarta:\n");
                scanf("%f",&t4);
                    printf("informe a quinta:\n");
                    scanf("%f",&t5);
///temperaturas abaixo de 100c
if(t1&&t2<100){}
if(t3&&t4<100){}
if(t4&&t5<100){}
///cinco temperaturas acima de 100c
if(t1>100&t2>100&t3>100&t4>100&t5>100){
    x5=(t1+t2+t3+t4+t5)/5;
    printf("essas temp. %.1fc, %.1fc, %.1fc, %.1fc e %.1fc tem a media de %.1fc\n",t1,t2,t3,t4,t5,x5);
    return;
}

///quatro temperaturas acima de 100c

if(t1>100&t2>100&t3>100&t4>100){
        x4=(t1+t2+t3+t4)/4;
        printf("essas temp. %.1fc, %.1fc, %.1fc, %.1fc tem a media de %.1fc\n",t1,t2,t3,t4,x4);
        return;
}
if(t1>100&t2>100&t3>100&t5>100){
    x4=(t1+t2+t3+t5)/4;
    printf("essas temp. %.1fc, %.1fc, %.1fc, %.1fc tem a media de %.1fc\n",t1,t2,t3,t5,x4);
    return;
}
if(t1>10&t3>100&t4>100&t5>100){
    x4=(t1+t3+t4+t5)/4;
    printf("essas temp. %.1fc, %.1fc, %.1fc, %.1fc tem a media de %.1fc\n",t1,t3,t4,t5,x4);
    return;
}
if(t1>100&t4>100&t2>100&t5>100){
    x4=(t1+t4+t2+t5)/4;
    printf("essas temp. %.1fc, %.1fc, %.1fc, %.1fc tem a media de %.1fc\n",t1,t4,t2,t5,x4);
    return;
}

///tres temperaturas acima de 100c
if(t1&&t2&&t3&&t4&&t5){
if(t1>100&t2>100&t3>100){
    x3=(t1+t2+t3)/3;
    printf("\nessas temp %.1fc, %.1fc, %.1fc tem media de %.1fc\n",t1,t2,t3,x3);
    return;
}
if(t1>100&t2>100&t4>100<t3&100<t5){
    x3=(t1+t2+t4)/3;
    printf("\nessas temp %.1fc, %.1fc, %.1fc tem media de %.1fc\n",t1,t2,t4,x3);
    return;
}
if(t1>100&t2>100&t5>100){
    x3=(t1+t2+t5)/3;
    printf("\nnessas temp %.1fc, %.1fc, %.1fc tem media de %.1fc\n",t1,t2,t5,x3);
    return;
}
if(t2>100&t3>100&t4>100){
    x3=(t2+t3+t4)/3;
    printf("\nnessas temp %.1fc, %.1fc, %.1fc tem media de %.1fc\n",t2,t3,t4,x3);
    return;
}
if(t2>100&t4>100&t5>100){
    x3=(t2+t4+t5)/3;
    printf("\nnessas temp %.1fc, %.1fc, %.1fc tem media de %.1fc\n",t2,t4,t5,x3);
    return;
}
if(t2>100&t3>100&t5>100){
    x3=(t2+t3+t5)/3;
    printf("\nnessas temp %.1fc, %.1fc, %.1fc tem media de %.1fc\n",t2,t3,t5,x3);
    return;
}
if(t3>100&t1>100&t5>100){
    x3=(t3+t1+t5)/3;
    printf("\nnessas temp %.1fc, %.1fc, %.1fc tem media de %.1fc\n",t3,t1,t5,x3);
    return;
}
if(t3>100&t4>100&t5>100){
    x3=(t3+t4+t5)/3;
    printf("\nnessas temp %.1fc, %.1fc, %.1fc tem media de %.1fc\n",t3,t4,t5,x3);
    return;
}
if(t4>100&t3>100&t1>100){
    x3=(t4+t3+t1)/3;
    printf("\nnessas temp %.1fc, %.1fc, %.1fc tem media de %.1fc\n",t4,t3,t1,x3);
    return;
}
if(t5>100&t4>100&t1>100){
    x3=(t5+t4+t1)/3;
    printf("\nnessas temp %.1fc, %.1fc, %.1fc tem media de %.1fc\n",t5,t4,t1,x3);
    return;
}
}
///duas temperaturas acima de 100c

if(t4>100&t5>100){
        x2=(t4+t5)/2;
    printf("nessas temp %.1fc e %.1fc tem media de %.1fc\n",t4,t5,x2);
    return;
}

if(t1>100&t3>100){
    x2=(t2+t3)/2;
    printf("nessas temp %.1fc e %.1fc tem media de %.1fc\n",t1,t3,x2);
    return;
}
if(t1>100&t4>100){
    x2=(t3+t4)/2;
    printf("nessas temp %.1fc e %.1fc tem media de %.1fc\n",t1,t4,x2);
    return;
}
if(t1>100&t5>100){
    x2=(t4+t5)/2;
    printf("nessas temp %.1fc e %.1fc tem media de %.1fc\n",t1,t5,x2);
    return;
}
if(t2>100&t3>100){
    x2=(t2+t3)/2;
    printf("nessas temp %.1fc e %.1fc tem media de %.1fc\n",t2,t3,x2);
    return;
}
if(t2>100&t4>100){
    x2=(t2+t4)/2;
    printf("nessas temp %.1fc e %.1fc tem media de %.1fc\n",t2,t4,x2);
    return;
}
if(t2>100&t5>100){
    x2=(t2+t5)/2;
    printf("nessas temp %.1fc e %.1fc tem media de %.1fc\n",t2,t5,x2);
    return;
}
if(t3>100&t4>100){
    x2=(t3+t4)/2;
    printf("nessas temp %.1fc e %.1fc tem media de %.1fc\n",t3,t4,x2);
    return;
}
if(t3>100&t5>100){
    x2=(t3+t5)/2;
    printf("nessas temp %.1fc e %.1fc tem media de %.1fc\n",t3,t5,x2);
    return;
}

if(t1>100&t2>100){
    x2=(t1+t2)/2;
    printf("nessas temp %.1fc e %.1fc tem media de %.1fc\n",t1,t2,x2);
    return;
}
}

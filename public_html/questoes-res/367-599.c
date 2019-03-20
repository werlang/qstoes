#include<stdio.h>

main()  {

       int time1,time2;

       printf("informe os gols feitos pelo Time 1: ");
       scanf("%i",&time1);
       printf("informe os gols feitos pelo Time 2: ");
       scanf("%i",&time2);

      if(time1>time2){
        printf("Time 1 venceu o jogo ",time1);
      }
      if(time2>time1){
                printf("Time dois venceu o jogo",time2);
      }

      if(time1==time2){
        printf("EMPATE\n");
      }



}

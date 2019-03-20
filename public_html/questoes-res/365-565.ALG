Algoritmo "q365"
Var
   mes: vetor[1..6,1..7] de inteiro
   i,j: inteiro
   dias, cont, dinicial: inteiro
Inicio
   escreva("Quantos dias tem o mês? ")
   leia(dias)
   escreva("Em que dia da semana começa o mês (1=domingo)? ")
   leia(dinicial)

   cont <- 0
   para i de 1 ate 6 faca
      para j de 1 ate 7 faca
         se (i > 1) ou (j >= dinicial) entao
            cont <- cont + 1
            se (cont <= dias) entao
               mes[i,j] <- cont
            fimse
         fimse
         se (mes[i,j] <> 0) entao
            escreva(mes[i,j]:3:0)
         senao
            escreva("   ")
         fimse
      fimpara
      escreval()
   fimpara
Fimalgoritmo
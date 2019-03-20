Algoritmo "q361"
Var
   mat: vetor[1..3,1..5] de inteiro
   i,j,soma: inteiro
Inicio
   escreva("Informe os valores da matriz: ")
   para i de 1 ate 3 faca
      para j de 1 ate 5 faca
         leia(mat[i,j])
         enquanto(mat[i,j] <= 0) faca
            leia(mat[i,j])
         fimenquanto
      fimpara
   fimpara

   soma <- 0
   para j de 1 ate 5 faca
      para i de 1 ate 3 faca
         soma <- soma + mat[i,j]
      fimpara
      escreval(soma)
      soma <- 0
   fimpara

Fimalgoritmo


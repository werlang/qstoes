Algoritmo "ex.349"
Var
   vet: vetor [1..10] de inteiro
   valor, i, t: inteiro
   jatem: logico
Inicio
   t <- 1
   enquanto (t <= 10) faca
      escreva("Informe um valor: ")
      leia(valor)
      jatem <- falso
      para i de 1 ate t faca
         se (vet[i] = valor) entao
            jatem <- verdadeiro
         fimse
      fimpara
      se (jatem = falso) entao
         vet[t] <- valor
         t <- t + 1
      fimse
   fimenquanto
   escreval("Lista dos 10 números:")
   para i de 1 ate 10 faca
      escreva(vet[i])
   fimpara
Fimalgoritmo
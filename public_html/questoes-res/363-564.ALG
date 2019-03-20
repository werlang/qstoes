Algoritmo "q363"
Var
   mat: vetor[1..10,1..20] de real
   contv: vetor[1..10] de inteiro
   vend, coluna, produtos, i, j: inteiro
   valor: real
Inicio
   repita
      escreva("Informe o valor do produto: ")
      leia(valor)
      escreva("Informe o número do vendedor: ")
      leia(vend)

      coluna <- contv[vend]+ 1
      contv[vend] <- contv[vend] + 1
      mat[vend,coluna] <- valor

      produtos <- produtos + 1
   ate (valor <= 0) ou (produtos = 20)

   para i de 1 ate 10 faca
      se (contv[i] > 0) entao
         escreva("Vendedor",i,": ")
         para j de 1 ate contv[i] faca
            escreva(mat[i,j],",")
         fimpara
         escreval()
      fimse
   fimpara

Fimalgoritmo
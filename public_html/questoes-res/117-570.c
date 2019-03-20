#include<stdio.h>
#include<math.h>

long int binaux(int n, int d){
    if (d == 0){
        if (n == 1)
            return 1;
        return 0;
    }
    if (n < pow(2,d))
        return binaux(n,d-1);
    return pow(10,d) + binaux(n-pow(2,d),d-1);
    
}

long int binario(int n){
    return binaux(n,20);
}

main(){
    printf("%li",binario(6));
}
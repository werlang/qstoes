#include <stdio.h>

main () {

	float cons, dist, comb;
	printf ("Informe o consumo do seu carro (km/l): "); scanf ("%f", &cons);
	printf ("Informe a distancia do percurso (km): "); scanf ("%f", &dist);
	printf ("Informe o valor do combustivel (R$): "); scanf ("%f", &comb);

	float gasto=(dist/cons)*comb;
	printf ("o gasto sera de R$%.2f", gasto);

}

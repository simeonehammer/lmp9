#include "gauss.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/**
 
Zwraca 0 - eliminacja zakończona sukcesem
Zwraca 1 - macierz osobliwa - dzielenie przez 0
*/
int eliminate(Matrix mat, Matrixb) {
    int i, j, k;
    int n = mat->r;

    for (i = 0; i < n; i++) {
        // Wybieramy glowny element
        int glowny = i;

        for (j = i + 1; j < n; j++) {
            if (fabs(mat->data[j][i]) > fabs(mat->data[glowny][i])) {
            
		    glowny = j;

            }
        }

        // Zamiana wierszy, jeśli inny wiersz ma większy element główny
        if (glowny != i) {
            // Zamień wiersze macierzy
            for (k = i; k < n; k++) {

                double temp = mat->data[i][k];
                mat->data[i][k] = mat->data[glowny][k];
                mat->data[glowny][k] = temp;
            }

            // Zamień elementy wektora prawych stron
            double temp = b->data[i][0];

            b->data[i][0] = b->data[glowny][0];
            b->data[glowny][0] = temp;
        }

        // Eliminacja poniżej diagonalnej
	//
        for (j = i + 1; j < n; j++) {
            double factor = mat->data[j][i] / mat->data[i][i];

            for (k = i; k < n; k++) {
                mat->data[j][k] -= factor * mat->data[i][k];
            }

            b->data[j][0] -= factor * b->data[i][0];
        }

        // Sprawdzenie macierzy osobliwej (dzielenie przez zero)
	
        if (mat->data[i][i] == 0.0) {
            return 1; // Macierz jest osobliwa
        }
    }

    return 0; // Sukces
}






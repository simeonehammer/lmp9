#include "backsubst.h"

int  backsubst(Matrix *x, Matrix *mat, Matrix *b) {

    if (mat->r != mat->c || mat->r != b->r || x->r != b->r || x->c != 1) {
        // Błąd nieprawidłowych rozmiarów macierzy
        return 2;
    }

    for (int i = mat->r - 1; i >= 0; i--) {
        if (mat->data[i][i] == 0) {
            // Błąd dzielenia przez 0 (element na diagonali = 0)
            return 1;
        }

        x->data[i][0] = b->data[i][0] / mat->data[i][i];

        for (int j = 0; j < i; j++) {
            b->data[j][0] -= mat->data[j][i] * x->data[i][0];
        }
    }

    // Wsteczne podstawienie zakończone sukcesem
    return 0;
}




#include "gauss.h"

/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
int eliminate(Matrix *mat, Matrix *b)
{
	int i, j, k;
	int n = mat->r;

	for (i = 0; i < n; i++)
	{

		for (j = i + 1; j < n; j++)
		{
			double factor = mat->data[j][i] / mat->data[i][i];
			for (k = i; k < n; k++)
			{
				mat->data[j][k] -= factor * mat->data[i][k];
			}
			b->data[j][0] -= factor * b->data[i][0];
		}

		if (mat->data[i][i] == 0.0)
		{
			return 1;
		}
	}

	return 0;
}

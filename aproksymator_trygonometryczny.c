#include "makespl.h"

#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <math.h>

void make_spl (points_t * pts, spline_t * spl){

	int i, j, m;
	int n = pts->n;
	double *x = pts->x;
	double *y = pts->y;

	if (n % 2 == 1)
		m = (n-1)/2-1;
	else 
		m = n/2-1;

	if (alloc_spl(spl, n) == 0){
		spl->x = x;
		spl->f = y;

		for (i=0; i<=m; i++){
			spl->a[i] = 0.0;
			spl->b[i] = 0.0;

			for(j=1; j<n; j++){
				spl->a[i] += (2/n)*pts->y[j]*cos((2*M_PI*i*j)/n);
				spl->b[i] += (2/n)*pts->y[j]*sin((2*M_PI*i*j)/n);
			}
		}
	}
}

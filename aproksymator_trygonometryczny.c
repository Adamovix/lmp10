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
	double k = 0.0;

	if (n % 2 == 1)
		m = (n-1)/2;
	else 
		m = n/2;

	if (alloc_spl(spl, n) == 0){
		spl->x = x;
		spl->y = y;

		for (i=0; i<=m; i++){
			spl->a[i] = 0.0;
			spl->b[i] = 0.0;

			for(j=0; j<n; j++){
				k = j*2*M_PI/n;
				spl->a[i] += (2.0/n)*spl->y[j]*(cos(i*k));
				spl->b[i] += (2.0/n)*spl->y[j]*(sin(i*k));
			}
		}
	}
}

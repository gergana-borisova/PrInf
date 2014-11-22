#include "fcpp.hh"
#include <stdio.h>

int i=0;

double f(double x, double w) {
	return x*x-w;
}

bool gut_genug (double wsqrt, double w) {
  return fabs(f(wsqrt, w))<=1E-12;
}

double NSIter (double w, double a, double b) {
  i=i+1;
  double m = (a+b)/2;
  return cond(gut_genug(m, w),
	       m,
	       cond(f(m, w)>0, NSIter(w,a,m), NSIter(w,m,b)));
}

double wurzel (double w, double a, double b)
{
  return NSIter(w, a, b);
}

int main (int argc, char** argv)
{
  double wsqrt = wurzel(readarg_double(argc,argv,1), 0, 4);
  printf("sqrt(w) nach %d Durchläufen =\n", i);
  return print(wsqrt);
}

/*
 * w	Durchläufe eps=1E-12	Durchläufe Newton
 * 2	40						6
 * 3	42						6
 * 4	1						7
 */

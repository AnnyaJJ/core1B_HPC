#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double p[20], t[20];
int n = 0;

FILE *fp = fopen("strong.dat", "r");
while (n  < 20 && fscanf(fp, "%d %lf", &p[n], &t[n]) == 2) {
    n++;
}
fclose(fp);

double sxy = 0.0, sxx = 0.0;
    for (int i = 0; i < n; i++) {
        double S = t[0] / t[i];
        double x = 1.0 - 1.0 / p[i];
        double y = 1.0 / S - 1.0 / p[i];
        sxy += x * y;
        sxx += x * x;
    }
    double f = sxy / sxx;

printf("f = %.5f\n", f);
    printf("speedup maximo = %.2f\n", 1.0 / f);

FILE *out = fopen("strong_fit.dat", "w");
for (int i = 0; i < n; i++) {
    double S_med = t[0] / t[i];
    double S_mod = 1.0 / (f + (1.0 - f) / p[i]);
    fprintf(out, "%g %f %f\n", p[i], S_med, S_mod);
}
fclose(out);
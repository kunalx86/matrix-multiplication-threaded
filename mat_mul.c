#include <stdio.h>
#include <time.h>

#define n 1000
#define m 1000
// const int n = 100, m = 100;
int a[n][m], b[n][m], c[n][m], s = 1;

int main() {
  clock_t t;
  double time_taken;

  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; ++j) {
      c[i][j] = 0;
      a[i][j] = b[i][j] = s++;
    }

  t = clock();
  for (int i = 0; i < m; ++i)
    for (int j = 0; j < n; ++j) 
      for (int k = 0; k < m; ++k) 
        c[i][j] += a[i][k] * b[k][j];
  t = clock() - t;
  time_taken = ((double) t ) / CLOCKS_PER_SEC;

  printf("%lf\n", time_taken);

  return 0;
}
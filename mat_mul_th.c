#include <stdio.h>
#include <pthread.h>
#include <time.h>

#define n 1000
#define m 1000

int a[n][m], b[n][m], c[n][m], s = 1;

// The worker function that will be executed by each Thread
void* worker(void* arg) {
  int i = *((int*) arg);

  for (int j = 0; j < n; ++j) {
    for (int k = 0; k < m; ++k) {
      c[i][j] += a[i][k] * b[k][j]; 
    }
  }
  return NULL;
}

int main() {
  // Declaration of Threads
  pthread_t t[m];
  int rows[m];
  clock_t ti;
  double time_taken;
  
  // Populate the arrays
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; ++j) {
      c[i][j] = 0;
      a[i][j] = b[i][j] = s++;
    }

  // Initialize the clock
  ti = clock();
  for (int i = 0; i < m; ++i) {
    // Assign the row index at ith position which will be passed as an argument to compute the result for the row.
    rows[i] = i;
    // Spawn the thread with i as parameter
    // For every row in solution a thread will be spawned to compute the result
    pthread_create(&t[i], NULL, worker, (void*)&rows[i]);
  }
  
  for (int i = 0; i < m; ++i) {
    // Wait for the Threads to return
    pthread_join(t[i], NULL);
  }
  // Timer end
  ti = clock() - ti;
  time_taken = (double) ti / CLOCKS_PER_SEC;

  printf("%lf\n", time_taken);

  return 0;
}
#include <stdio.h>

#define SIZE 10

int connected(int *id, int p, int q) {
  return id[p] == id[q] ? 1 : 0;
}

void unite(int *id, int p, int q) {
  int qid = id[q];
  int pid = id[p];

  if(connected(id, p, q) == 1) { return; }

  for(int i = 0; i < SIZE; i++) {
    if(id[i] == pid) {
      id[i] = qid;
    }
  }

  return;
}

int main() {
  int id[SIZE]   = { 0,1,2,3,4,5,6,7,8,9 };

  for(int i = 0; i < SIZE - 1; i++) {
    printf("Checking if %d and %d are connected: %d\n", i, i+1, connected(id, i, i+1));
  }

  for(int i = 0; i < SIZE - 1; i++) {
    printf("Connecting %d and %d\n", i, i+1);
    unite(id, i, i+1);
    printf("Checking if %d and %d are connected: %d\n", i, i+1, connected(id, i, i+1));
  }

  //random selection because all nodes should now be connected
  printf("Checking if %d and %d are connected: %d\n", 0, 9, connected(id, 0, 9));
  printf("Checking if %d and %d are connected: %d\n", 1, 8, connected(id, 1, 8));
  printf("Checking if %d and %d are connected: %d\n", 2, 7, connected(id, 2, 7));
  printf("Checking if %d and %d are connected: %d\n", 3, 6, connected(id, 3, 6));
  printf("Checking if %d and %d are connected: %d\n", 4, 5, connected(id, 4, 5));

  return 0;
}

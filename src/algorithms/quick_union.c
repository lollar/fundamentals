// quick_union.c - Mike Lollar
// Simple algorithm for determining if two nodes are connected
// and connecting two nodes if not.
//
// DEFECTS:
// Trees can grow tall
// Find is too expensive (could be N array accesses)
#include <stdio.h>

#define SIZE 10

typedef struct Repos {
  int ids[SIZE];
} Repo;

Repo init() {
  Repo repo;

  for(int i = 0; i < SIZE; i++) {
    repo.ids[i] = i;
  }

  return repo;
}

int root(Repo *repo, int i) {
  while(i != repo->ids[i]) { i = repo->ids[i]; }

  return i;
}

int connected(Repo *repo, int p, int q) {
  return root(repo, p) == root(repo, q) ? 1 : 0;
}

void unite(Repo *repo, int p, int q) {
  int i            = root(repo, p);
  int j            = root(repo, q);
  repo->ids[i] = j;

  return;
}

int main() {
  Repo repo = init();

  for(int i = 0; i < SIZE; i++) {
    printf("Checking %d node is at root... %d\n", i, root(&repo, i));
  }

  for(int i = 0; i < SIZE - 1; i++) {
    printf("Checking if %d and %d are connected... %d\n", i, i+1, connected(&repo, i, i+1));
  }

  // randomly uniting some of the nodes
  unite(&repo, 3, 7);
  unite(&repo, 4, 5);
  unite(&repo, 1, 9);
  unite(&repo, 8, 1);
  unite(&repo, 9, 4);

  printf("Checking all connections...\n");

  for(int i = 0; i < SIZE; i++) {
    for(int j = 0; j < SIZE; j++) {
      if(j == i){
        continue;
      } else {
        printf("Checking if %d and %d are connected... %d\n", i, j, connected(&repo, i, j));
      }
    }
  }

  return 0;
}

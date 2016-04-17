#include <algorithm>
#include <cstdio>
#include <cstring>

#define MAXN 1000

using namespace std;

int f[MAXN];

int INVALID = 0, PAIR = 1, PATH = 2, LOOP = 3;
int pathType[MAXN], bestPathTo[MAXN];
bool found[MAXN];

void follow(int st, int& type, int& dest, int& size) {
  memset(found, false, sizeof(found));

  size = 0; dest = st;
  int prev2 = -1, prev = -1;
  while(!found[dest]) {
    found[dest] = true; size++;
    prev2 = prev; prev = dest; dest = f[dest];
  }

  if(size == 2) type = PAIR;
  else if(dest == st) type = LOOP;
  else type = (dest == prev2 ? PATH : INVALID);
}

int main() {
  int t; scanf("%d", &t);
  for (int tc = 1; tc <= t; tc++) {
    int n; scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      scanf("%d", &f[i]); f[i]--;
    }

    memset(bestPathTo, 0, sizeof(bestPathTo));

    int best = 0, dest, size;
    for (int i = 0; i < n; i++) {
      follow(i, pathType[i], dest, size);

      if(pathType[i] == LOOP) {
        best = max(best, size);
      } else if(pathType[i] == PATH) {
        bestPathTo[dest] = max(bestPathTo[dest], size - 2);
      }
    }

    int groupedBest = 0;
    for (int i = 0; i < n; i++) {
      if(pathType[i] == PAIR)
        groupedBest += 1 + bestPathTo[i];
    }
    best = max(best, groupedBest);
    printf("Case #%d: %d\n", tc, best);
  }
  return 0;
}

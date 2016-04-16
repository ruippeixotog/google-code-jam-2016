#include <cstdio>
#include <cstring>

#define MAXN 50
#define MAXH 2500

using namespace std;

int hs[2 * MAXN - 1][MAXN];

bool used[2 * MAXN - 1];
int hsIndex[MAXN][2], sol[MAXN];

int main() {
  int t; scanf("%d", &t);
  for (int tc = 1; tc <= t; tc++) {
    int n; scanf("%d", &n);

    for(int i = 0; i < 2 * n - 1; i++) {
      for(int j = 0; j < n; j++)
        scanf("%d", &hs[i][j]);
    }

    memset(used, false, sizeof(used));

    int missing = -1;
    for(int i = 0; i < n; i++) {
      int minH = MAXH + 1;
      for(int j = 0; j < 2 * n - 1; j++) {
        if(used[j]) continue;
        if(hs[j][i] < minH) {
          minH = hs[j][i]; hsIndex[i][0] = j; hsIndex[i][1] = -1;
        } else if(hs[j][i] == minH) {
          hsIndex[i][1] = j;
        }
      }
      used[hsIndex[i][0]] = true;
      if(hsIndex[i][1] == -1) missing = i;
      else used[hsIndex[i][1]] = true;
    }

    for (int i = 0; i < n; i++) {
      if(i == missing) sol[i] = hs[hsIndex[i][0]][i];
      else {
        sol[i] = hs[hsIndex[i][0]][missing] == hs[hsIndex[missing][0]][i] ?
                 hs[hsIndex[i][1]][missing] : hs[hsIndex[i][0]][missing];
      }
    }

    printf("Case #%d:", tc);
    for(int i = 0; i < n; i++) printf(" %d", sol[i]);
    printf("\n");
  }
  return 0;
}

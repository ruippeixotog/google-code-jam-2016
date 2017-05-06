#include <algorithm>
#include <cstdio>
#include <cstring>

#define MAXN 200

using namespace std;

typedef long double ld;

int n, k;
ld p[MAXN];

ld com[MAXN], dp[MAXN + 1][MAXN / 2 + 1];

int main() {
  int t; scanf("%d", &t);
  for(int tc = 1; tc <= t; tc++) {
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++)
      scanf("%Lf", &p[i]);

    sort(p, p + n);

    ld best = 0.0;
    for(int k0 = 0; k0 <= k; k0++) {
      for(int i = 0; i < k0; i++) com[i] = p[i];
      for(int i = 0; i < k - k0; i++) com[k0 + i] = p[n - i - 1];

      memset(dp, 0, sizeof(dp));
      dp[0][0] = 1.0;

      for(int i = 0; i < k; i++) {
        for(int j = 0; j <= k / 2; j++) {
          dp[i + 1][j + 1] += dp[i][j] * com[i];
          dp[i + 1][j] += dp[i][j] * (1.0 - com[i]);
        }
      }
      best = max(best, dp[k][k / 2]);
    }

    printf("Case #%d: %.9Lf\n", tc, best);
  }
  return 0;
}

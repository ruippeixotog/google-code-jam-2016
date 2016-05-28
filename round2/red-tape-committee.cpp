#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>

#define MAXN 200
#define INF 1000000000

using namespace std;

typedef long long ll;
typedef long double ld;

int n, k;
ld p[MAXN];

//ld dp[MAXN + 1][MAXN + 1];

vector<int> sol;

ld bf2(int curr, int yesCnt, ld pAcc) {
  if(curr == sol.size()) {
    return (yesCnt == sol.size() / 2) ? pAcc : 0.0;
  }

  return
    bf2(curr + 1, yesCnt + 1, pAcc * p[sol[curr]]) +
    bf2(curr + 1, yesCnt, pAcc * (1.0 - p[sol[curr]]));
}

ld bf(int curr) {
  if(sol.size() == k) return bf2(0, 0, 1.0);

  sol.push_back(curr);
  ld p1 = bf(curr + 1);
  sol.pop_back();

  if((n - curr - 1) >= (k - sol.size()))
    p1 = max(p1, bf(curr + 1));

  return p1;
}

int main() {
  int t; scanf("%d", &t);
  for(int tc = 1; tc <= t; tc++) {
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; i++)
      scanf("%Lf", &p[i]);

    ld sol = bf(0);

//    memset(dp, 0, sizeof(dp));
//    dp[0][0] = 1.0;
//
//    for(int i = 0; i < n; i++) {
//      ld dpNew[MAXN + 1][MAXN + 1];
//      memcpy(dpNew, dp, sizeof(dp));
//
//      for(int yes = 0; yes <= i; yes++) {
//        for(int no = 0; no <= i; no++) {
//          dpNew[yes + 1][no] = max(dpNew[yes + 1][no], dp[yes][no] * p[i]);
//          dpNew[yes][no + 1] = max(dpNew[yes][no + 1], dp[yes][no] * (1.0 - p[i]));
//        }
//      }
//
//      memcpy(dp, dpNew, sizeof(dp));
//    }

//    printf("Case #%d: %Lf\n", tc, dp[k / 2][k / 2]);
    printf("Case #%d: %.8Lf\n", tc, sol);
  }
  return 0;
}

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

#define MAXN 2000

#define IS_SET(var, pos) ((var) & (1 << (pos)))

using namespace std;

typedef long long ll;
typedef long double ld;

string w1[MAXN], w2[MAXN];

int main() {
  int t; scanf("%d", &t);
  for (int tc = 1; tc <= t; tc++) {
    int n; scanf("%d", &n);
    for (int i = 0; i < n; i++)
      cin >> w1[i] >> w2[i];

    int best = 0;
    for (int set = 0; set < (1 << n); set++) {
      int count = 0; bool valid = true;

      for(int b = 0; b < n; b++) {
        if(IS_SET(set, b)) continue;
        count++;

        bool found1 = false, found2 = false;
        for(int b2 = 0; b2 < n; b2++) {
          if(IS_SET(set, b2)) {
            if (w1[b] == w1[b2]) found1 = true;
            if (w2[b] == w2[b2]) found2 = true;
          }
        }

        if(!found1 || !found2) {
          valid = false;
          break;
        }
      }

      if(valid)
        best = max(best, count);
    }

    printf("Case #%d: %d\n", tc, best);
  }
  return 0;
}

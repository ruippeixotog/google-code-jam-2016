#include <algorithm>
#include <cstdio>

using namespace std;

typedef long long ll;

int main() {
  int t; scanf("%d", &t);
  for (int tc = 1; tc <= t; tc++) {
    int k, c, s; scanf("%d %d %d", &k, &c, &s);

    printf("Case #%d:", tc);
    if(s < (k + c - 1) / c) printf(" IMPOSSIBLE");
    else {
      for(int i = 0; i < k; i += c) {
        ll idx = 0;
        for(int j = 0; j < c; j++) {
          idx = idx * k + min(i + j, k - 1);
        }
        printf(" %lld", idx + 1);
      }
    }
    printf("\n");
  }
  return 0;
}

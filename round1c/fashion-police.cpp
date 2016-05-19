#include <algorithm>
#include <cstdio>

using namespace std;

int main() {
  int t; scanf("%d", &t);
  for (int tc = 1; tc <= t; tc++) {
    int j, p, s, k; scanf("%d %d %d %d", &j, &p, &s, &k);

    printf("Case #%d: %d\n", tc, j * p * min(s, k));
    for(int ji = 0; ji < j; ji++) {
      for(int pi = 0; pi < p; pi++) {
        for(int i = 0; i < min(s, k); i++) {
          printf("%d %d %d\n", ji + 1, pi + 1, (ji + pi + i) % s + 1);
        }
      }
    }
  }
  return 0;
}

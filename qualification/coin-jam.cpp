#include <algorithm>
#include <cmath>
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

using namespace std;

typedef long long ll;
typedef long double ld;

int x[MAXN], y[MAXN];

ll conv(ll n, int b) {
  ll n2 = 0, mult = 1;
  while(n != 0) {
    n2 += mult * (n % 2);
    mult *= b;
    n /= 2;
  }
  return n2;
}

int primeFactor(ll n) {
  for(int i = 2; i < (ll) ceil(sqrt(n)); i++) {
    if(n % i == 0) return i;
  }
  return 0;
}

int main() {
  int t;
  scanf("%d", &t);
  for (int tc = 1; tc <= t; tc++) {
    int n, j;
    scanf("%d %d", &n, &j);

    printf("Case #%d:\n", tc);
    for(int i = (1 << (n - 1)); i < (1 << n) && j > 0; i++) {
      if(i % 2 == 0) continue;

      ll factors[10];
      memset(factors, 0, sizeof(factors));

      bool jamcoin = true;

      for(int b = 2; b <= 10; b++) {
        ll ib = conv(i, b);
        ll factor = primeFactor(ib);

        if(!factor) {
          jamcoin = false;
          break;
        } else {
          factors[b - 1] = factor;
        }
      }

      if(jamcoin) {
        printf("%lld", conv(i, 10));
        for(int b = 1; b < 10; b++) {
          printf(" %lld", factors[b]);
        }
        printf("\n");
        j--;
      }
    }
  }
  return 0;
}

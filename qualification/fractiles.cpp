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

using namespace std;

typedef long long ll;
typedef long double ld;

int x[MAXN], y[MAXN];

int main() {
  int t;
  scanf("%d", &t);
  for (int tc = 1; tc <= t; tc++) {
    int k, c, s; scanf("%d %d %d", &k, &c, &s);
    ll pow = k;
    while(c > 1) { pow = pow * k; c--; }
    ll step = pow / k;

    printf("Case #%d:", tc);
    for(int i = 0; i < s; i++) {
      printf(" %lld", step * i + 1);
    }
    printf("\n");
  }
  return 0;
}

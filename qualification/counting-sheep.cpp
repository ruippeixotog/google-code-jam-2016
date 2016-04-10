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

bool found[10];

int main() {
  int t;
  scanf("%d", &t);
  for (int tc = 1; tc <= t; tc++) {
    int n;
    scanf("%d", &n);

    memset(found, 0, sizeof(found));

    int i, last;
    for (i = 1; i < 101; i++) {
      last = n * i;
      int res = last;
      while(res != 0) {
//        if(!found[res % 10]) fprintf(stderr, "found: %d\n", res % 10);
        found[res % 10] = true;
        res /= 10;
      }

      bool foundAll = true;
      for(int j = 0; j < 10; j++) {
        if(!found[j]) {
          foundAll = false;
          break;
        }
      }

      if(foundAll) break;
    }

    if(i != 101) {
      printf("Case #%d: %d\n", tc, last);
    } else {
      printf("Case #%d: INSOMNIA\n", tc);
    }
  }
  return 0;
}

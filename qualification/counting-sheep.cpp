#include <cstdio>
#include <cstring>

using namespace std;

bool found[10];

int main() {
  int t; scanf("%d", &t);
  for (int tc = 1; tc <= t; tc++) {
    int n; scanf("%d", &n);

    int last = 0;
    if(n != 0) {
      memset(found, 0, sizeof(found));

      bool foundAll = false;
      while(!foundAll) {
        int next = last = last + n;
        while(next != 0) { found[next % 10] = true; next /= 10; }

        foundAll = true;
        for(int j = 0; j < 10; j++) {
          if(!found[j]) { foundAll = false; break; }
        }
      }
    }

    if(last == 0) printf("Case #%d: INSOMNIA\n", tc);
    else printf("Case #%d: %d\n", tc, last);
  }
  return 0;
}

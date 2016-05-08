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

#define MAXB 50

using namespace std;

typedef long long ll;
typedef long double ld;

int graph[MAXB][MAXB];

int main() {
  int t; scanf("%d", &t);
  for (int tc = 1; tc <= t; tc++) {
    int b; ll m; scanf("%d %lld", &b, &m);

    memset(graph, 0, sizeof(graph));
    graph[0][b - 1] = 1;
    m--;

    int idx = 1;
    ll cap = 1;

    while(m > 0 && idx < b - 1) {
      graph[0][idx] = 1;

      cerr << "cap:     " << cap << endl;
      cerr << "missing: " << m << endl;

      ll currCap = cap;
      int link = idx - 1;
      while(link > 0) {
        if(m >= currCap / 2) {
//          cerr << "currCap     " << currCap << endl;
//          cerr << "currCap / 2 " << (currCap / 2) << endl;
//          cerr << "m           " << m << endl;

          graph[idx][link] = 1;
          m -= currCap / 2;
        }
        link--;
        currCap /= 2;
      }

      if(m > 0) {
        graph[idx][b - 1] = 1;
        m--;
      }

      idx++;
      cap *= 2;
    }

    printf("Case #%d: %s\n", tc, m == 0 ? "POSSIBLE" : "IMPOSSIBLE");
    if(m == 0) {
      for(int i = 0; i < b; i++) {
        for(int j = 0; j < b; j++) printf("%d", graph[i][j]);
        printf("\n");
      }
    }
  }
  return 0;
}

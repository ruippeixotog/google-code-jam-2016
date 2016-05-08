#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

#define MAXN 26

using namespace std;

pair<int, char> p[MAXN];

int main() {
  int t; scanf("%d", &t);
  for (int tc = 1; tc <= t; tc++) {
    int n; scanf("%d", &n);

    int ps = 0;
    for (int i = 0; i < n; i++) {
      scanf("%d", &p[i].first);
      p[i].second = (char) ('A' + i);
      ps += p[i].first;
    }

    vector<string> sol;
    while(ps > 0) {
      sort(p, p + n);

      string step(1, p[n - 1].second);
      p[n - 1].first--; ps--;

      if(ps % 2 == 1) {
        step.push_back(p[n - 2].second);
        p[n - 2].first--; ps--;
      }
      sol.push_back(step);
    }

    printf("Case #%d:", tc);
    for(string s : sol) cout << " " << s;
    printf("\n");
  }
  return 0;
}

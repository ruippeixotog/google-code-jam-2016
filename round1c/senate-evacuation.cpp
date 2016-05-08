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

int p[MAXN];

vector<pair<int, char>> pairs;
vector<string> sol;

int main() {
  int t; scanf("%d", &t);
  for (int tc = 1; tc <= t; tc++) {
    cerr << "tc" << tc << endl;
    int n; scanf("%d", &n);

    int ps = 0;
    for (int i = 0; i < n; i++) {
      scanf("%d", &p[i]);
      ps += p[i];
    }

    pairs.clear();
    for(int i = 0; i < n; i++)
      pairs.push_back(make_pair(p[i], (char) ('A' + i)));

    sol.clear();
    while(ps > 0) {
      sort(pairs.begin(), pairs.end());

      if(pairs[pairs.size() - 1].first > ps / 2) {
        fprintf(stderr, "ERROR majority! ps=%d, p[%c]=%d\n", ps,
                pairs[pairs.size() - 1].second, pairs[pairs.size() - 1].first);

        cerr << "current: " << endl;
        for(auto p : pairs) {
          cerr << p.first << ": " << p.second << endl;
        }
      }

      if(ps % 2 == 1) {
        char x = pairs[pairs.size() - 1].second;
        pairs[pairs.size() - 1].first--;

        sol.push_back(string(1, x));
        ps--;

      } else {
        char x1 = pairs[pairs.size() - 1].second;
        pairs[pairs.size() - 1].first--;
        char x2 = pairs[pairs.size() - 2].second;
        pairs[pairs.size() - 2].first--;

        sol.push_back(string(1, x1) + x2);
        ps -= 2;
      }
    }

    if(ps != 0) cerr << "ERROR: " << ps << endl;

    printf("Case #%d:", tc);
    for(string s : sol) cout << " " << s;
    printf("\n");
  }
  return 0;
}

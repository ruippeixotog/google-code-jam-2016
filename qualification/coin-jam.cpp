#include <cstdio>
#include <vector>
#include <string>

using namespace std;

int j;
vector<string> sols;

void putEven(string curr, int cnt, int k) {
  if(sols.size() == j) return;
  if(k >= curr.size() - 1) {
    if(cnt == 0) sols.push_back(curr);
    return;
  }

  putEven(curr, cnt, k + 2);
  curr[k] = '1';
  putEven(curr, cnt - 1, k + 2);
}

void putOdd(string curr, int cnt, int k) {
  if(sols.size() == j) return;
  if(k >= curr.size() - 1) { putEven(curr, cnt, 2); return; }

  putOdd(curr, cnt, k + 2);
  curr[k] = '1';
  putOdd(curr, cnt + 1, k + 2);
}

int main() {
  int t; scanf("%d", &t);
  for (int tc = 1; tc <= t; tc++) {
    int n; scanf("%d %d", &n, &j);

    string base;
    for(int i = 0; i < n; i++)
      base.push_back(i == 0 || i == n - 1 ? '1' : '0');

    sols.clear();
    putOdd(base, 0, 1);

    printf("Case #%d:\n", tc);
    for(string sol : sols) {
      printf("%s 3 4 5 6 7 8 9 10 11\n", sol.c_str());
    }
  }
  return 0;
}

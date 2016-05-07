#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <string>

#define MAXN 1000

using namespace std;

map<string, int> w1Index, w2Index;
bool graph[MAXN][MAXN];

bool seen[MAXN];
int matchL[MAXN], matchR[MAXN];

bool bpmDfs(int k) {
  for(int i = 0; i < w2Index.size(); i++) {
    if(graph[k][i]) {
      if(seen[i]) continue;
      seen[i] = true;

      if(matchR[i] < 0 || bpmDfs(matchR[i])) {
        matchL[k] = i; matchR[i] = k;
        return true;
      }
    }
  }
  return false;
}

int bpm() {
  memset(matchL, -1, sizeof(matchL));
  memset(matchR, -1, sizeof(matchR));
  int cnt = 0;
  for(int i = 0; i < w1Index.size(); i++) {
    memset(seen, false, sizeof(seen));
    if(bpmDfs(i)) cnt++;
  }
  return cnt;
}

int main() {
  int t; scanf("%d", &t);
  for (int tc = 1; tc <= t; tc++) {
    int n; scanf("%d", &n);

    memset(graph, false, sizeof(graph));
    w1Index.clear(); w2Index.clear();

    for (int i = 0; i < n; i++) {
      string w1, w2; cin >> w1 >> w2;
      if(!w1Index.count(w1)) w1Index[w1] = (int) w1Index.size();
      if(!w2Index.count(w2)) w2Index[w2] = (int) w2Index.size();
      graph[w1Index[w1]][w2Index[w2]] = true;
    }

    int matches = bpm();
    int res = n - matches - (w1Index.size() - matches)
              - (w2Index.size() - matches);

    printf("Case #%d: %d\n", tc, res);
  }
  return 0;
}

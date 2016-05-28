#include <algorithm>
#include <cstdio>
#include <string>

using namespace std;

string moves[] = {"P", "R", "S"};
int rem[3];

string gen0(int n, int winner) {
  if(n == 1) { rem[winner]--; return moves[winner]; }

  string winBranch = gen0(n / 2, winner);
  string loseBranch = gen0(n / 2, (winner + 1) % 3);
  return min(winBranch + loseBranch, loseBranch + winBranch);
}

string gen(int n, int r, int p, int s) {
  string best = "Z";
  for(int winner = 0; winner < 3; winner++) {
    rem[0] = p; rem[1] = r; rem[2] = s;
    string bestCurr = gen0(n, winner);

    if(rem[0] == 0 && rem[1] == 0 && rem[2] == 0)
      best = min(best, bestCurr);
  }
  return best == "Z" ? "" : best;
}

int main() {
  int t; scanf("%d", &t);
  for(int tc = 1; tc <= t; tc++) {
    int n, r, p, s; scanf("%d %d %d %d", &n, &r, &p, &s);
    n = 1 << n;

    string sol = gen(n, r, p, s);

    printf("Case #%d: ", tc);
    if(sol.empty()) printf("IMPOSSIBLE\n");
    else printf("%s\n", sol.c_str());
  }
  return 0;
}

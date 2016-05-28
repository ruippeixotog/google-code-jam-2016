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
#define INF 1000000000

using namespace std;

typedef long long ll;
typedef long double ld;

int x[MAXN], y[MAXN];

int n, r, p, s;

//bool bf(string& curr, int k) {
//  if(k >= n) {
//    cerr << "testing " << curr << endl;
//
//    string run = curr, next;
//    while(run.size() > 1) {
//      for(int i = 0; i < run.size(); i += 2) {
//        if(run[i] == run[i + 1]) return false;
//        if((run[i] == 'S' && run[i + 1] == 'P') ||
//          (run[i] == 'P' && run[i + 1] == 'R') ||
//          (run[i] == 'R' && run[i + 1] == 'S')) {
//
//          next.push_back(run[i]);
//        } else {
//          next.push_back(run[i + 1]);
//        }
//      }
//      run = next; next = "";
//      cerr << "  - " << run << endl;
//    }
//    return true;
//  }
//
//  if(p > 0) {
//    curr.push_back('P'); p--;
//    if(bf(curr, k + 1)) return true;
//    curr.pop_back(); p++;
//  }
//
//  if(r > 0) {
//    curr.push_back('R'); r--;
//    if(bf(curr, k + 1)) return true;
//    curr.pop_back(); r++;
//  }
//
//  if(s > 0) {
//    curr.push_back('S'); s--;
//    if(bf(curr, k + 1)) return true;
//    curr.pop_back(); s++;
//  }
//
//  return false;
//}

map<vector<int>, string> mem;

string best(int n, int p, int r, int s, int winner) {
  vector<int> memKey = {n, p, r, winner};
  if(mem.count(memKey)) return mem[memKey];

//  if(n >= 1024)
//    cerr << n << " " << p << " " << r << " " << s << " " << winner << endl;

  if(n == 2) {
    switch(winner) {
      case 0:
        if(p == 0 || r == 0) return "";
        return "PR";
      case 1:
        if(r == 0 || s == 0) return "";
        return "RS";
      case 2:
        if(s == 0 || p == 0) return "";
        return "PS";
    }
    cerr << "error" << endl;
  }

  string bestStr;
  int rem = n / 2;
  for(int i = 0; i <= min(p, rem); i++) {
    int rem2 = rem - i;
    for(int j = 0; j <= min(r, rem2); j++) {
      int k = rem2 - j;
//      cerr << " div: " << i << " " << j << " " << k << endl;
//      cerr << "(lim) " << p << " " << r << " " << s << endl;
      if(k < 0 || k > s) continue;

      string bestLeftWin = best(n / 2, i, j, k, winner);
      string bestRightLose = best(n / 2, p - i, r - j, s - k, (winner + 1) % 3);

      string bestLeftLose = best(n / 2, i, j, k, (winner + 1) % 3);
      string bestRightWin = best(n / 2, p - i, r - j, s - k, winner);

      string bestInner;
      if(bestLeftWin == "" || bestRightLose == "") {
        if(bestLeftLose == "" || bestRightWin == "") bestInner = "";
        else bestInner = bestLeftLose + bestRightWin;
      } else {
        if(bestLeftLose == "" || bestRightWin == "") bestInner = bestLeftWin + bestRightLose;
        else {
          if(bestLeftWin < bestLeftLose) bestInner = bestLeftWin + bestRightLose;
          else bestInner = bestLeftLose + bestRightWin;
        }
      }

//      cerr << " parts: " << bestLeftWin << "+" << bestRightLose << " " << bestLeftLose << "+" << bestRightWin << endl;
//      cerr << " cand: " << bestStr << endl;

      if(bestStr == "" || (bestInner != "" && bestInner < bestStr))
        bestStr = bestInner;
    }
  }
  mem[memKey] = bestStr;
  return bestStr;
}

int main() {
  int t; scanf("%d", &t);
  for(int tc = 1; tc <= t; tc++) {
    scanf("%d %d %d %d", &n, &r, &p, &s);
    n = 1 << n;

//    string sol; bf(sol, 0);
    string sol = best(n, p, r, s, 0);
    string sol2 = best(n, p, r, s, 1);
    string sol3 = best(n, p, r, s, 2);

    if(sol == "" || (sol2 != "" && sol2 < sol)) sol = sol2;
    if(sol == "" || (sol3 != "" && sol3 < sol)) sol = sol3;

    printf("Case #%d: ", tc);
    if(sol.empty()) printf("IMPOSSIBLE\n");
    else printf("%s\n", sol.c_str());
  }
  return 0;
}

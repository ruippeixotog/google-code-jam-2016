#include <iostream>
#include <string>

using namespace std;

typedef long long ll;

int n;
string bestCs, bestJs;

bool better(string& cs, string& js, string& cs2, string& js2) {
  ll diff1 = abs(stoll(cs) - stoll(js));
  ll diff2 = abs(stoll(cs2) - stoll(js2));
  if(diff1 != diff2) return diff1 < diff2;

  else if(stoll(cs) != stoll(cs2)) return stoll(cs) < stoll(cs2);
  else return stoll(js) < stoll(js2);
}

void makeLargest(string& s, int st, int end) {
  for(int i = st; i < end; i++) {
    if(s[i] == '?') s[i] = '9';
  }
}

void makeSmallest(string& s, int st, int end) {
  for(int i = st; i < end; i++) {
    if(s[i] == '?') s[i] = '0';
  }
}

void checkSolution(string& cs, string& js) {
  if(bestCs.empty() || better(cs, js, bestCs, bestJs)) {
    bestCs = cs; bestJs = js;
  }
}

void finishFilling(string cs, string js, char ck, char jk, int k) {
  cs[k] = ck; js[k] = jk;
  makeLargest(ck > jk ? js : cs, k + 1, n);
  makeSmallest(ck > jk ? cs : js, k + 1, n);
  checkSolution(cs, js);
}

void go(string cs, string js, int k) {
  if(k >= n) { checkSolution(cs, js); return; }

  if(cs[k] == '?') {
    if(js[k] == '?') {
      cs[k] = '0'; js[k] = '0'; go(cs, js, k + 1);
      finishFilling(cs, js, '0', '1', k);
      finishFilling(cs, js, '1', '0', k);

    } else {
      cs[k] = js[k]; go(cs, js, k + 1);

      if(js[k] != '9') {
        finishFilling(cs, js, (char) (js[k] + 1), js[k], k);
      }
      if(js[k] != '0') {
        finishFilling(cs, js, (char) (js[k] - 1), js[k], k);
      }
    }

  } else if(js[k] == '?') {
    js[k] = cs[k]; go(cs, js, k + 1);

    if(cs[k] != '9') {
      finishFilling(cs, js, cs[k], (char) (cs[k] + 1), k);
    }
    if(cs[k] != '0') {
      finishFilling(cs, js, cs[k], (char) (cs[k] - 1), k);
    }

  } else if(cs[k] != js[k]) {
    finishFilling(cs, js, cs[k], js[k], k);

  } else {
    go(cs, js, k + 1);
  }
}

int main() {
  int t; scanf("%d", &t);
  for (int tc = 1; tc <= t; tc++) {
    string cs, js; cin >> cs >> js;
    n = (int) cs.size();

    bestCs = bestJs = "";
    go(cs, js, 0);
    cout << "Case #" << tc << ": " << bestCs << " " << bestJs << endl;
  }
  return 0;
}

#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int main() {
  int t; scanf("%d", &t);
  for (int tc = 1; tc <= t; tc++) {
    string str; cin >> str;

    string last;
    for (char ch: str) {
      if(!last.empty() && ch >= last[0]) last.insert(0, 1, ch);
      else last.push_back(ch);
    }
    cout << "Case #" << tc << ": " << last << endl;
  }
  return 0;
}

#include <cstdio>
#include <iostream>

using namespace std;

int main() {
  int t; scanf("%d", &t);
  for (int tc = 1; tc <= t; tc++) {
    string str; cin >> str;

    int cnt = 0;
    for(int i = 1; i < str.length(); i++) {
      if(str[i] != str[i - 1]) cnt++;
    }
    if(str.back() == '-') cnt++;
    printf("Case #%d: %d\n", tc, cnt);
  }
  return 0;
}

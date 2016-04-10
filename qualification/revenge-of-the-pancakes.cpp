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

int main() {
  int t;
  scanf("%d", &t);
  for (int tc = 1; tc <= t; tc++) {
    string str; cin >> str;

    int cnt = 0;
    while(true) {
      char first = str[0];
      int i = 1;
      while(i < str.length() && str[i] == first) i++;

      if(i < str.length()) {
        for(int j = 0; j < i; j++) {
          str[j] = str[j] == '-' ? '+' : '-';
        }
        cnt++;
      } else {
        break;
      }
    }

    if(str[0] == '-') cnt++;
    printf("Case #%d: %d\n", tc, cnt);
  }
  return 0;
}

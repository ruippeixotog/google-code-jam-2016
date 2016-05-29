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

#include "oops.h"
#include "message.h"

#define MAXN 2000
#define INF 2e18

using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
  int nodeBegin = (int) (MyNodeId() * GetN() / NumberOfNodes());
  int nodeEnd = (int) ((MyNodeId() + 1) * GetN() / NumberOfNodes());

  bool hasValues = nodeEnd - nodeBegin > 0;
  ll minVal = INF, maxVal = -INF;
  for(int i = nodeBegin; i < nodeEnd; i++) {
    minVal = min(minVal, GetNumber(i));
    maxVal = max(maxVal, GetNumber(i));
  }

  cerr << MyNodeId() << ": " << hasValues << " " << minVal << " " << maxVal << endl;

  if(MyNodeId() != 0) {
    PutInt(0, hasValues);
    if(hasValues) { PutLL(0, minVal); PutLL(0, maxVal); }
    Send(0);

  } else {
    for(int k = 1; k < NumberOfNodes(); k++) {
      Receive(k);
      if(GetInt(k)) {
        minVal = min(minVal, GetLL(k));
        maxVal = max(maxVal, GetLL(k));
      }
    }
    if(minVal == INF) minVal = maxVal = 0;
    printf("%lld\n", maxVal - minVal);
  }

  return 0;
}

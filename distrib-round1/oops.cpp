#include <algorithm>
#include <cstdio>

#include "oops.h"
#include "message.h"

#define INF 2e18

using namespace std;

typedef long long ll;

int main() {
  int nodeBegin = (int) (MyNodeId() * GetN() / NumberOfNodes());
  int nodeEnd = (int) ((MyNodeId() + 1) * GetN() / NumberOfNodes());

  ll minVal = INF, maxVal = -INF;
  for(int i = nodeBegin; i < nodeEnd; i++) {
    minVal = min(minVal, GetNumber(i));
    maxVal = max(maxVal, GetNumber(i));
  }

  if(MyNodeId() != 0) {
    PutLL(0, minVal);
    PutLL(0, maxVal);
    Send(0);

  } else {
    for(int k = 1; k < NumberOfNodes(); k++) {
      Receive(k);
      minVal = min(minVal, GetLL(k));
      maxVal = max(maxVal, GetLL(k));
    }
    printf("%lld\n", minVal == INF ? 0 : maxVal - minVal);
  }

  return 0;
}

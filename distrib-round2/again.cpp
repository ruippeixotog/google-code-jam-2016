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

#include "again.h"
#include "message.h"

#define MAXN 2000
#define MOD 1000000007

using namespace std;

typedef long long ll;
typedef long double ld;

ll a[20], b[20];

int main() {
  int nodeBegin = (MyNodeId() * GetN() / NumberOfNodes());
  int nodeEnd = ((MyNodeId() + 1) * GetN() / NumberOfNodes());

//  ll a = 0, b = 0;
  for(int i = nodeBegin; i < nodeEnd; i++) {
    int k = i % NumberOfNodes();
    a[k] = (a[k] + GetA(i)) % MOD;
    b[k] = (b[k] + GetB(i)) % MOD;
  }

  if(MyNodeId() != 0) {
    for(int k = 0; k < NumberOfNodes(); k++) {
      PutLL(0, a[k]);
      PutLL(0, b[k]);
    }
    Send(0);

  } else {
    for(int k = 1; k < NumberOfNodes(); k++) {
      Receive(k);
      for(int k2 = 0; k2 < NumberOfNodes(); k2++) {
        a[k2] = (a[k2] + GetLL(k)) % MOD;
        b[k2] = (b[k2] + GetLL(k)) % MOD;
      }
    }

    ll res = 0;
    for(int k = 0; k < NumberOfNodes(); k++) {
      for(int k2 = 0; k2 < NumberOfNodes(); k2++) {
        if((k + k2) % NumberOfNodes() > 0) {
          res = (res + ((a[k] * b[k2]) % MOD)) % MOD;
        }
      }
    }
    printf("%lld\n", res);
  }
  return 0;
}

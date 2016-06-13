#include <cstdio>

#include "again.h"
#include "message.h"

#define MAX_NODES 20
#define MOD 1000000007

using namespace std;

typedef long long ll;

ll a[MAX_NODES], b[MAX_NODES];

int main() {
  int nodeBegin = (int) (MyNodeId() * GetN() / NumberOfNodes());
  int nodeEnd = (int) ((MyNodeId() + 1) * GetN() / NumberOfNodes());

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
      for(int i = 0; i < NumberOfNodes(); i++) {
        a[i] = (a[i] + GetLL(k)) % MOD;
        b[i] = (b[i] + GetLL(k)) % MOD;
      }
    }

    ll res = 0;
    for(int i = 0; i < NumberOfNodes(); i++) {
      for(int j = 0; j < NumberOfNodes(); j++) {
        if((i + j) % NumberOfNodes() > 0) {
          res = (res + (a[i] * b[j] % MOD)) % MOD;
        }
      }
    }
    printf("%lld\n", res);
  }
  return 0;
}

#include <cstdio>
#include <cstdlib>

#include "crates.h"
#include "message.h"

#define MOD 1000000007

using namespace std;

typedef long long ll;

int main() {
  int nodeBegin = (int) (MyNodeId() * GetNumStacks() / NumberOfNodes());
  int nodeEnd = (int) ((MyNodeId() + 1) * GetNumStacks() / NumberOfNodes());

  // -- phase 1: get sum --

  ll sum = 0;
  for(int i = nodeBegin; i < nodeEnd; i++)
    sum += GetStackHeight(i + 1);

  if(MyNodeId() != 0) {
    PutLL(0, sum); Send(0);
    Receive(0); sum = GetLL(0);

  } else {
    for(int k = 1; k < NumberOfNodes(); k++) {
      Receive(k); sum += GetLL(k);
    }
    for(int k = 1; k < NumberOfNodes(); k++) {
      PutLL(k, sum); Send(k);
    }
  }

  // -- phase 2: calculate back debts --

  ll backDebt = 0, localDebt = 0;
  for(int i = nodeBegin; i < nodeEnd; i++) {
    ll reqStackHeight = (sum / GetNumStacks()) + (sum % GetNumStacks() > i);
    localDebt += reqStackHeight - GetStackHeight(i + 1);
  }

  if(MyNodeId() > 0) {
    Receive(MyNodeId() - 1);
    backDebt = GetLL(MyNodeId() - 1);
  }

  if(MyNodeId() < NumberOfNodes() - 1) {
    PutLL(MyNodeId() + 1, backDebt + localDebt);
    Send(MyNodeId() + 1);
  }

  // -- phase 3: compute number of moves --

  ll moves = 0; ll currDebt = backDebt;
  for(int i = nodeBegin; i < nodeEnd; i++) {
    ll reqStackHeight = (sum / GetNumStacks()) + (sum % GetNumStacks() > i);
    ll currHeight = GetStackHeight(i + 1) - currDebt;

    moves = (moves + abs(reqStackHeight - currHeight)) % MOD;
    currDebt = reqStackHeight - currHeight;
  }

  if(MyNodeId() > 0) {
    Receive(MyNodeId() - 1);
    moves = (moves + GetLL(MyNodeId() - 1)) % MOD;
  }

  if(MyNodeId() < NumberOfNodes() - 1) {
    PutLL(MyNodeId() + 1, moves);
    Send(MyNodeId() + 1);
  } else {
    printf("%lld\n", moves);
  }

  return 0;
}

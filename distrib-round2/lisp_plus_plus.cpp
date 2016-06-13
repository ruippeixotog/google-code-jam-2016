#include <cstdio>

#include "lisp_plus_plus.h"
#include "message.h"

using namespace std;

typedef long long ll;

int main() {
  int nodeBegin = (int) (MyNodeId() * GetLength() / NumberOfNodes());
  int nodeEnd = (int) ((MyNodeId() + 1) * GetLength() / NumberOfNodes());

  ll back = 0, fwd = 0;
  for(int i = nodeBegin; i < nodeEnd; i++) {
    if(GetCharacter(i) == '(') fwd++;
    else if(fwd == 0) back++;
    else fwd--;
  }
  PutLL(0, back);
  PutLL(0, fwd);
  Send(0);

  if(MyNodeId() != 0) return 0;

  int k; ll balance = 0;
  for(k = 0; k < NumberOfNodes(); k++) {
    Receive(k);
    back = GetLL(k), fwd = GetLL(k);

    if(balance - back < 0) break;
    balance = balance - back + fwd;
  }

  if(k == NumberOfNodes()) {
    printf("%lld\n", balance == 0 ? -1 : GetLength());
  } else {
    int kNodeBegin = (int) (k * GetLength() / NumberOfNodes());
    int kNodeEnd = (int) ((k + 1) * GetLength() / NumberOfNodes());

    for(int i = kNodeBegin; i < kNodeEnd; i++) {
      if(GetCharacter(i) == '(') balance++;
      else if(--balance < 0) { printf("%d\n", i); break; }
    }
  }
  return 0;
}

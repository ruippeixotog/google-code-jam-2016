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

#include "lisp_plus_plus.h"
#include "message.h"

#define MAXN 2000
#define INF 1000000000

using namespace std;

typedef long long ll;
typedef long double ld;

//string str = "())()()())";
//string str = "(((((()))((())))))";
//long long GetLength() { return str.size(); }
//char GetCharacter(long long index) { return str[index]; }

int main() {
  int nodeBegin = (MyNodeId() * GetLength() / NumberOfNodes());
  int nodeEnd = ((MyNodeId() + 1) * GetLength() / NumberOfNodes());

  ll backOpens = 0, cnt = 0;
  for(int i = nodeBegin; i < nodeEnd; i++) {
    if(GetCharacter(i) == '(') cnt++;
    else if(cnt == 0) backOpens--;
    else cnt--;
  }
  PutLL(0, -backOpens);
  PutLL(0, cnt);
  Send(0);

  if(MyNodeId() == 0) {
    int backMissing = -1;
    ll balance = 0;

    for(int k = 0; k < NumberOfNodes(); k++) {
      Receive(k);
      ll bk = GetLL(k), fk = GetLL(k);
//      cerr << bk << " " << fk << endl;
      if(backMissing > -1) continue;

      if(balance - bk < 0) {
        backMissing = k;
      } else {
        balance = balance - bk + fk;
      }
    }

    if(backMissing == -1) {
      if(balance == 0) printf("-1\n");
      else printf("%lld\n", GetLength());
    }
    else {
      int kNodeBegin = (backMissing * GetLength() / NumberOfNodes());
      int kNodeEnd = ((backMissing + 1) * GetLength() / NumberOfNodes());

      ll cnt = balance;
      for(int i = kNodeBegin; i < kNodeEnd; i++) {
        if(GetCharacter(i) == '(') cnt++;
        else if(--cnt < 0) {
          printf("%d\n", i);
          break;
        }
      }
    }
  }
  return 0;
}

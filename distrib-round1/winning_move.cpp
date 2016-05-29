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

#include "winning_move.h"
#include "message.h"

#define MAXN 2000
#define INF 1000000000

using namespace std;

typedef long long ll;
typedef long double ld;

vector<ll> ebuf[100];
vector<int> cntbuf[100];

int main() {
  int nodeBegin = (int) (MyNodeId() * GetNumPlayers() / NumberOfNodes());
  int nodeEnd = (int) ((MyNodeId() + 1) * GetNumPlayers() / NumberOfNodes());

  map<ll, int> numbers;
  for(int i = nodeBegin; i < nodeEnd; i++)
    numbers[GetSubmission(i)]++;

  for(auto entry: numbers) {
//    cerr << entry.first << " -> " << entry.second << endl;
    ebuf[entry.first % NumberOfNodes()].push_back(entry.first);
    cntbuf[entry.first % NumberOfNodes()].push_back(entry.second);
  }

  for(int k = 0; k < NumberOfNodes(); k++) {
    PutInt(k, (int) ebuf[k].size());
//    cerr << MyNodeId() << " sending " << ebuf[k].size() << " numbers to " << k << endl;
    for(int i = 0; i < ebuf[k].size(); i++) {
      PutLL(k, ebuf[k][i]); PutInt(k, cntbuf[k][i]);
    }
    Send(k);
  }

  numbers.clear();

  for(int k = 0; k < NumberOfNodes(); k++) {
    Receive(k);
    int len = GetInt(k);
//    cerr << "len: " << len << endl;
    for(int i = 0; i < len; i++) {
      ll e = GetLL(k); int count = GetInt(k);
      numbers[e] += count;
    }
  }

  ll winner = 0;
  for(auto entry: numbers) {
//    cerr << entry.first << " -> " << entry.second << endl;
    if(entry.second == 1) { winner = entry.first; break; }
  }

  if(MyNodeId() != 0) {
    PutLL(0, winner); Send(0);
  } else {
    for(int k = 1; k < NumberOfNodes(); k++) {
      Receive(k);
      ll nodeWinner = GetLL(k);

//      cerr << "nodeWinner " << k << " = " << nodeWinner << endl;

      if(winner == 0) winner = nodeWinner;
      else if(nodeWinner != 0) {
        winner = min(winner, nodeWinner);
      }
    }
    printf("%lld\n", winner);
  }

  return 0;
}

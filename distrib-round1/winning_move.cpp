#include <algorithm>
#include <cstdio>
#include <map>
#include <vector>

#include "winning_move.h"
#include "message.h"

#define MAX_NODES 100
#define INF 2e18

using namespace std;

typedef long long ll;

unsigned ehash(ll n) {
  unsigned h = 31;
  while (n > 0) {
    h = (h * 54059) ^ ((int) (n % 10) * 76963);
    n /= 10;
  }
  return h;
}

vector<ll> ebuf[MAX_NODES];
vector<int> cntbuf[MAX_NODES];

int main() {
  int nodeBegin = (int) (MyNodeId() * GetNumPlayers() / NumberOfNodes());
  int nodeEnd = (int) ((MyNodeId() + 1) * GetNumPlayers() / NumberOfNodes());

  map<ll, int> numbers;
  for(int i = nodeBegin; i < nodeEnd; i++)
    numbers[GetSubmission(i)]++;

  for(auto entry: numbers) {
    int node = (int) (ehash(entry.first) % NumberOfNodes());
    ebuf[node].push_back(entry.first);
    cntbuf[node].push_back(entry.second);
  }

  for(int k = 0; k < NumberOfNodes(); k++) {
    PutInt(k, (int) ebuf[k].size());
    for(int i = 0; i < ebuf[k].size(); i++) {
      PutLL(k, ebuf[k][i]);
      PutInt(k, cntbuf[k][i]);
    }
    Send(k);
  }

  numbers.clear();

  for(int k = 0; k < NumberOfNodes(); k++) {
    Receive(k);
    int len = GetInt(k);
    for(int i = 0; i < len; i++) {
      ll e = GetLL(k);
      numbers[e] += GetInt(k);
    }
  }

  ll winner = INF;
  for(auto entry: numbers) {
    if(entry.second == 1) { winner = entry.first; break; }
  }

  if(MyNodeId() != 0) {
    PutLL(0, winner); Send(0);
  } else {
    for(int k = 1; k < NumberOfNodes(); k++) {
      Receive(k);
      winner = min(winner, GetLL(k));
    }
    printf("%lld\n", winner == INF ? 0 : winner);
  }

  return 0;
}

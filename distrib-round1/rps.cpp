#include <algorithm>
#include <cstdio>
#include <vector>

#include "rps.h"
#include "message.h"

using namespace std;

void play(vector<int>& currRound) {
  while(currRound.size() > 1) {
    vector<int> nextRound;

    for(int i = 0; i < currRound.size(); i += 2) {
      char moveLeft = GetFavoriteMove(currRound[i]);
      char moveRight = GetFavoriteMove(currRound[i + 1]);

      int winner = currRound[i];
      if(moveLeft != moveRight) {
        winner = ((moveLeft == 'R' && moveRight == 'S') ||
                  (moveLeft == 'S' && moveRight == 'P') ||
                  (moveLeft == 'P' && moveRight == 'R')) ?
                 currRound[i] : currRound[i + 1];
      }
      nextRound.push_back(winner);
    }
    currRound = nextRound;
  }
}

int main() {
  int n = 1 << GetN();
  int nPerNode = n;
  int activeNodes = 1;

  while(nPerNode >= 2 && activeNodes * 2 <= NumberOfNodes()) {
    nPerNode /= 2;
    activeNodes *= 2;
  }

  if(MyNodeId() >= activeNodes) return 0;
  int nodeBegin = MyNodeId() * nPerNode;
  int nodeEnd = (MyNodeId() + 1) * nPerNode;

  vector<int> currRound;
  for(int i = nodeBegin; i < nodeEnd; i++)
    currRound.push_back(i);

  play(currRound);
  PutInt(0, currRound[0]);
  Send(0);

  if(MyNodeId() == 0) {
    currRound.clear();
    for(int k = 0; k < activeNodes; k++) {
      Receive(k);
      currRound.push_back(GetInt(k));
    }
    play(currRound);
    printf("%d\n", currRound[0]);
  }
  return 0;
}

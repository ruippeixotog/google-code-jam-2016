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

#include "gas_stations.h"
#include "message.h"

#define MAXN 2000
#define INF 1000000000

using namespace std;

typedef long long ll;
typedef long double ld;

struct SegTree {
  int size;
  vector<int> tree;
  vector<bool> hasPending;

  SegTree(int n) {
    size = n;
    tree.resize(4 * n + 1);
    hasPending.resize(4 * n + 1);
  }

  inline int left(int node) { return 2 * node; }
  inline int right(int node) { return 2 * node + 1; }

  void build(int node, int st, int end) {
    if (st == end) { tree[node] = 0; return; }

    build(left(node), st, (st + end) / 2);
    build(right(node), (st + end) / 2 + 1, end);
    tree[node] = tree[left(node)] + tree[right(node)];
  }

  void applyPending(int node, int st, int end) {
    if(hasPending[node]) {
      update(left(node), st, (st + end) / 2, st, end);
      update(right(node), (st + end) / 2 + 1, end, st, end);
      hasPending[node] = false;
    }
  }

  int query(int node, int st, int end, int i, int j) {
    if (j < st || i > end) return 0;
    if (st >= i && end <= j) return tree[node];

    applyPending(node, st, end);
    int p1 = query(left(node), st, (st + end) / 2, i, j);
    int p2 = query(right(node), (st + end) / 2 + 1, end, i, j);
    return p1 + p2;
  }

  void update(int node, int st, int end, int i, int j) {
    if (j < st || i > end) return;
    if (st == end) { tree[node] = 1; return; }
    if (st >= i && end <= j) {
      tree[node] = end - st + 1;
      hasPending[node] = true;
      return;
    }
    applyPending(node, st, end);
    if(i <= (st + end) / 2) update(left(node), st, (st + end) / 2, i, j);
    if(j > (st + end) / 2) update(right(node), (st + end) / 2 + 1, end, i, j);
    tree[node] = tree[left(node)] + tree[right(node)];
  }

  void build() { build(1, 0, size - 1); }
  int query(int i, int j) { return query(1, 0, size - 1, i, j); }
  void update(int i, int j) { return update(1, 0, size - 1, i, j); }
};

// -----------------------------------------------

pair<ll, int> prices[1000000];

int main() {
//  int nodeBegin = (MyNodeId() * GetNumKms() / NumberOfNodes());
//  int nodeEnd = ((MyNodeId() + 1) * GetNumKms() / NumberOfNodes());
//
//  ll gas = 0, price = 0;
//  vector<int> bestStations;
//  for(int i = nodeBegin; i < nodeEnd; i++) {
//    int tankEnd = min(GetNumKms(), i + GetTankSize());
//    if(tankEnd > nodeEnd) {
//      while(GetGasPrice(bestStations[bestStations.size() - 1]) >= GetGasPrice(i))
//        bestStations.pop_back();
//      bestStations.push_back(i);
//    }
//  }
//
//  vector<int> backStations;
//  if(MyNodeId() > 0) {
//    Receive(MyNodeId() - 1);
//    int len = GetInt(MyNodeId() - 1);
//    for(int i = 0; i < len; i++)
//      backStations.push_back(GetInt(MyNodeId() - 1));
//  }
//
//
//
//  if(MyNodeId() < NumberOfNodes() - 1) {
//    PutLL(MyNodeId() + 1, backDebt + localDebt);
//    Send(MyNodeId() + 1);
//  }
  if(MyNodeId() != 0) return 0;

  for(int i = 0; i < GetNumKms(); i++)
    prices[i] = make_pair(GetGasPrice(i), i);

  sort(prices, prices + GetNumKms());

  SegTree tree(GetNumKms());

  ll total = 0;
  for(int i = 0; i < GetNumKms(); i++) {
    auto entry = prices[i];
    int tankEnd = min(GetNumKms(), entry.second + GetTankSize());

    int filled = tree.query(entry.second, tankEnd - 1);
    total += (tankEnd - entry.second - filled) * entry.first;
    tree.update(entry.second, tankEnd - 1);

////    cerr << "km " << km << ": " << prices[i].first << endl;
////    cerr << "price: " << total << endl;
  }

  printf("%lld\n", total);
  return 0;
}

#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

string reprs[] = {
    "ZERO", "ONE", "TWO", "THREE", "FOUR",
    "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"
};

int chHist[26], nHist[10];

void remove(int digit, int n) {
  nHist[digit] += n;
  for(char ch : reprs[digit])
    chHist[ch - 'A'] -= n;
}

int main() {
  int t;
  scanf("%d", &t);
  for (int tc = 1; tc <= t; tc++) {
    int n; scanf("%d", &n);
    string str; cin >> str;

    for(char ch : str)
      chHist[ch - 'A']++;

    memset(nHist, 0, sizeof(nHist));

    remove(0, chHist['Z' - 'A']);
    remove(6, chHist['X' - 'A']);
    remove(2, chHist['W' - 'A']);
    remove(8, chHist['G' - 'A']);
    remove(4, chHist['U' - 'A']);

    remove(3, chHist['H' - 'A']);
    remove(5, chHist['F' - 'A']);

    remove(7, chHist['V' - 'A']);
    remove(9, chHist['I' - 'A']);
    remove(1, chHist['O' - 'A']);

    printf("Case #%d: ", tc);
    for(int i = 0; i < 10; i++) {
      for(int j = 0; j < nHist[i]; j++)
        printf("%d", i);
    }
    printf("\n");
  }
  return 0;
}

#include<iostream>
#include <map>
#include <iterator>
#include <utility>

using namespace std;
map <unsigned long long, unsigned long long> dp;

unsigned long long change(unsigned long long a) {
  if (dp[a] > 0) {
    return dp[a];
  } else if (a < 12) return a;
  unsigned long long result = change(a/2) + change(a/3) + change(a/4);
  dp[a] = max(a, result);
  return dp[a];
}

int main() {
  unsigned long long num = 0;
  while (scanf("%llu", &num) != 0) {
    /* code */
    cout << change(num) << endl;
  }
  return 0;
}

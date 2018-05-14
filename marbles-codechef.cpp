// https://www.codechef.com/problems/MARBLES

#include <iostream>
#include <algorithm>
using namespace std;

unsigned long long int ncr(int n, int r){
  // better approach of nCr
  r = min(r, n - r);
  unsigned long long int denom = 1;
  unsigned long long int numer = n;
  unsigned long long int ans= 1;
  while (denom <= r) ans = (ans*numer--)/denom++;
  return ans;
}

int main(int argc, char const *argv[]) {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, k;
    scanf("%d", &n);
    scanf("%d", &k);
    if (n - k  == 0) {
      std::cout << 1 << '\n';
    } else if(n - k == 1){
      std::cout << k << '\n';
    } else {
      std::cout << ncr(n - 1, k - 1) << '\n';
    }
  }
  return 0;
}

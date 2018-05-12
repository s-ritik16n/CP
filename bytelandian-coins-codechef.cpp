#include<iostream>
#include <math.h>
using namespace std;
int stored_arr[1000000] = {0};

unsigned long long change(unsigned long long a) {
  if(a < 100000){
    if (stored_arr[a] != 0) {
      /* code */
      return stored_arr[a];
    } else if(a < 12) return a;
  }
  unsigned long long result = change(a/2) + change(a/3) + change(a/4);
  stored_arr[a] = max(a, result);
  return stored_arr[a];
}

int main() {
  unsigned long long num = 0;
  while (scanf("%llu", &num) != 0) {
    /* code */
    std::cout << change(num);
  }
  return 0;
}

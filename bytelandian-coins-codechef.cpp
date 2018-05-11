#include<iostream>
#include <math.h>
#include <stack>
using namespace std;

int change(int a) {
  return ceil(a/2) + ceil(a/3) + ceil(a/4);
}

int main(int argc, char const *argv[]) {
  int t;
  cin>>t;
  while (t--) {
    /* code */
    int n;
    int sum = n;
    stack<int> s;

    std::cin >> n;
    s.push(n);
    while(s.size() > 0) {
      int first = s.top();
      s.pop();
      if(sum - first + change(first) > sum) {
        sum -= first + change(first);
        s.push(ceil(first/2));
        s.push(ceil(first/3));
        s.push(ceil(first/4));
      }
    }
    std::cout << sum << '\n';
  }
  return 0;
}

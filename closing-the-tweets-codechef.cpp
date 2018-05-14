// https://www.codechef.com/problems/TWTCLOSE

#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[]) {

  int n;
  scanf("%d", &n);
  int arr[n] = {0};
  int k;
  int c = 0;
  scanf("%d", &k);
  while (k--) {
    /* code */
    string str;
    cin>>str;
    if (str == "CLICK") {
      int i;
      cin>>i;
      if (arr[i-1] == 0) {
        arr[i-1] = 1;
        c++;
      } else {
        arr[i-1] = 0;
        c--;
      }
    } else{
      c = 0;
      for (int i = 0; i < n; i++) arr[i] = 0;
    }
    std::cout << c << '\n';
  }
  return 0;
}

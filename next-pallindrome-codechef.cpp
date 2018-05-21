// https://www.codechef.com/problems/PALIN

#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[]) {
  int t;
  cin >> t;
  while (t--) {
    string input;
    cin >> input;
    int c = 0;
    bool greater = false;
    if (input.length() % 2 == 0) {
      int i = input.length() / 2 - 1;
      int j = input.length() - (i + 1);
      while(i >= 0) {
        if (greater) {
          if (c == 1) {
            if (input[i] == '9') {
              c = 1;
              input[i] = '0';
              input[j] = '0';
            } else {
              input[i]++;
              input[j] = input[i];
              c = 0;
            }
          } else {
            input[j] = input[i];
          }
        } else {
          if (input[i] <= input[j]) {
            if (input[i] == '9') {
              c = 1;
              input[i] = '0';
              input[j] = '0';
            } else {
              cout << "f" << endl;
              c = 0;
              input[i] ++;
            }
          }
          input[j] = input[i];
          greater = true;
        }
        i--;
        j = input.length()- (i + 1);
      }
      if (c == 1) {
        input.insert(0, "1");
        input[input.length() - 1] = '1';
      }
    }
    cout << input;
  }
  return 0;
}

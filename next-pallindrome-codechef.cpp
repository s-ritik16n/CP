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
    int i, j, index;
    if (input.length() % 2 == 0) {
      i = input.length()/2 - 1;
      j = i + 1;
    } else {
      i = input.length()/2;
      j = i;
    }
    index = i;
    bool found = false;
    if (input.length() % 2 == 0)
    while (index >= 0) {
      int k = input.length() - (index + 1);
      if (input[index] == input[k]) {
        if(c == 0) {
          c = 1;
        } else {
          if (found) {
            input[index]++;
            input[k] = input[index];
            c = 0;
          }
        }
        index--;
      } else if (input[k] < input[index]) {
        input[k] = input[index];
        index--;
        c = 0;
        break;
      } else if (input[k] > input[index]) {
        if (c == 1) {
          if (input[index] != '9') {
            input[index] ++;
            input[k] = input[index];
            c = 0;
            index--;
            break;
          } else {
            input[index] = '0';
            input[k] = input[index];
            index = i;
            found = true;
            c = 1;
            continue;
          }
        }
        if (input[index] != '9') {
          input[index]++;
          input[k] = input[index];
          index--;
          c = 0;
          break;
        }
      }
    }
    else {
      index--;
      while (index >= 0) {
        int k = input.length()- (index + 1);
        if (input[index] > input[k]) {
          input[k] = input[index];
          index--;
          c = 0;
          break;
        } else if (input[index] < input[k]) {
          if (input[i] != '9') {
            input[i]++;
            c = 0;
            break;
          } else {

          }
        } else {

        }
      }
    }
    if (c == 0) {
      while (index >= 0) {
        int j = input.length() - (index + 1);
        input[j] = input[index--];
      }
    } else {
      input.insert(0, "1");
      int i = 1;
      while(i < input.length()) {
        input[i++] = '0';
      }
      input[input.length() - 1] = '1';
    }
    cout << input << endl;
  }
  return 0;
}

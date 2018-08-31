// https://www.codechef.com/problems/NUMFACT
// 31-8-18

#include<iostream>
using namespace std;

int main(){
  int t;
  cin>>t;
  cout<<t;
  int a[1000000];
  a[0] = 2;
  for (int i = 1; i < 1000000; i++) a[i] = a[i-1] + 1;
  while (t--) {
    int n, count = 0;
    cin>>n;
    int b[n];
    for (size_t i = 0; i < n; i++) cin>>b[i];
    for (size_t i = 0; i < 1000000-1; i++) {
      int num = a[i];
      for (size_t j = 0; j < n; j++) if(b[j]%num == 0) num /= b[j];
      if (num == 1) {
        count += 1;
      }
    }
    cout<<count+2<<endl;
  }
  return 0;
}

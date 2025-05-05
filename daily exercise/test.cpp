#include <iostream>
#include <string>

using namespace std;

int add(int a, int b) {
  return a + b;
}

int main() {
  int n = 5;
  int a = 1, b = 3;
  for (int i = 0; i < n; i++)
  {
    cout << "i = " << i << endl;
  }
  cout << "Hello world" << add(a, b) << endl;
  return 0;
}
#include <fstream>
#include <iostream>
#include <limits>
using namespace std;

int line_length(int num, char **mass) {
  ifstream line("words.txt", ios::in | ios::binary);

  line.close();
  return 0;
}

int number_of_strings() {
  ifstream start("words.txt", ios::in | ios::binary);
  if (!start) {
    cout << "File with shapes not found, maybe you renamed it" << endl;
    return 0;
  }

  int count = 0;
  while (start.ignore(numeric_limits<streamsize>::max(), '\n')) {
    if (!start.eof())
      count++;
  }

  start.close();
  return count;
}

int main() {
  const int len = 50, strings = number_of_strings();

  const char ch = '\n';
  char **mass = new char *[strings];
  for (int i = 0; i < strings; i++) {
    mass[i] = new char[len];
  }

  ifstream work("words.txt", ios::in | ios::binary);

  for (int r = 0; r < strings; r++) {
    work.getline(mass[r], len - 1, ch);
    cout << "String " << r + 1 << " = " << mass[r] << endl;
  }

  work.close();

  return 0;
}

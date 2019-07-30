//main.cpp
#include "stats.h"
#include "p1_library.h"
#include <iostream>
#include <fstream>
using namespace std;

int main() {
  string fname;
  ifstream myfile;
  string column;
  string line;
  cout << "enter a filename\n";
  cin >> fname;
  cout << "enter a column name\n";
  cin >> column;
  cout << "reading column " << column << " from " << fname << "\n";
  myfile.open(fname);
  if (myfile.is_open()){
    while (getline(myfile,line)){
      cout << line << '\n';
    }
    myfile.close();
  }
  else cout << "Unable to open file";
}

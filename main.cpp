//main.cpp
#include "stats.h"
#include "p1_library.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;



vector<int> &extract_column_data(string line, char column);
int get_column_data(string line, int col_index){
    int i = 0;
    int data = -1;
    string raw_data="raw";
    stringstream linestream(line);
    while(getline(linestream,raw_data,'\t')){
        if (i == col_index){
            data = stoi(raw_data);
        }
        i++;
    }
    return data;
}


int get_column_index(string line, char col_label){
    int i = 0;
    string candidate;
    //going through column labels (ie. A, B,...)
    stringstream linestream(line);
    while(getline(linestream,candidate,'\t')){
        if (string(1,col_label) == candidate){
            break;
        }
        i++;
    }
    return i;
}

int main() {
  string fname;
  ifstream myfile;
  char column;
  string line;
  cout << "enter a filename\n";
  cin >> fname;
  cout << "enter a column name\n";
  cin >> column;
  cout << "reading column " << column << " from " << fname << "\n";
  cout << "Summary (value: frequency)\n";
  myfile.open(fname);
  
  int j = 0;
  if (myfile.is_open()){
    while (getline(myfile,line)){
      j++;
    }
  }
  const int SIZE = j;
  myfile.close();
  vector<int>  data_store(SIZE,-1);
  cout<<j;
  myfile.open(fname);
  if (myfile.is_open()){
    //get the column labels
    int col_index = 0;
    //istringstream s1 =  getline(myfile,line);
    //string input = s1.str();
    //string input = string(getline(myfile,line));
    string input;
    getline(myfile,line) >> input;
    col_index = get_column_index(input,column);
    
    //optimizaiton: potentially could just grap second column
    int k = 0;
    while (getline(myfile, line)){

        data_store[k] = get_column_data(line,col_index);       
        //cout << line << '\n';
        k++;
    }
    
    myfile.close();
  }
  else{
      cout << "Unable to open file";
  }

  for (int i = 0; i < SIZE; i++){
        cout << data_store[i] << "\n";
    }
}



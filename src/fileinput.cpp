// reading a text file
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <typeinfo>
#include "fileinput.hpp"
using namespace std;


void printmatrix(vector<vector<char>> mat)
{
  int row = mat.size();
  int col = mat[0].size();
  for (int i = 0; i < row ; i++)
  {
      if (mat[i].size() != 0){
          for (int j = 0 ; j < col ; j++)
        {
          cout<<mat[i][j];
          if (j != col-1)
          {
            cout<<" ";
          }
        }
        cout<<endl;
      }
    }
}

void inputFile(string fileName) {
  
  string line;
  bool flag = false;
  fstream myfile ("../test/"+ fileName);
  while (!myfile.eof())
  {
    getline(myfile, line);
    vector<char> arr;
    if ((int)line[1] == 32)
    {
      for (int i = 0 ; i<line.size(); i=i+2)
      {
        arr.push_back(line[i]);
      }
      mat.push_back(arr);
      
    }
    
    else if ((int)line[1] >= 65 && (int)line[1] <=122 ){
      vector<char> patt;
      for (int i = 0 ; i<line.size(); i++)
      {
        if ((int)line[i] >= 65 && (int)line[i] <=122){
          patt.push_back(line[i]);
        }
        
      }
      listPatt.push_back(patt);

    }

  } mat.pop_back();

}
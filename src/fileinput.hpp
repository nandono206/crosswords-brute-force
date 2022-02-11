#ifndef FILEINPUT_H
#define FILEINPUT_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <typeinfo>
using namespace std;

extern vector<vector<char>> mat;
extern vector<vector<char>> listPatt;

void printmatrix(vector<vector<char>> a);
void inputFile(string fileName);



#endif
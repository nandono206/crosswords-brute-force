#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include "solver.hpp"

using namespace std;

int matcher(vector<char> P, vector<char> T){
    int m = P.size();
    int n = T.size();
    int i = 0;
    int j = 0;
    bool found = false;

    while ((i<=n-m) && not(found)){
        j = 0;
        while ((j < m) && (P[j] == T[i+j])){
            j++;
        }
        if (j == m){
            found = true;
        }
        else{
            i++;
        }
    }

    if (found){
        return i;
    }
    else{
        return -1;
    }
}


#include <iostream>
#include <fstream>
#include "solver.hpp"
#include "fileinput.hpp"
#include <typeinfo>
#include <chrono>
#include <ctime> 

using namespace std;

void printascii(vector<vector<char>> ex){
    for(auto x: ex){
        for(auto y: x){
            cout << (int)y << ' '; 
        }
        cout << '\n';
    }
}

void printdefault(vector<char> ex){
    for(auto x: ex){
        cout << x;
    }
    cout << '\n';
}

vector<vector<char>> mat;
vector<vector<char>> listPatt;
int main(){
    string fileName;
    cout << "Masukkan nama file: ";
    cin >> fileName;
    cout << '\n';
    inputFile(fileName);

    vector<vector<char>> rlistPatt;
    for(int x = 0; x<listPatt.size(); x++){
        vector<char> rpatt;
        for (auto ir = listPatt[x].rbegin(); ir != listPatt[x].rend(); ++ir){
            rpatt.push_back(*ir);
        }
        rlistPatt.push_back(rpatt);
        
    }

    

    int counter = 0;


    

    
    auto start = chrono::system_clock::now();
    for (int j = 0; j < listPatt.size(); j++){
        // inisialisasi display matriks
        vector<vector<char>> disp;
        int row = mat.size();
        int col = mat[0].size();

        for (int i = 0; i < row ; i++)
        {
            vector<char> arrnew;
            for (int j = 0 ; j < col ; j++)
            {
                arrnew.push_back('-');
            }
            disp.push_back(arrnew);
          
        }
        int idx;
        
        //HORIZONTAL
        for (int i=0; i< mat.size(); i++){
            //KIRI KE KANAN
            // auto start = chrono::system_clock::now();
            idx = matcher(listPatt[j], mat[i]);
            // auto end = chrono::system_clock::now();
            // chrono::duration<double> elapsed_seconds = end-start;
            // chrono::duration<double> total_time = total_time + elapsed_seconds;
            counter++;

            if (idx != -1){                
                for(int k = 0; k < listPatt[j].size(); k++){
                    disp[i][idx] = listPatt[j][k];
                    idx++;
                }
                printmatrix(disp);
                cout << '\n';
            }
            else{
                //kanan ke kiri
            //    auto start2 = chrono::system_clock::now();
               idx = matcher(rlistPatt[j], mat[i]);
                // auto efend = chrono::system_clock::now();
                // chrono::duration<double> elapsed_seconds = efend-start2;
                // chrono::duration<double> total_time = total_time + elapsed_seconds;
                counter++;

               if (idx != -1){
                for(int k = 0; k < rlistPatt[j].size(); k++){
                    disp[i][idx] = rlistPatt[j][k];
                    idx++;
                }
                printmatrix(disp);
                cout << '\n';
            } 
            }
        }

        if (idx == -1){
        //VERTIKAL 
        
        //inisialisasi vector of char veretical
            for (int i=0; i< mat[0].size(); i++){
                vector<char> vertical;
                for(int l=0; l<mat.size(); l++){
                    vertical.push_back(mat[l][i]);
                }
                // atas ke bawah
                // auto start = chrono::system_clock::now();
                idx = matcher(listPatt[j], vertical);
            // auto end = chrono::system_clock::now();
            // chrono::duration<double> elapsed_seconds = end-start;
            // chrono::duration<double> total_time = total_time + elapsed_seconds;
            counter++;
                if (idx != -1){
                    for(int k = 0; k < listPatt[j].size(); k++){
                        disp[idx][i] = listPatt[j][k];
                        idx++;
                    }
                    printmatrix(disp);
                    cout << '\n';
                }
                else {
                    // auto start2 = chrono::system_clock::now();
                    idx = matcher(rlistPatt[j], vertical);
                    // auto efend = chrono::system_clock::now();
                    // chrono::duration<double> elapsed_seconds = efend-start2;
                    // chrono::duration<double> total_time = total_time + elapsed_seconds;
                    counter++;
                    if (idx != -1){
                        for(int k = 0; k < rlistPatt[j].size(); k++){
                            disp[idx][i] = rlistPatt[j][k];
                            idx++;
                        }
                        printmatrix(disp);
                        cout << '\n';
                }

                }
            }
        }


        if (idx == -1){
        //DIAGONAL

            //Diagonal kiri atas ke kanan bawah segitiga atas
            for(int ltc = 0; ltc < col-1; ltc++){
                vector<char> diagonalLR;
                int li = 0;
                int lj = ltc;
                while ((li < row) && (lj < col)){
                    diagonalLR.push_back(mat[li][lj]);
                    li++;
                    lj++;
                }
                // auto start = chrono::system_clock::now();
                idx = matcher(rlistPatt[j], diagonalLR);
                // auto end = chrono::system_clock::now();
                // chrono::duration<double> elapsed_seconds = end-start;
                // chrono::duration<double> total_time = total_time + elapsed_seconds;
                counter++;
                if (idx != -1){
                    for(int k = 0; k < rlistPatt[j].size(); k++){
                        disp[0+idx][ltc+idx] = rlistPatt[j][k];
                        idx++;
                    }
                    printmatrix(disp);
                    cout << '\n';
                }
                else{
                    // auto start2 = chrono::system_clock::now();
                    idx = matcher(listPatt[j], diagonalLR);
                    // auto efend = chrono::system_clock::now();
                    // chrono::duration<double> elapsed_seconds = efend-start2;
                    // chrono::duration<double> total_time = total_time + elapsed_seconds;
                    counter++;
                    if (idx != -1){
                        for(int k = 0; k < listPatt[j].size(); k++){
                            disp[0+idx][ltc+idx] = listPatt[j][k];
                            idx++;
                        }
                        printmatrix(disp);
                        cout << '\n';
                    }

                }
            }
        }


        if (idx == -1){
        //Diagonal kiri atas ke kanan bawah segitiga bawah
        for(int ltc = 0; ltc < row-1; ltc++){
            vector<char> diagonalLR;
            int li = ltc;
            int lj = 0;
            while ((li < row) && (lj < col)){
                diagonalLR.push_back(mat[li][lj]);
                li++;
                lj++;
            }
            // auto start = chrono::system_clock::now();
            idx = matcher(rlistPatt[j], diagonalLR);
            // auto end = chrono::system_clock::now();
            // chrono::duration<double> elapsed_seconds = end-start;
            // chrono::duration<double> total_time = total_time + elapsed_seconds;
            counter++;
            if (idx != -1){
                for(int k = 0; k < rlistPatt[j].size(); k++){
                    disp[ltc+idx][0+idx] = rlistPatt[j][k];
                    idx++;
                }
                printmatrix(disp);
                cout << '\n';
            }
            else{
                // auto start2 = chrono::system_clock::now();
                idx = matcher(listPatt[j], diagonalLR);
                // auto efend = chrono::system_clock::now();
                // chrono::duration<double> elapsed_seconds = efend-start2;
                // chrono::duration<double> total_time = total_time + elapsed_seconds;
                counter++;
                if (idx != -1){
                    for(int k = 0; k < listPatt[j].size(); k++){
                        disp[ltc+idx][0+idx] = listPatt[j][k];
                        idx++;
                    }
                    printmatrix(disp);
                    cout << '\n';
                }

            }
        }
        }

        if (idx == -1){
        //Diagonal kanan atas ke kiri bawah segitiga atas
        for(int rtc = 1; rtc < col; rtc++){
            vector<char> diagonalLR;
            int li = 0;
            int lj = rtc;
            while ((li < row) && (lj >= 0)){
                diagonalLR.push_back(mat[li][lj]);
                li++;
                lj--;
            }
            // auto start = chrono::system_clock::now();
            idx = matcher(rlistPatt[j], diagonalLR);
            // auto end = chrono::system_clock::now();
            // chrono::duration<double> elapsed_seconds = end-start;
            // chrono::duration<double> total_time = total_time + elapsed_seconds;
            counter++;
            if (idx != -1){
                for(int k = 0; k < rlistPatt[j].size(); k++){
                    disp[0+idx][rtc-idx] = rlistPatt[j][k];
                    idx++;
                }
                printmatrix(disp);
                cout << '\n';
            }
            else{
                // auto start2 = chrono::system_clock::now();
                idx = matcher(listPatt[j], diagonalLR);
                // auto efend = chrono::system_clock::now();
                // chrono::duration<double> elapsed_seconds = efend-start2;
                // chrono::duration<double> total_time = total_time + elapsed_seconds;
                counter++;
                if (idx != -1){
                    for(int k = 0; k < listPatt[j].size(); k++){
                        disp[0+idx][rtc-idx] = listPatt[j][k];
                        idx++;
                    }
                    printmatrix(disp);
                    cout << '\n';
                }

            }
        }
        }


        if (idx == -1){
        //Diagonal kanan atas ke kiri bawah segitiga bawah
        for(int ltc = 0; ltc < row-1; ltc++){
            vector<char> diagonalLR;
            int li = ltc;
            int lj = col-1;
            while ((li < row) && (lj >= 0)){
                diagonalLR.push_back(mat[li][lj]);
                li++;
                lj--;
            }
            // auto start = chrono::system_clock::now();
            idx = matcher(rlistPatt[j], diagonalLR);
            // auto end = chrono::system_clock::now();
            // chrono::duration<double> elapsed_seconds = end-start;
            // chrono::duration<double> total_time = total_time + elapsed_seconds;
            counter++;
            if (idx != -1){
                for(int k = 0; k < rlistPatt[j].size(); k++){
                    disp[ltc+idx][col-1-idx] = rlistPatt[j][k];
                    idx++;
                }
                printmatrix(disp);
                cout << '\n';
            }
            else{
                // auto start2 = chrono::system_clock::now();
                idx = matcher(listPatt[j], diagonalLR);
                // auto efend = chrono::system_clock::now();
                // chrono::duration<double> elapsed_seconds = efend-start2;
                // chrono::duration<double> total_time = total_time + elapsed_seconds;
                counter++;
                if (idx != -1){
                    for(int k = 0; k < listPatt[j].size(); k++){
                        disp[ltc+idx][col-1-idx] = listPatt[j][k];
                        idx++;
                    }
                    printmatrix(disp);
                    cout << '\n';
                }

            }
        }
        }


        

    }
    auto end = chrono::system_clock::now();
    chrono::duration<double> elapsed_seconds = end-start;
    cout << "total perbadingan: " << counter << endl;
    cout << "elapsed time: " << elapsed_seconds.count() << "s\n";
    return 0;
}
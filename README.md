# Word Search Puzzle Solver 
## Tugas Kecil 1 - IF2211 Strategi Algoritma

## 13520070 - Raden Haryosato Wisjnunandono

<br>

## Deskripsi singkat

Program untuk menyelesaikan word search puzzle menggunakan algoritma brute force. Pengguna dapat memasukkan puzzle dalam bentuk file '.txt' pada folder test. Program akan mencari kata dalam arah horizontal, vertikal, dan diagonal dari kanan ke kiri dan kiri ke kanan sehingga total ada 8 arah.

Directory :

- bin : executable files 
- doc : laporan
- src : source code
- test : all word search input files

<br>

## Program Execution Tutorial
## Windows
To run the program : 
1. Open terminal (Windows Command Prompt)
2. Untuk me-run program
```sh
cd Tucil1_13520070
cd bin
.\main.exe
```
3. Program akan meminta pengguna untuk memasukkan nama file (pilih file yang ada dalam folder test)
```
masukkan nama file :
```
4. contoh menggunakan `small_1.txt`
```
masukkan nama file : small_1.txt
```
5. Program akan mencari pattern soal dengan pendekatan brute force

<br>

Untuk recompile :
1. Open terminal (Windows Command Prompt)
2. To recompile:
```sh
cd Tucil1_13520070
cd src
g++ fileinput.hpp fileinput.cpp solver.hpp solver.cpp main.cpp -o ../bin/main
```
3. Untuk me-run program
```
cd ..\bin
.\main.exe
```

<br>

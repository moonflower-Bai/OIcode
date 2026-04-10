#include <bits/stdc++.h>
#include <cstddef>
#include <cstdlib>
using namespace std;
array<int, 4> plain_text[4];
int chiper_text[10];
int key_text[10];
map<int, int> sbox = {
    {0x0, 0xE}, {0x1, 0x4}, {0x2, 0xD}, {0x3, 0x1},
    {0x4, 0x2}, {0x5, 0xF}, {0x6, 0xB}, {0x7, 0x8},
    {0x8, 0x3}, {0x9, 0xA}, {0xA, 0x6}, {0xB, 0xC},
    {0xC, 0x5}, {0xD, 0x9}, {0xE, 0x0}, {0xF, 0x7}
};
map<int, int> pbox = {
    {1, 1},   {2, 5},   {3, 9},   {4, 13},
    {5, 2},   {6, 6},   {7, 10},  {8, 14},
    {9, 3},   {10, 7},  {11, 11}, {12, 15},
    {13, 4},  {14, 8},  {15, 12}, {16, 16}
};
int l = 4, m = 4, nr = 4;
int main(){
    for(int i = 0; i < 4; i++){
        string num;
        cin >> num;
        plain_text[i] = strtol(num.c_str(), NULL, 2);
    }
    for(int i = 0; i < 8; i++){
        string num;
        cin >> num;
        key_text[i] = strtol(num.c_str(), NULL, 2);
    }
    array<int, 4> w[10];
    eq(w)
    for(int i = 0; i < 8; i++){

    }
    return 0;
}
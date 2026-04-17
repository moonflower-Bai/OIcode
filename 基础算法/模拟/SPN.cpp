#include <array>
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
array<int, 17> plain_text;
int chiper_text[33];
int key_text[33];
map<int, int> sbox = {{0x0, 0xE}, {0x1, 0x4}, {0x2, 0xD}, {0x3, 0x1}, {0x4, 0x2}, {0x5, 0xF}, {0x6, 0xB}, {0x7, 0x8},
                      {0x8, 0x3}, {0x9, 0xA}, {0xA, 0x6}, {0xB, 0xC}, {0xC, 0x5}, {0xD, 0x9}, {0xE, 0x0}, {0xF, 0x7}};
map<int, int> pbox = {{1, 1}, {2, 5},  {3, 9},   {4, 13},  {5, 2},  {6, 6},  {7, 10},  {8, 14},
                      {9, 3}, {10, 7}, {11, 11}, {12, 15}, {13, 4}, {14, 8}, {15, 12}, {16, 16}};
int l = 4, m = 4, nr = 4;

array<int, 17> array_xor(array<int, 17> a, array<int, 17> b)
{
	array<int, 17> res;
	for (int i = 1; i <= 16; i++) {
		res[i] = a[i] ^ b[i];
	}
	return res;
}
array<int, 17> array_xor(array<int, 17> a, int *b)
{
	array<int, 17> res;
	for (int i = 1; i <= 16; i++) {
		res[i] = a[i] ^ b[i];
	}
	return res;
}
array<int, 17> f_sbox(array<int, 17> a)
{
	array<int, 17> res;
	for (int i = 0; i < 4; i++) {
		int num = a[i * 4 + 1] * 8 + a[i * 4 + 2] * 4 + a[i * 4 + 3] * 2 + a[i * 4 + 4];
		int s_num = sbox[num];
		res[i * 4 + 1] = s_num / 8;
		res[i * 4 + 2] = (s_num % 8) / 4;
		res[i * 4 + 3] = (s_num % 4) / 2;
		res[i * 4 + 4] = s_num % 2;
	}
	return res;
}

int main()
{
	for (int i = 1; i <= 16; i++) {
		char num;
		cin >> num;
		if (num == '0') {
			plain_text[i] = 0;
		} else {
			plain_text[i] = 1;
		}
	}
	for (int i = 1; i <= 32; i++) {
		char num;
		cin >> num;
		if (num == '0') {
			key_text[i] = 0;
		} else {
			key_text[i] = 1;
		}
	}
	array<int, 17> w[10], u[10], v[10];
	w[0] = plain_text;
	for (int i = 1; i < nr; i++) {
		array<int, 17> key;
		for (int j = 1; j <= 16; j++) {
			key[j] = key_text[(4 * i - 4) + j];
		}
		u[i] = array_xor(w[i - 1], key);
		v[i] = f_sbox(u[i]);
		for (int j = 1; j <= 16; j++) {
			// w[i][j] = v[i][pbox[j + 1] - 1];
			w[i][pbox[j]] = v[i][j];
			// w[i][j] = v[i][pbox[j]];
		}
		// cout << "w:";
		// for (int j = 1; j <= 16; j++) {
		// 	printf("%d", w[i][j]);
		// 	if (j % 4 == 0) {
		// 		cout << " ";
		// 	}
		// }
		// cout << endl;
	}
	// cout << endl;
	array<int, 17> key;
	for (int j = 1; j <= 16; j++) {
		key[j] = key_text[(4 * nr - 3) + j - 1];
	}
	u[nr] = array_xor(w[nr - 1], key);
	v[nr] = f_sbox(u[nr]);
	for (int j = 1; j <= 16; j++) {
		key[j] = key_text[(4 * (nr + 1) - 3) + j - 1];
	}
	auto res = array_xor(v[nr], key);
	for (int i = 1; i <= 16; i++) {
		printf("%d", res[i]);
		if (i % 4 == 0) {
			cout << " ";
		}
	}
	cout << endl;
	return 0;
}
/*
input:
0010 0110 1011 0111
0011 1010 1001 0100 1101 0110 0011 1111
output:
1011 0101 0100 0110
correct answer:
1011 1100 1101 0110
*/
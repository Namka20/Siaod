#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>
using namespace std;

int pos(const char* s, const char* p, int n)
{
	int i, j;
	int lol, kek;

	for (lol = 0; p[lol]; lol++);
	for (kek = 0; s[kek]; kek++);

	for (i = 0; i <= kek - lol; i++) {
		for (j = 0; s[i + j] == p[j]; j++);
		if (j - lol == 1 && i == kek - lol && !(n - 1)) return i;
		if (j == lol)
			if (n - 1) n--;
			else return i;
	}
	return -1;
}
int main() {
	setlocale(LC_ALL, "rus");
	char x[30]; char y[33];
	int N, k, g;
	int ar[30];
	string line, a;
	ifstream f("C://Users//Admin//OneDrive//Ðàáî÷èé ñòîë//group.txt");
	cout << "ASCII êîä\n : ";
	k = 0;
	while (f >> N) {
		ar[k++] = N;
	}
	for (int i = 0; i < k; i++) {
		cout << ar[i] << " ";
	}
	f.close();
	cout << endl;
	cout << "Ïåðåâîä ñ ÿçûêà: \n";
	for (int i = 0; i < 30; i++) {
		y[i] = ar[i];
		cout << y[i] << "";
	}
	cout << endl;
	ofstream out("C://dvoich.txt", ios::binary | ios::out);
	out.write((char*)&y, sizeof y);
	out.close();

	ifstream in("C://Users//Admin//OneDrive//Ðàáî÷èé ñòîë//group_bi.txt", ios::binary | ios::in);
	in.read((char*)&x, sizeof x);
	in.close();
	cout << "Äàííûå èç ôàéëà:\n";
	cout << x << endl;
	cout << "Ââåäèòå íîìåð äëÿ ïîèñêà: \n";
	cin >> a;
	const char* s = x;
	const char* p = a.c_str();
	int i, n = 0;
	for (i = 1; n != -1; i++) {
		n = pos(s, p, i);

		if (n >= 0)
			cout << n << endl;
	}
	cout << "Ïîñëå óäàëåíèÿ:\n ";
	for (int i = 0; i <= 5; i++) {
		for (int j = 0; j < 30; ++j) {
			x[j] = x[j + 1];
		}
	}
	for (int i = 0; i <= 30; i++) {
		cout << x[i] << "";
	}
	return 0;
}
#pragma once
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
class tovar {
public:
	string nazvanie;
	int kolichestvo;
	int price;
	tovar(string s, int c, int p) {
		nazvanie = s;
		kolichestvo = c;
		price = p;
	}
	double summa(tovar* x, int i) {
		return(x[i].kolichestvo * x[i].price);
	}
	void zamenakolich(tovar* a, int l) {
		cout << "���-�� ������: " << endl;
		cin >> a[l - 1].kolichestvo;
	}
	void zamenaceny(tovar* a, int l) {
		cout << "���� ������: " << endl;
		cin >> a[l - 1].price;
	}
	void tabel(tovar* a, int t) {
		cout << "|" << setw(17) << "�������� ������" << setw(17) << "|" << setw(15) << "���-�� ������" << setw(15) << "|" << setw(13) << "���� ������" << setw(13) << "|" << setw(25) << "����� ��������� ������" << setw(25) << "|" << "\n";
		cout << "---------------------------------------------------------------------------------------------------------------------------------------------" << "\n";
		for (int i = 0; i < t; i++) {
			cout << "|" << setw(17) << a[i].nazvanie << setw(17) << "|" << setw(15) << a[i].kolichestvo << setw(15) << "|" << setw(13) << a[i].price << setw(13) << "|" << setw(25) << a->summa(a, i) << setw(25) << "|" << "\n";
		}
	}
};
#include "Header.h"
int main()
{
	setlocale(LC_ALL, "Russian");
	int t = 0;
	int k, l, col, q;
	string name;
	cout << "������� ���������� ����� ������: " << endl;
	cin >> t;
	tovar* a = (tovar*)operator new (sizeof(tovar) * t);
	cout << "������� ������ � ������: " << endl;
	cin.ignore();
	for (int i = 0; i < t - 1; i++) {
		cout << "�������� ������ � " << i + 1 << endl;
		getline(cin, name);
		cout << "���������� ������� ������: " << endl;
		cin >> col;
		cout << "���� �� ����� ������� ������: " << endl;
		cin >> q;
		cin.ignore();
		cout << "����� ��������� ����� ������� ������ = " << col * q;
		cout << endl;
		new(&a[i]) tovar(name, col, q);
	}
	new(&a[t - 1]) tovar("moloko", 22, 22);


	do {
		cout << "1. �������� ���-�� ������" << endl;
		cout << "2. �������� ���� ������" << endl;
		cout << "3. ������� �������" << endl;
		cout << "0. �����" << endl;
		cin >> k;
		switch (k) {
		case 1:
			cout << "������� ����� ������ ����� �������� ���-��: " << endl;
			cin >> l;
			if (l == 0 || l > t || l < 0)
				cout << "����� �� ������!" << endl;
			else
				a->zamenakolich(a, l);
			break;
		case 2:
			cout << "������� ����� ������ � �������� ������ �������� ����: " << endl;
			cin >> l;
			if (l == 0 || l > t || l < 0)
				cout << "����� �� ������!" << endl;
			else
				a->zamenaceny(a, l);
			break;
		case 3:
			a->tabel(a, t);
			break;
		}

		if (k != 0)
			system("pause");
	} while (k != 0);


	delete a;
	return 0;
}
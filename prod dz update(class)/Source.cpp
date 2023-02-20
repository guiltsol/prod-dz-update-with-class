#include "Header.h"
int main()
{
	setlocale(LC_ALL, "Russian");
	int t = 0;
	int k, l, col, q;
	string name;
	cout << "Введите количество видов товара: " << endl;
	cin >> t;
	tovar* a = (tovar*)operator new (sizeof(tovar) * t);
	cout << "Введите данные о товаре: " << endl;
	cin.ignore();
	for (int i = 0; i < t - 1; i++) {
		cout << "Название товара № " << i + 1 << endl;
		getline(cin, name);
		cout << "Количество данного товара: " << endl;
		cin >> col;
		cout << "Цена за штуку данного товара: " << endl;
		cin >> q;
		cin.ignore();
		cout << "Общая стоимость всего данного товара = " << col * q;
		cout << endl;
		new(&a[i]) tovar(name, col, q);
	}
	new(&a[t - 1]) tovar("moloko", 22, 22);


	do {
		cout << "1. Изменить кол-во товара" << endl;
		cout << "2. Изменить цену товара" << endl;
		cout << "3. Таблица товаров" << endl;
		cout << "0. Выход" << endl;
		cin >> k;
		switch (k) {
		case 1:
			cout << "Введите номер товара чтобы изменить кол-во: " << endl;
			cin >> l;
			if (l == 0 || l > t || l < 0)
				cout << "Товар не найден!" << endl;
			else
				a->zamenakolich(a, l);
			break;
		case 2:
			cout << "Введите номер товара у которого хотите изменить цену: " << endl;
			cin >> l;
			if (l == 0 || l > t || l < 0)
				cout << "Товар не найден!" << endl;
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
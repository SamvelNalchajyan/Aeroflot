#include <iostream>
#include <fstream>
#include <cstdlib>
#include <clocale>
#include "AEROFLOT.h"

#define SIZE 7
#define MAS_SIZE 30

using namespace std;

int main()
{
	setlocale(LC_CTYPE, "Russian");
	AEROFLOT* mas = new AEROFLOT[SIZE];
	/*............................................*/
	ifstream file;
	file.open("../file.txt");
	for (int i = 0; i < SIZE; i++)
	{
		char tmp1[MAS_SIZE];
		int tmp2;
		char tmp3[MAS_SIZE];
		file >> tmp1 >> tmp2 >> tmp3;
		mas[i] = AEROFLOT(tmp1, tmp2, tmp3);
		mas[i].Print();
		cout << endl;
	}
	file.close();
	cout << endl << "Отсортированный массив:" << endl;
	// Сортировка
	for (int i = 0; i < SIZE - 1; i++)
	{
		for (int j = 0; j < SIZE - i - 1; j++)
		{
			if (mas[j + 1] < mas[j])
			{
				AEROFLOT c(mas[j]);
				mas[j] = mas[j + 1];
				mas[j + 1] = c;
			}
		}
	}
	for (int i = 0; i < SIZE; i++)
	{
		mas[i].Print();
		cout << endl;
	}
	int a;
	do
	{
		cout << endl << "Введите название самолёта - ";
		char tmp[MAS_SIZE];
		cin >> tmp;
		int flag = 0;
		for (int i = 0; i < SIZE; i++)
		{
			if (mas[i] == tmp)
			{
				mas[i].Print();
				cout << endl;
				flag = 1;
			}
		}
		if (flag == 0)
		{
			cout << "Такого типа самолёта нет!" << endl;
		}
		cout << endl << "Для ввода типа самолёта введите \"1\"";
		cout << endl << "Для завершения введите \"0\"" << endl;
		cin >> a;
	} while (a == 1);
	/*............................................*/
	delete[] mas;
	system("pause");
	return 0;
}
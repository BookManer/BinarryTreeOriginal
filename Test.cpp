// Test.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <clocale>
#include <vector>
#include "Three.h"

using namespace std;

template<typename Y> void insertionSort(vector<Y>*& mass);
template<typename Y> void NogotSort(vector<Y>*& mass);
template<typename Y> void show(vector<Y>*& mass);

int main()
{
	setlocale(LC_ALL, "rus");
	int select;
	Three three;
	do
	{
		cout << "Выберите одно из действий:\n\t1 - Создать новый корень/узел дерева\n\t2 - Поиск узла\n\t3 - Показать узлы дерева\n\t4 - Удалить узел\n\t0 - Завершить программу.\nНапишите выбранное Вами действие: ";
		cin >> select;
		cout << endl << endl;
		switch (select)
		{
			case 0:
				return 0;
			case 1:
				int val, dData;
				cout << "Напишите значение узла: ";
				cin >> val;
				cout << endl << "Напишите дополнительное значение узла: ";
				cin >> dData;
				cout << endl << endl;
				three.addNode(val, dData);
				break;
			case 2:
				int vals;
				cout << "Напишите значение искомого узла: ";
				cin >> vals;
				cout << endl;
				cout << three.search(vals)->getData() << endl << endl;
				break;
			case 3:
				three.display(three.root);
				break;
			case 4:
				int vals2;
				cout << "Напишите значение удаляемого узла: ";
				cin >> vals2;
				cout << endl;
				three.deleteNode(vals2);
				break;
		}
	} while (select != 0);
	system("pause");
	return 0;
}

template<typename Y> void show(vector<Y>*& mass)
{     
	cout << mass->at(0);
	for (int i = 1; i < (mass->size()); i++)
	{
		cout << ", " << mass->at(i);
	}
	cout << "\n";
}

template<typename Y> void insertionSort(vector<Y>*& mass)
{
	int counter = 0;
	for (int i = 1; i < mass->size(); i++)
	{
		for (int j = i; j > 0 && mass->at(j - 1) > mass->at(j); j--)
		{
			counter++;
			cout << mass->at(j - 1) << " | " << mass->at(j) << endl;
			int tmp = mass->at(j-1);
			mass->at(j - 1) = mass->at(j);
			mass->at(j) = tmp;
			cout << mass->at(j - 1) << " | " << mass->at(j) << endl;
		}
	}
	cout << "Количество вставок: " << counter << endl;
}
template<typename Y> void NogotSort(vector<Y>*& mass)
{
	// в процессе (нет)
}

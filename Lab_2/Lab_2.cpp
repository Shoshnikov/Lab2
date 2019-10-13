#include <iostream>
#include <locale.h>

using namespace std;

int CorrectInput(int& value);

void PrintArr(int arr[], int lngth);

void PrintArrLikeNumber(int arr[], int lngth);

void Polindrom(int number);

int main()
{
	setlocale(LC_ALL, "RUS");
	cout << "Вариант 9. ИКБО-02-18. Шошников Иван\n";
	int length;
	cout << "Введите количество чисел\n";
	CorrectInput(length);
	int* Array = new int[length];
	cout << "Введите числа\n";
	for(int i = 0; i < length; i++)
		CorrectInput(Array[i]);
	PrintArr(Array, length);
	cout << "Следующие значения - полиндромы\n";
	for (int i = 0; i < length; i++)
		Polindrom(Array[i]);
	delete[] Array;
}

int CorrectInput(int& value)
{
	char fail;
	cin >> value;
	while (cin.fail())
	{
		cout << "Данные некорректны\n";
		cin.clear();
		cin >> fail;
		cin >> value;
	}
	return value;
}

void PrintArr(int arr[], int lngth)
{
	for (int i = 0; i < lngth; i++)
		cout << arr[i] << "\t";
	cout << endl;
}

void PrintArrLikeNumber(int arr[], int lngth)
{
	for (int i = 0; i < lngth; i++)
		cout << arr[i];
	cout << endl;
}

void Polindrom(int number)
{
	int num = number;
	bool polindrom = true;
	int count = 0;
	while (number) 
	{
		number /= 10;
		count++;
	}
	int* arr = new int[count];
	for (int i = 0; i < count; i++) 
	{
		arr[i] = num % 10;
		num /= 10;
	}
	int leftBorder = 0;
	int righBorder = count - 1;
	while (leftBorder <= righBorder) 
	{
		if (arr[leftBorder] != arr[righBorder])
			polindrom = false;
		leftBorder++;
		righBorder--;
	}
	if (polindrom)
		PrintArrLikeNumber(arr, count);
	delete[] arr;
}
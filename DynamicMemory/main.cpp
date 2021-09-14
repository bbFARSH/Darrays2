#include <iostream>
using std::cin;
using std::endl;
using std::cout;

void FillRand(int arr[], const unsigned int n);
void Print(int arr[], const unsigned int n);

void push_back(int** arr, int& n, int value);
int* pop_back(int arr[], int& n);
void main()
{
	setlocale(LC_ALL, "");
	int n;
	cout << "¬ведите размер массива: "; cin >> n;
	int* arr = new int[n];
	FillRand(arr, n);
	Print(arr, n);
	int value;
	cout << " ¬ведите добавл€емое значение : "; cin >> value;
    push_back(&arr, n, value);
	Print(arr, n);
	arr = pop_back(arr, n);
	//n++;
	Print(arr, n);
	delete[] arr;
}
void FillRand(int arr[], const unsigned int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 100;
	}

}
void Print(int arr[], const unsigned int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}

}
void push_back(int** arr, int& n, int value)
{
	cout << typeid(arr).name() << endl;
	int* buffer = new int[n + 1];
	for (int i = 0; i < n; i++)
	{
		buffer[i] = (*arr)[i];
	}
	//3) ”дал€ем исходный массив
	delete[] *arr;	
	*arr = buffer;
	(*arr)[n] = value;
	n++;
}
int* pop_back(int arr[], int& n)
{
	int* buffer = new int[--n];
	for (int i = 0; i < n; i++) buffer[i] = arr[i];
	delete[]	arr;
	return buffer;

}
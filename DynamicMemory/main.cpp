#include <iostream>
using std::cin;
using std::endl;
using std::cout;

void FillRand(int arr[], const unsigned int n);
void Print(int arr[], const unsigned int n);

int* push_back(int arr[], int& n, int value);
int* push_front(int arr[], int& n, int value1);
int* pop_back(int arr[], int& n);
int* insert(int arr[], int& n, int number, int value2);
int* pop_front(int arr[], int& n);
int* erase(int arr[], int& n, int number1);
void main()
{
	setlocale(LC_ALL, "Ru");
	int n;
	cout << "¬ведите размер массива: "; cin >> n;
	int* arr = new int[n];
	FillRand(arr, n);
	Print(arr, n);
	
	int value1;
	cout << "¬ведите добавл€емое значение: "; cin >> value1;
	arr = push_front(arr, n, value1);
	Print(arr, n);
	
	int value;
	cout << "¬ведите добавл€емое значение: "; cin >> value;
	arr = push_back(arr, n, value);
	Print(arr, n);
	
	Print(arr, n);
	arr = pop_back(arr, n);
	
	
	int value2;
	int number;
	cout << "¬ведите добавл€емое значение: "; cin >> value2;
	cout << "¬ведите индекс добавл€емого элемента: "; cin >> number;
	arr = insert(arr, n, number, value2);
	Print(arr, n);
	
	arr = pop_front(arr, n);
	Print(arr, n);
	
	int number1;
	cout << "¬ведите индекс удал€емого элемента: "; cin >> number1;
	arr = erase(arr, n, number1);
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
	cout << endl;

}
int* push_back(int arr[], int& n, int value)
{
	Print(arr, n);
	int* buffer = new int[n + 1];
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	//3) ”дал€ем исходный массив
	delete[] arr;
	arr = buffer;
	arr[n] = value;
	n++;
	return arr;
}
int* pop_back(int arr[], int& n)
{
	int* buffer = new int[--n];
	for (int i = 0; i < n; i++) buffer[i] = arr[i];
	delete[] arr;
	return buffer;

}
int* push_front(int arr[], int& n, int value1)
{
	int* buffer = new int[n + 1];
	for (int i = 0; i < n; i++)
	{
		buffer[i+1] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[0] = value1;
	n++;
	return arr;
}
int* insert(int arr[], int& n, int number, int value2)
{
	int* buffer = new int[n + 1];
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	for (int i = n - 1; i >= number; i--)
	{
		arr[i + 1] = arr[i];
	}
	arr[number] = value2;
	n++;
	return arr;
}
int* pop_front(int arr[], int& n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i--] = arr[i];
	}
	n--;
	return arr;
}
int* erase(int arr[], int& n, int number1)
{
	for (int i = number1; i < n - 1; i++)
	{
		arr[i] = arr[i + 1];
	}
	n--;
	return arr;
}
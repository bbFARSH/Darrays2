#include <iostream>
using std::cin;
using std::endl;
using std::cout;

int** allocate(const unsigned int rows, const unsigned int cols);
void clear(int** arr, int rows);
void FillRand(int arr[], const unsigned int n);
void FillRand(int** arr, const unsigned int rows, const unsigned int cols);
void Print(int arr[], const unsigned int n);
void Print(int** arr, const unsigned int rows, const unsigned int cols);
int* push_back(int arr[], int& n, int value);
int* push_front(int arr[], int& n, int value1);
int* pop_back(int arr[], int& n);
int* insert(int arr[], int& n, int number, int value2);
int* pop_front(int arr[], int& n);
int* erase(int arr[], int& n, int number1);

int** push_row_back(int** arr,  unsigned int& rows,  unsigned int cols);
//#define DYNAMICMEMORY_1
#define DYNAMICMEMORY_2
void main()
{
	setlocale(LC_ALL, "Ru");
#ifdef DYNAMICMEMORY_1
	int n;
	cout << "Введите размер массива: "; cin >> n;
	int* arr = new int[n];
	FillRand(arr, n);
	Print(arr, n);

	int value1;
	cout << "Введите добавляемое значение: "; cin >> value1;
	arr = push_front(arr, n, value1);
	Print(arr, n);

	int value;
	cout << "Введите добавляемое значение: "; cin >> value;
	arr = push_back(arr, n, value);
	Print(arr, n);

	Print(arr, n);
	arr = pop_back(arr, n);


	int value2;
	int number;
	cout << "Введите добавляемое значение: "; cin >> value2;
	cout << "Введите индекс добавляемого элемента: "; cin >> number;
	arr = insert(arr, n, number, value2);
	Print(arr, n);

	arr = pop_front(arr, n);
	Print(arr, n);

	int number1;
	cout << "Введите индекс удаляемого элемента: "; cin >> number1;
	arr = erase(arr, n, number1);
	Print(arr, n);
	delete[] arr;
#endif // DYNAMICMEMORY_1
	unsigned int rows;
	unsigned int cols;
	cout << "Введите количество строк: "; cin >> rows;
	cout << "Введите количество элементов строки: "; cin >> cols;
	int** arr = allocate(rows, cols);
	FillRand(arr, rows, cols);
	Print(arr, rows, cols);
	cout << "С добавлением строки";
#ifdef Les2
	int** arr = allocate(rows, cols);
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//////////////////      Объявление двумерного динамического массива       //////////////////////////////////////////
	// 1) Объявляем указатель на указатель, и сохраняем в него адрес массива указателей: 
	int** arr = new int* [rows];
	// 2) Создаем строки ДДМ :
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols] {};
	}
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//////////////////      Обращения к элементам двумерного ДДМ:        /////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#endif // Les2
	arr = push_row_back(arr, rows, cols);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << *(*(arr + i) + j) << "\t";
		}
		cout << endl;
	}	
	FillRand(arr, rows, cols);//заполняем значениями только новую добавленную строку
	Print(arr, rows, cols);
	clear(arr, rows);	
}
int** allocate(int const unsigned rows, const unsigned int cols)
{
	int** arr = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols] {};
	}
	return arr;
}
void clear(int** arr, int rows)
{
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	delete arr;
}
void FillRand(int arr[], const unsigned int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 100;
	}
}
void FillRand(int** arr, const unsigned int rows, const unsigned int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % 100;
		}
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
void Print(int** arr, const unsigned int rows, const unsigned int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
}
int* push_back(int arr[], int& n, int value)
{
	Print(arr, n);
	int* buffer = new int[n + 1];
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	//3) Удаляем исходный массив
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
		buffer[i + 1] = arr[i];
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
int** push_row_back(int** arr, unsigned int& rows, unsigned int cols)
{
	//1) Создаем буферный массив указателей
	int** buffer = new int* [rows + 1];
	//2) Копируем адреса строк в буферный массив указателей
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = arr[i];
	}
	//3) Удаляем исходный массив указателей
	delete[] arr;
	//4) Подменяем исходный массив буферным
	arr = buffer;
	//5) Добавляем в исходный массив новую строку
	arr[rows] = new int[cols] {};
	//6) Увелечиваем количество строк
	rows++;	
	//7) ВОзвращаем новый массив на место вызова
	return arr;
}
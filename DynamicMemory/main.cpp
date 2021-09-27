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
	cout << "������� ������ �������: "; cin >> n;
	int* arr = new int[n];
	FillRand(arr, n);
	Print(arr, n);

	int value1;
	cout << "������� ����������� ��������: "; cin >> value1;
	arr = push_front(arr, n, value1);
	Print(arr, n);

	int value;
	cout << "������� ����������� ��������: "; cin >> value;
	arr = push_back(arr, n, value);
	Print(arr, n);

	Print(arr, n);
	arr = pop_back(arr, n);


	int value2;
	int number;
	cout << "������� ����������� ��������: "; cin >> value2;
	cout << "������� ������ ������������ ��������: "; cin >> number;
	arr = insert(arr, n, number, value2);
	Print(arr, n);

	arr = pop_front(arr, n);
	Print(arr, n);

	int number1;
	cout << "������� ������ ���������� ��������: "; cin >> number1;
	arr = erase(arr, n, number1);
	Print(arr, n);
	delete[] arr;
#endif // DYNAMICMEMORY_1
	unsigned int rows;
	unsigned int cols;
	cout << "������� ���������� �����: "; cin >> rows;
	cout << "������� ���������� ��������� ������: "; cin >> cols;
	int** arr = allocate(rows, cols);
	FillRand(arr, rows, cols);
	Print(arr, rows, cols);
	cout << "� ����������� ������";
#ifdef Les2
	int** arr = allocate(rows, cols);
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//////////////////      ���������� ���������� ������������� �������       //////////////////////////////////////////
	// 1) ��������� ��������� �� ���������, � ��������� � ���� ����� ������� ����������: 
	int** arr = new int* [rows];
	// 2) ������� ������ ��� :
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols] {};
	}
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//////////////////      ��������� � ��������� ���������� ���:        /////////////////////////////////////////
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
	FillRand(arr, rows, cols);//��������� ���������� ������ ����� ����������� ������
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
	//3) ������� �������� ������
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
	//1) ������� �������� ������ ����������
	int** buffer = new int* [rows + 1];
	//2) �������� ������ ����� � �������� ������ ����������
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = arr[i];
	}
	//3) ������� �������� ������ ����������
	delete[] arr;
	//4) ��������� �������� ������ ��������
	arr = buffer;
	//5) ��������� � �������� ������ ����� ������
	arr[rows] = new int[cols] {};
	//6) ����������� ���������� �����
	rows++;	
	//7) ���������� ����� ������ �� ����� ������
	return arr;
}
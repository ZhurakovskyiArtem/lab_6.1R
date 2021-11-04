#include <iostream>
#include <cmath>
#include <time.h>
#include <iomanip>
using namespace std;
void Create(int* a, const int size, const int Low, const int High, int i)
{
		a[i] = Low + rand() % (High - Low + 1);
		if (i < size - 1)
			Create(a, size, Low, High, i + 1);
}
void Print(int* a, const int size, int i)
{
	cout << "a[" << setw(2) << i << " ] = " << setw(4) << a[i] << endl;
	if (i < size - 1)
		Print(a, size, i + 1);
	else
		cout << endl;
}
int Sum(int* a, const int size, int i, int S)
{
	if (a[i] % 2 == 0 && a[i] > 0)
		S += a[i];
	if (i < size - 1 )
		return Sum(a, size, i + 1, S);
	else
		return S;
}
int K(int* a, const int size, int i, int k)
{
	if (a[i] % 2 == 0 && a[i] > 0)
		k++;
	if (i < size - 1 && a[i] % 2 == 0 && a[i] > 0)
		a[i] = 0;
		if(i < size - 1)
		return K(a, size, i + 1, k);
	else
		return k;
}
int main()
{
	srand((unsigned)time(NULL));
	const int n = 25;
	int a[n];
	int Low = -20;
	int High = 30;
	Create(a, n, Low, High, 0);
	Print(a, n, 0);
	cout << "Sum =" << Sum(a, n, 0, 0) << endl;
	cout << "K = " << K(a, n, 0, 0) << endl;
	Print(a, n, 0);
	return 0;
}
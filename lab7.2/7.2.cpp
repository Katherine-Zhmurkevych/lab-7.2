//ітераційний спосіб
#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

void create(int** a, const int n, const int Low, const int High)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			a[i][j] = Low + rand() % (High - Low + 1);
}

void print(int** a, const int n)
{
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << setw(4) << a[i][j];
		cout << endl;
	}
	cout << endl;
}

void replace (int** a, int rows, int cols, int low)
{
	int maxTemp;
	int temp;
	int maxElement[3];
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			maxElement[0] = low;
			if (i == j) {
				for (int z = 0; z < cols; z++) {
					if (a[i][z] > maxElement[0]) {
						maxElement[0] = a[i][z];
						maxElement[1] = i;
						maxElement[2] = z;
					}
				}
				if (a[i][j] < maxElement[0]) {
					a[i][maxElement[2]] = a[i][j];
					a[i][j] = maxElement[0];
				}
			}
		}
	}
}

int main()
{
	srand((unsigned)time(NULL));
	int low;
	cout << "Low = " << endl; cin >> low;
	int high;
	cout << "High = " << endl; cin >> high;
	int n;
	cout << "n = "; cin >> n;
	int** a = new int* [n];
	for (int i = 0; i < n; i++)
		a[i] = new int[n];
	create(a, n, low, high);
	print(a, n);
	replace(a, n, n, low);
	cout << "Modified matrix:" << endl;
	print(a, n);
	return 0;
}
#include <iostream>
using namespace std;
//Алгоритм вычисления значения многочлена по схеме Горнера

int Gorner(int a[], long long n, int x) {
	long long s = a[n];
	for (int i = 1; i < n + 1; i++) {
		if (i <= n)
		{
			s = s * x + a[n - i];
		}
	}
	return s;
}


int main()
{
	setlocale(LC_ALL, "rus");
	unsigned long long n = 1;
	int x = 25;
	for (int i = 0; i <= 28; i++) {
		n *= 2;
		cout << "N = " << n << " ";
		int* a = new int[n + 1];
		for (int j = 0; j < n + 1; j++) {
			a[j] = rand() % 1001 - 500;
		}

		clock_t start = clock();
		cout << "Ответ: " << Gorner(a, n, x) << "; ";
		double duration = (clock() - start) / (double)CLOCKS_PER_SEC;
		cout << " time: " << duration << '\n';
		delete[] a;
	}
	return 0;
}

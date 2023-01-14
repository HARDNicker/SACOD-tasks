#include <iostream>
#include <vector>
#include <string>

using namespace std;
typedef vector<int> lnum;

//Для натуральных чисел A и B(1 <= A <= 9, 1 <= B <= 104) требуется вычислить значение AB.

void Cin_Long(lnum &a,string s) { //Считываем строку в string, и затем преобразовываем её в вектор:
			a.push_back(atoi(s.c_str()));
}
void Cout_Long(lnum a){ //Сначала мы выводим самый последний элемент вектора (или 0, если вектор пустой)
	printf("%d", a.empty() ? 0 : a.back());
	for (int i = a.size() - 2; i >= 0; --i)//а затем выводим все оставшиеся элементы вектора, дополняя их нулями до 9 символов
		printf("%09d", a[i]);
}
lnum Umn_Long(int base,int st,lnum a,lnum b) {
	while (true) {
		lnum c(a.size() + b.size());
		for (int i = 0; i < a.size(); ++i)
			for (int j = 0, carry = 0; j < b.size() || carry; ++j) {
				long long cur = c[i + j] + a[i] * 1ll * (j < b.size() ? b[j] : 0) + carry;
				c[i + j] = int(cur % base);
				carry = int(cur / base);
			}
		while (c.size() > 1 and c.back() == 0)
			c.pop_back();
		a = c;
		st -= 1;
		if (st == 1)
			return c;
	}
}

int main()
{
	const int base = 1000*1000*1000;
	setlocale(LC_ALL, "rus");
	cout << "Введите число (1 <= A <= 9) = ";
	int a;
	cin >> a;
	if (a >= 1 and a <= 9) {
		string Num = to_string(a);
		cout << "Введите степень(1 <= B <= 10000) = ";
		int st;
		cin >> st;
		if (st >= 1 and st <= 10000)
		{ 
			lnum va, vb,vc;
			Cin_Long(va, Num);
			Cin_Long(vb, Num);
			vc = Umn_Long(base, st, va, vb);
			cout << "Полученное число = ";
			Cout_Long(vc);
		}
		else
			cout << "Неверная степень";
	}
	else
		cout << "Неверное число ";
}


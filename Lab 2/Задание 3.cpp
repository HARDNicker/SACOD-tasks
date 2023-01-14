#include <string>
#include <iostream>
using namespace std;
//Написать программу перевода числа, записанного в римской системе счисления в арабскую десятичную систему счисления.

string Translate(int n) {
    string result = "\0";
    int numbers[] = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
    string words[] = { "M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I" };
    for (int i = 0; i < 13; i++) {
        while (n >= numbers[i])
        {
            result += words[i]; 
            n -= numbers[i];
        }
    }
    return result;
}

int main()
{
	setlocale(LC_ALL, "rus");
	cout << "Введите число в римской системе счисления : ";
	int NumberRim;
	cin >> NumberRim;
    cout << Translate(NumberRim);
}
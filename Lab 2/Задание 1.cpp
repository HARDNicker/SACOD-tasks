#include <iostream>
#include <cmath>
using namespace std;
//Составить программу перевода натурального числа из системы счисления с основанием m в систему счисления с основанием n, используя десятичную систему счисления:

int main()
{
    setlocale(LC_ALL, "russian");
    cout << "Введите натуральное число: " << endl;
    int Nat;
    cin >> Nat;
    cout << "Введите систему счистления введенного числа " << endl;
    int m;
    cin >> m;
    int count = 1, result = 0;
    do
    {
        int mod = Nat % 10;
        result += count * mod;
        count *= m;
        Nat /= 10;
    } while (Nat);
    int i = -1;
    int n,c = 0;
    cout << "Введите новую систему счистления" << endl;
    cin >> n;
    for (int b = result; b != 0; b = b / n) {
        int a = 0;
        i += 1;
        a = b % n;
        c += a * (pow(10,i));
    }
    cout << c;
}


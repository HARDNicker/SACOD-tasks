#include <iostream>
#include <stdio.h> //printf
#include <conio.h> // putch, getch

using namespace std;
//----------------------------------------------------------
// Функция вывода двоичного представления области памяти
// Вывод осуществляется побайтно от старших байт к младшим,
// впереди старшие биты
void BinOut(unsigned char* Buf, int len) {
    int i, j;
    unsigned char byte;
    for (i = len - 1; i >= 0; i--)
        for (j = 1, byte = Buf[i]; j <= 8; byte <<= 1, j++)
            _putch(byte & 0x80 ? '1' : '0'); //0x80  шестнадцатеричное число
    printf("\n");
}
//----------------------------------------------------------
// Функция ввода двоичного представления области памяти
// с клавиатуры
// Ввод осуществляется побайтно от старших байт к младшим,
// впереди старшие биты
void BinIn(unsigned char* Buf, int len) {
    int i, j;
    char ch;
    for (i = len - 1; i >= 0; i--)
        for (j = 1, Buf[i] = 0; j <= 8; Buf[i] = (Buf[i] << 1) + (ch - '0'), j++) {
            while ((ch = _getch()) != '0' && ch != '1');
            _putch(ch);
        }
    printf("\n");
}

int main() {
    // (unsigned short)
    unsigned short n;
    cout << "Enter number of a unsigned short type: ";
    cin >> n;
    cout << "This is its binary representation:" << endl;
    BinOut((unsigned char*)&n, sizeof(n));
    cout << "Enter binary representation of a unsigned short number:" << endl;
    BinIn((unsigned char*)&n, sizeof(n));
    cout << "This is its value: " << n << endl;
    // (long double)
    long double x;
    cout << "Enter number of a long double type: ";
    cin >> x;
    cout << "This is its binary representation:" << endl;
    BinOut((unsigned char*)&x, sizeof(x));
    cout << "Enter binary representation of a long double number:" << endl;
    BinIn((unsigned char*)&x, sizeof(x));
    cout << "This is its value: " << x << endl;
    //(Array)
    double a[3];
    for (int i = 0; i <= 2; i++) {
        cout << "Enter number of a array type: ";
        cin >> a[i];
    }
    cout << "This is its binary representation:" << endl;
    BinOut((unsigned char*)&a, sizeof(a));
    cout << "Enter binary representation of a array number:" << endl;
    BinIn((unsigned char*)&a, sizeof(a));
    for (int i = 0; i <= 2; i++) {
            cout << "This is its value: "<<endl;
            cout << a[i];
    }
    return 0;
}
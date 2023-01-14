
#include <iostream>
using namespace std;
//Сортировка чёт-нечёт

/*Является модификацией
пузырьковой сортировки. Суть
модификации в том, чтобы
сравнивать элементы массива под
чётными и нечётными
индексами с последующими
элементами независимо.*/

int cnt_cmp=0, cnt_ass=0;
int assign(int* dest, int src) {
    ++cnt_ass;
    return (*dest = src);
}


bool lt(int lh, int rh) {
    ++cnt_cmp;
    return lh < rh;
}

bool le(int lh, int rh) {
    ++cnt_cmp;
    return lh > rh;
}

template <typename T, size_t N>
void Sorting_Even_Odd(T(&array)[N]) {
    for (size_t i = 0; lt(i, N); i = i + 1)
    {   
        cnt_ass++;
        for (size_t j = (i % 2) ? 0 : 1; lt(j + 1, N); j = j + 2) {
            cnt_ass++;
            if (le(array[j], array[j + 1])) {
                swap(array[j], array[j + 1]);
                cnt_ass += 3;
            }
        }
        cnt_cmp++; //сравнение в (i % 2) ? 0 : 1
    }
    cout << "Sravnenii= " << cnt_cmp << " Prisvoenii= " << cnt_ass <<" Sum = "<< cnt_cmp + cnt_ass << endl;
    cnt_cmp = 0;
    cnt_ass = 0;
}

template <typename T, size_t N>
void Best_Array(T(&array)[N])
{
    for (int i = 0; i < N; i++)
        array[i] = i;
}

template <typename T, size_t N>
void Worst_Array(T(&array)[N])
{
    for (int i = 0; i < N; i++)
        array[i] = N-i;
}

template <typename T, size_t N>
void Random_Array(T(&array)[N])
{
    for (int i = 0; i < N; i++)
        array[i] = rand() % 51 - 10;
}

template <typename T, size_t N>
void Do_Array(T(&array)[N]) {
    cout << "Best_Array: " << endl;
    Best_Array(array);
    Sorting_Even_Odd(array);
    cout << "Worst_Array: " << endl;
    Worst_Array(array);
    Sorting_Even_Odd(array);
    cout << "Random_Array: " << endl;
    Random_Array(array);
    Sorting_Even_Odd(array);
}

int main()
{
    int array_10[10];
    int array_20[20];
    int array_50[50];
    int array_100[100];
    cout << "10 elements"<< endl;
    Do_Array(array_10);
    cout << "20 elements" << endl;
    Do_Array(array_20);
    cout << "50 elements" << endl;
    Do_Array(array_50);
    cout << "100 elements" << endl;
    Do_Array(array_100);
}


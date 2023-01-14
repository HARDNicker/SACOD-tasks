#include <iostream>
#include <vector>
using namespace std;
/*1.Сортировка Шелла с подбором шага методом Кнута
2.Бинарный поиск
3.Найти два элемента, сумма которых равна заданному числу*/

template <typename T>
void ShellSort_Knut(vector<T> array)
{
    int h = 1;
    while (h < N / 3) {
        h = 3 * h + 1;
    }

    for (int h; h > 0; h /= 3)
    {
        for (int i = h; i < N; i++)
        {
            int tmp = array[i];
            int j;
            for (j = i + 1; j >= h; j -= h)
            {
                if (tmp < array[j - h])
                    array[j] = array[j - h];
                else
                    break;
            }
            array[j] = tmp;
        }
    }
}

template <typename T>
void Random_Array(vector<T> array)
{
    for (int i = 0; i < array.size(); i++)
        array[i] = rand() % 101 - 10;
}

template <typename T>
int Binary_Search(vector<T> array, int key)
{
    int l = 0;
    int r = N;
   

    while (l < r) {
        int mid = (l + r) / 2; // считываем срединный индекс отрезка [l,r]

        if (array[mid] > key) r = mid; // проверяем, какую часть нужно отбросить с поиска
        else l = mid + 1;
    }
    r--; // уменьшаем на один 

    if (array[r] == key) return r;
    else return -1;
}

template <typename T>
pair<int, int> Search_Summ(vector<T> array,int Number)
{
    // индексы
    int lt = 0;
    int rt = array.size() - 1;

    while (lt != rt)
    {
        int cursum = array[lt] + array[rt];
        if (cursum < Number)
            lt++;
        else if (cursum > Number)
            rt--;
        else
        {
            return {lt, rt}
        }
    }
    return {-1, -1};
}
int main()
{
    const int n = 5;
    vector<int> array(n);
    Random_Array(array);
    ShellSort_Knut(array);

    int Number;
    cout << "Array: ";
    for (int i = 0; i < size(array); i++)
        cout << array[i] << " ";
    cout << " \n Need number : ";
    cin >> Number;

    pair<int, int> Result = Search_Summ(array, Number);
    if (Result.first != -1)
        cout <<"Elements " << array[Result.first]<< " + " << array[Result.second]<< " = "<<Number;
    else
        cout << "No Sum";     
}
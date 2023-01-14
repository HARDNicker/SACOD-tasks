#include <iostream>
#include <vector>
using namespace std;
//Сортировка Шелла с подбором шага в виде чисел Фибоначчи


int Fib(int i)
{
    unsigned long OldValue = 0;
    unsigned long Value = 1;
    unsigned long Hold;
    if (i < 1) return(0);
    for (int n = 2; n < i; n++)
    {
        Hold = Value;
        Value += OldValue;
        OldValue = Hold;
    }
    return(Value);
}

int cnt_cmp = 0, cnt_ass = 0;
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

bool ler(int lh, int rh) {
    ++cnt_cmp;
    return lh >= rh;
}

vector<int> calculate_nums(int N) {
    vector<int> Result{ 0, 1, 1 };
    int i = 3;
    while (Result.back() < N) {
        Result.push_back(Result[i - 1] + Result[i - 2]);
        i++;
    }
    Result.pop_back();
    return Result;
}

template <typename T, size_t N>
void ShellSort_Fib(T(&array)[N])
{
    int tmp,j;
    vector<int> fibs = calculate_nums(N); 
    ++cnt_ass;
    for (int i = fibs.size() - 1; i > 1; i--)
    { 
        int step = fibs[i];
        ++cnt_ass;
        for (int i = assign(&i,step); lt(i,N); assign(&i,i+1))
        {
            tmp = array[i];
            cnt_ass++;
            for (assign(&j, i); ler(j,step);  assign(&j, j - step))
            {
                if (lt(tmp, array[j - step]))
                    assign(&array[j] , array[j - step]);
                else
                    break;
            }
            assign(&array[j], tmp);
        }
    }
    cout << "Sravnenii= " << cnt_cmp << " Prisvoenii= " << cnt_ass << " Sum = " << cnt_cmp + cnt_ass << endl;
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
        array[i] = N - i;
}

template <typename T, size_t N>
void Random_Array(T(&array)[N])
{
    for (int i = 0; i < N; i++)
        array[i] = rand() % 51 - 10;
}

template<typename T, size_t N> 
void print(T (& array)[N]) {
    cout << "---Arrray--------------\n";
    for (auto x : array) {
        cout << x << " ";
    }
    cout << '\n';
    cout << "-------------------\n\n";

}

template <typename T, size_t N>
void Do_Array(T(&array)[N]) {
    cout << "Best_Array: " << endl;
    Best_Array(array);
    print(array);
    ShellSort_Fib(array);
    print(array);
    cout << "Worst_Array: " << endl;
    Worst_Array(array);
    print(array); 
    ShellSort_Fib(array); 
    print(array);
    cout << "Random_Array: " << endl; 
    Random_Array(array); 
    print(array);
    ShellSort_Fib(array); 
    print(array);
   
}
int main()
{
    int array_10[10];
    int array_20[20];
    int array_50[50];
    int array_100[100];
    cout << "10 elements" << endl;
    Do_Array(array_10);
    cout << "20 elements" << endl;
    Do_Array(array_20);
    cout << "50 elements" << endl;
    Do_Array(array_50);
    cout << "100 elements" << endl;
    Do_Array(array_100);
}


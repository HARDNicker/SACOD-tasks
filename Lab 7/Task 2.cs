using System;
//Дано число N,
//необходимо найти количество и вывести все способы представления его как сумму других M заданных положительных чисел или указать, что такого способа нет(каждое число можно использовать не более чем по одному разу)

namespace Задание_2
{
    internal class Program
    {
        public static int N, L, M, count;
        //NeedNumbers - частичное решение
        // N число 
        // L сумма всех чисел в массиве
        // M размер массива чисел
        // count число пар

        // метод ветвей и границ

        //cost - сумма чисел из массива ArrayOfNumbers которым соответствует значение 1 в NeedNumbers.
        //(сумма элементов, использованных в разложении на данный момент)
        //left – сумму оставшихся элементов.
        public static void Funk(int k, int cost, int left, ref int[] ArrayOfNumbers, ref int[] NeedNumbers)
        {
            if (cost > N || cost < N - left)
                return;
            if (k >= M)
                if (cost == N)
                {
                    Print(ref ArrayOfNumbers, ref NeedNumbers);
                    return;
                }
            NeedNumbers[k] = 1; //используем число k в разложении (k-номер числа в массиве)
            Funk(k + 1, cost + ArrayOfNumbers[k], left - ArrayOfNumbers[k], ref ArrayOfNumbers, ref NeedNumbers);
            NeedNumbers[k] = 0;//пропускаем число k в разложении
            Funk(k + 1, cost, left - ArrayOfNumbers[k], ref ArrayOfNumbers, ref NeedNumbers);
        }
        public static void Print(ref int[] ArrayOfNumbers, ref int[] NeedNumbers)
        {
            for (int j = 0; j < M; j++) //no one element
                if (ArrayOfNumbers[j] == N && NeedNumbers[j] == 1)
                    return;
            count++;
            Console.Write("{0} pair = ", count);
            for (int j = 0; j < M; j++)
                if (NeedNumbers[j] == 1)
                    Console.Write(ArrayOfNumbers[j] + " ");
            Console.WriteLine();
        }
        static void Main(string[] args)
        {
            Console.Write("Enter N: ");
            N = int.Parse(Console.ReadLine());
            Console.Write("Enter numbers of array M ");
            M = int.Parse(Console.ReadLine());
            int[] ArrayOfNumbers = new int[M];
            int[] NeedNumbers = new int[M];
            for (int i = 0; i < M; i++)
            {
                Console.Write("Enter number: ");
                ArrayOfNumbers[i] = int.Parse(Console.ReadLine());
                L += ArrayOfNumbers[i];
                if (ArrayOfNumbers[i] <= 0)
                {
                    Console.WriteLine("Error");
                    Console.ReadLine();
                    Environment.Exit(-1);
                }
            }
            /* Если на первом шаге
            перебирается самое большое число, то это приводит к тому, что ограничение на
            нижнюю и верхнюю границу нарушается раньше и соответственно раньше
            происходит исключение ненужных вариантов.*/
            Array.Sort(ArrayOfNumbers);
            Array.Reverse(ArrayOfNumbers);
            Funk(0, 0, L, ref ArrayOfNumbers, ref NeedNumbers);
            if (count == 0)
                Console.WriteLine("No solution");
            Console.ReadLine();
        }
    }
}
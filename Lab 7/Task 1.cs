using System;
//Дана шахматная доска размером N*N.
//Найдите количество способов расстановки на ней N ферзей, так чтобы они не били друг друга.

namespace Задание_1
{
    internal class Program
    {
        static int k = 0;

        /*Функция вызывается, когда ферзи "col"  
        уже размещены в столбцах от 0 до col -1.  
        Поэтому нам нужно проверить только левую сторону на наличие  
        атакующих ферзей */
        static bool IsSafe(int[,] board, int row, int col, int N)
        {
            int i, j;

            /* Проверка этой строки с левой стороны */
            for (i = 0; i < col; i++)
                if (board[row, i] == 1)
                    return false;

            /* Проверка верхней диагонали на левой стороне */
            for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
                if (board[i, j] == 1)
                    return false;

            /* Проверка нижней диагонали на левой стороне */
            for (i = row, j = col; j >= 0 && i < N; i++, j--)
                if (board[i, j] == 1)
                    return false;

            return true;
        }

        static bool BackTrack(int[,] board, int col, int N)
        {
            /*Если все ферзи размещены  
            то возвращается true */
            if (col == N)
            {
                k++;
                return true;
            }

            /* Возьмем столбец и попробуем разместить  
            ферзя во всех строках по очереди */
            bool res = false;
            for (int i = 0; i < N; i++)
            {
                /* Проверим, можно ли поставить ферзя на  
                доске[i,col] */
                if (IsSafe(board, i, col, N))
                {
                    /* Поместим этого ферзя на доску[i,col] */
                    board[i, col] = 1;

                    // Сделать результат истинным, если любое размещение  возможно 
                    res = BackTrack(board, col + 1, N) || res;

                    /* Если размещение ферзя на доске[i,col]  
                    не приводит к решению, то  
                    удалим ферзя с доски[i,col] */
                    board[i, col] = 0; // BACKTRACK  
                }
            }

            /* Если ферзь не может быть помещен ни в одну строку в  
                 то возвращается false */
            return res;
        }



        static void Main(string[] args)
        {
            Console.Write("Введите колличество ферзей: = ");
            int N = int.Parse(Console.ReadLine());
            int[,] board = new int[N, N];
            if (BackTrack(board, 0, N) == false)
            {
                Console.Write("Solution does not exist");
                return;
            }
            if (k != 0)
                Console.WriteLine(k);
            Console.ReadLine();
        }
    }
}

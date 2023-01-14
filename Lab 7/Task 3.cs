using System;
//На плоскости даны n точек. Соедините их замкнутой ломаной линией минимальной длины.
//Программа получает на вход число n≤10. Далее идет n пар действительных чисел: координаты точек.
//Выведите одно действительное число: минимальную длину замкнутой ломаной, проходящей через все эти точки.

namespace Задание_3
{
    internal class Program
    {
        static int Count = 0;
        //v Boolean массив для проверки того, был ли узел посещен или нет
        //n Кол-во точек
        static double Solution(double[,] graph, bool[] v, int currPos, int n, int count, double cost, double ans)
        {

            // Если последний узел достигнут и у него есть ссылка
            // к начальному узлу, т.е. источнику, то
            // сохраняем минимальное значение из общей стоимости
            // обхода и "ans"
            if (count == n && graph[currPos, 0] > 0)
            {
                ans = Math.Min(ans, cost + graph[currPos, 0]);
                Count++;
                return ans;
            }

            
            // Цикл обхода списка смежности(это список, элемент S[i] которого содержит номера всех вершин в которые можно попасть из вершины i.)
            // узла currPos и увеличение графа
            // на 1 и стоимость на значение graph[currPos,i]
            for (int i = 0; i < n; i++)
            {
                if (v[i] == false && graph[currPos, i] > 0)
                {
                    // Отметить как посещенный
                    v[i] = true;
                    ans = Solution(graph, v, i, n, count + 1, cost + graph[currPos, i], ans);
                    // Пометить узел как непосещенный
                    v[i] = false;
                }
            }
            return ans;
        }
        static double Distance(double xa, double ya, double xb, double yb)
        {
            return Math.Sqrt(((xb - xa) * (xb - xa)) + ((yb - ya) * (yb - ya)));
        }
        static void Main(string[] args)
        {
            Console.WriteLine("Введите количество точек :");
            int NPoint = int.Parse(Console.ReadLine());
            if (NPoint <= 10 && NPoint > 0)
            {

                double[] ArrayPoints = new double[NPoint * 2];
                for (int i = 0; i < NPoint; i++)
                {
                    Console.Write("Введите координаты x точки {0} :", i);
                    ArrayPoints[i] = double.Parse(Console.ReadLine());
                    Console.Write("\nВведите координаты y точки {0} :", i);
                    ArrayPoints[i + NPoint] = double.Parse(Console.ReadLine());
                }
                for (int i = 0; i < NPoint; i++)
                {
                    Console.WriteLine("Координаты точки : {0} = {1} {2}", i, ArrayPoints[i], ArrayPoints[i + NPoint]);
                }

                double[,] graph = new double[NPoint, NPoint];
                for (int i = 0; i < NPoint; i++)
                {
                    for (int j = 0; j < NPoint; j++)
                    {
                        graph[i, j] += Distance(ArrayPoints[i], ArrayPoints[i + NPoint], ArrayPoints[j], ArrayPoints[j + NPoint]);
                        Console.WriteLine("Расстояние между точками : {0} и {1} = {2}", i, j, graph[i, j]);

                    }
                }

                bool[] v = new bool[NPoint];

                // Пометить 0-й узел как посещенный
                v[0] = true;
                double ans = double.MaxValue;

                ans = Solution(graph, v, 0, NPoint, 1, 0, ans);
                Console.Write($"Answer = {ans} Count = {Count}");
                Console.ReadLine();
            }
        }
    }
}

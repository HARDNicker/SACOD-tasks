using System;
using System.Collections;
using System.Collections.Generic;
//Реализовать шаблонный класс динамической структуры со всеми присущими для неё методами 
//(добавление новых узлов, удаление узлов, поиск)
//Односвязный линейный список

namespace Задание_1
{
    public class Node<T> 
    {

        public T Data { get; set; } 
        public Node<T> Next { get; set; }
        public Node(T data)
        {
            Data = data;
        }
    }

    public class LineList<T> : IEnumerable<T>
    {
        Node<T> head;
        Node<T> tail;

        public LineList() 
        {
            head = null;
            tail = null;
        }
        public LineList(T data) 
        {
            Node<T> node = new Node<T>(data);
            head = node;
            tail = node;
        }

        public void Add(T data) 
        {
            Node<T> node = new Node<T>(data);

            if (head == null)
                head = node;
            else
                tail.Next = node;
            tail = node;

        }
        public bool Remove(T data)
        {
            Node<T> current = head;
            Node<T> previous = null;

            while (current != null)
            {
                if (current.Data.Equals(data))
                {
                    if (previous != null)
                    {
                        previous.Next = current.Next;

                        if (current.Next == null)
                            tail = previous;
                    }
                    else
                    {

                        head = head.Next;

                        if (head == null)
                            tail = null;
                    }
                    return true;
                }

                previous = current;
                current = current.Next;
            }
            return false;
        }
        public bool Search(T data)
        {
            Node<T> current = head;
            while (current != null)
            {
                if (current.Data.Equals(data))
                    return true;
                current = current.Next;
            }
            return false;
        }

        IEnumerator IEnumerable.GetEnumerator()
        {
            return ((IEnumerable)this).GetEnumerator();
        }

        IEnumerator<T> IEnumerable<T>.GetEnumerator() 
        {
            Node<T> current = head;
            while (current != null)
            {
                yield return current.Data;
                current = current.Next;
            }
        }
    }
    internal class Program
    {

        static void Main(string[] args)
        {
            LineList<string> lineList = new LineList<string>();
            Console.WriteLine("Добавление элементов в первый список : Vlad, Pasha, Dima, Nikita ");
            lineList.Add("Vlad");
            lineList.Add("Pasha");
            lineList.Add("Dima");
            lineList.Add("Nikita");

            Console.WriteLine("Вывод первого списка: ");
            foreach (var item in lineList)
            {
                Console.WriteLine(item);
            }

            Console.WriteLine("Удаляем элемент Nikita ");
            lineList.Remove("Nikita");
            Console.WriteLine("Вывод первого списка без Nikita: ");
            foreach (var item in lineList)
            {
                Console.WriteLine(item);
            }

            Console.WriteLine("\nПоиск элемента Pasha ");
            Console.WriteLine("Есть ли элемент в списке? = " + lineList.Search("Pasha"));
            Console.ReadLine();
        }
    }
}

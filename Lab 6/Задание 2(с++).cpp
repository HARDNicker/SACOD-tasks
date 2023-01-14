#include"RBTree.h"
#include<iostream>
#include<vector>
using namespace std;
//Реализовать шаблонный класс динамической структуры со всеми присущими для неё методами 
//(добавление новых узлов, удаление узлов, поиск)
//Красно-черное дерево поиска

int main()
{
	setlocale(LC_ALL, "rus");
	vector<int> nums{ 10,40,30,60,90,70,20,50,80,100 };
	RBTree<int> tree;
	for (auto num : nums)
		tree.insert(num);
	tree.preOrder();
	cout << endl;
	tree.inOrder();
	cout << endl;
	tree.postOrder();
	cout << endl;
	cout << "Найти узел с ключом 30: \n";
	cout << endl << tree.search(30)->key << endl;
	cout << "Удалить узел с ключом 100 \n";
	tree.remove(100);
	tree.preOrder();
	cout << endl;
	cout << "\nКрасные и черные детали дерева: \n";
	tree.print();
	cin.get();
	return 0;
}
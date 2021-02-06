#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <unordered_set>
#include <queue>
#include <conio.h>
using namespace std;

class Tree
{

	struct Node
	{

		Node(int _key, const string& _val) :
			key(_key),
			val(_val),
			left(nullptr),
			right(nullptr)
		{}

		const Node operator=(const Node& r)
		{
			left = r.left;
			right = r.right;
			key = r.key;
			val = r.val;

			return *this;
		}

		Node *left;
		Node *right;

		int key;
		string val;

	};

public:

	Tree() :
		head(nullptr)
	{}

	Tree(int _key, const string& _val) :
		head(new Node(_key, _val))
	{}

	void insert(int _key, const string& _val)
	{
		Node *cur = head;

		while (cur)
		{
			if (_key > cur->key)
			{
				if (cur->right == nullptr)
				{
					cur->right = new Node(_key, _val);
					return;
				}

				cur = cur->right;
			}
			else if (_key < cur->key)
			{
				if (cur->left == nullptr)
				{
					cur->left = new Node(_key, _val);
					return;
				}

				cur = cur->left;
			}
			else
			{
				cerr << "Error: value must be unique." << endl;
				return;
			}
		}

		head = new Node(_key, _val);
	}

	void print_value(int _key)
	{
		Node *cur = head;

		cout << _key << ": ";

		while (cur)
		{
			if (_key > cur->key)
			{
				cur = cur->right;
			}
			else if (_key < cur->key)
			{
				cur = cur->left;
			}
			else
			{
			    cout << cur->val << endl;
				return;
			}
		}

		cout << "Not found." << endl;
	}

	void print_NLR()
	{
		if (head)
			print_NLR_helper(head);
		else
			cout << "(null)" << endl;

		cout << endl;
	}

	void print_LNR()
	{
		if (head)
			print_LNR_helper(head);
		else
			cout << "(null)" << endl;

		cout << endl;
	}

	void print_LRN()
	{
		if (head)
			print_LRN_helper(head);
		else
			cout << "(null)" << endl;

		cout << endl;
	}

	void print_RNL()
	{
		if (head)
			print_RNL_helper(head, 0);
		else
			cout << "(null)" << endl;

		cout << endl;
	}

	void erase(int _key)
	{
		Node *cur = head;
		Node *parent = nullptr;

		cout << _key << ": ";

		while (cur)
		{
			if (_key != cur->key)
				parent = cur;

			if (_key > cur->key)
				cur = cur->right;
			else if (_key < cur->key)
				cur = cur->left;
			else
				break;
		}

		if (cur == nullptr)
		{
			cout << "Not found." << endl;
			return;
		}

		if (cur->left && cur->right)
		{
			Node *right = cur->right;
			Node *left = cur->left;

			Node *smallest_right = right;
			while (smallest_right->left)
				smallest_right = smallest_right->left;


			smallest_right->left = left;
			*cur = *right;

			delete right;
		}
		else if (cur->right)
		{
			Node *right = cur->right;

			*cur = *right;

			delete right;
		}
		else if (cur->left)
		{
			Node *left = cur->left;

			*cur = *left;

			delete left;
		}
		else
		{
			if (cur != head)
			{
				if (cur == parent->left)
					parent->left = nullptr;
				else
					parent->right = nullptr;
			}
			else
				head = nullptr;

			delete cur;
		}


		cout << "Deleted.\n" << endl;
	}

	void balance()
	{
		if (head == nullptr)
			return;

		vector<pair<int, string>> nodes;

		stack<Node*> s;
		s.push(head);

		unordered_set<Node*> checked;
		while (!s.empty())
		{
			Node *top = s.top();
			
			Node *cur = top->left;
			while (cur && !checked.count(cur))
				s.push(cur), cur = cur->left;

			top = s.top();

			checked.insert(top);
			nodes.push_back(pair<int, string>(top->key, top->val));

			s.pop();

			if (top->right && !checked.count(top->right))
				s.push(top->right);
		}

		head = nullptr;
		unordered_set<int> added;

		balance_helper(nodes, added, 0, nodes.size());

		for (auto it = checked.begin(); it != checked.end(); ++it)
			delete *it;
	}

	void solution(int _key)
	{
		if (head && head->key == _key)
		{
			head = nullptr;
			return;
		}

		Node *cur = head;

		while (cur)
		{
			if (_key > cur->key)
			{
				if (cur->right && cur->right->key == _key)
				{
					delete cur->right;

					cur->right = nullptr;
					return;
				}

				cur = cur->right;
			}
			else if (_key < cur->key)
			{
				if (cur->left && cur->left->key == _key)
				{
					delete cur->left;

					cur->left = nullptr;
					return;
				}

				cur = cur->left;
			}
		}

		cout << _key << ": Not found." << endl;
	}

	~Tree()
	{
		if (head == nullptr)
			return;

		queue<Node*> q;
		q.push(head);

		while (!q.empty())
		{
			Node *front = q.front();

			if (front->left)
				q.push(front->left);

			if (front->right)
				q.push(front->right);

			q.pop();

			delete front;
		}
	}

private:

	void balance_helper(const vector<pair<int, string>>& nodes, unordered_set<int>& added, int l, int r)
	{
		int m = (l + r) / 2;

		if (l == r || added.count(m))
			return;

		insert(nodes[m].first, nodes[m].second);

		added.insert(m);

		balance_helper(nodes, added, l, m);
		balance_helper(nodes, added, m, r);
	}

	void print_NLR_helper(Node *node)
	{
		if (node == nullptr)
			return;

		cout << node->key << ": " << node->val << endl;

		print_NLR_helper(node->left);
		print_NLR_helper(node->right);
	}

	void print_LNR_helper(Node *node)
	{
		if (node == nullptr)
			return;

		print_LNR_helper(node->left);

		cout << node->key << ": " << node->val << endl;

		print_LNR_helper(node->right);
	}

	void print_LRN_helper(Node *node)
	{
		if (node == nullptr)
			return;

		print_LRN_helper(node->left);
		print_LRN_helper(node->right);

		cout << node->key << ": " << node->val << endl;
	}

	void print_RNL_helper(Node *node, int n)
	{
		if (node == nullptr)
			return;

		print_RNL_helper(node->right, n + 6);

		cout << string(n, ' ') << "(" << node->key << "," << node->val << ")" << endl;

		print_RNL_helper(node->left, n + 6);
	}

	Node *head;

};


int main()
{
	setlocale(LC_ALL, "");
	Tree tree;
	tree.insert(100, "F");
	tree.insert(50, "B");
	tree.insert(25, "A");
	tree.insert(75, "D");
	tree.insert(65, "C");
	tree.insert(85, "E");
	tree.insert(125, "G");
	tree.insert(150, "I");
	tree.insert(135, "H");
	while (true)
	{
		cout << "\n\n\t1.  Вставить элемент в дерево.\n";
		cout << "\t2.  Найти элемент в дереве по ключу.\n";
		cout << "\t3.  Удалить элемент из дерева по ключу.\n";
		cout << "\t4.  Сбалансировать дерево.\n";
		cout << "\t5.  Вывести дерево в виде дерева.\n";
		cout << "\t6.  Вывести дерево прямым обходом.\n";
		cout << "\t7.  Вывести дерево обратным обходом.\n";
		cout << "\t8.  Вывести дерево в порядке возрастания ключа.\n";
		cout << "\t9.  Удалить из дерева ветвь, имеющую заданный ключ.\n";
		cout << "\t10. Очистка консоли.\n";
		cout << "\t11. Выход из программы.\n";
		cout << "Введите команду: ";
		int n;
		cin >> n;
		if (n == 1)
		{
			cout << "\nВставка элемента в дерево: \n\n";
			int key;
			string val;
			cout << "Введите ключ: ";
			cin >> key;
			cout << "Введите строковое значение: ";
			cin >> val;
			tree.insert(key, val);
			cout << "\nВставка прошла успешно." << endl;
		}
		else if (n == 2)
		{
			cout << "\nПоиск элемента в дереве по ключу: \n\n";
			int key;
			cout << "Введите ключ: ";
			cin >> key;
			cout << endl;
			tree.print_value(key);
		}
		else if (n == 3)
		{
			cout << "\nУдаление элемента из дерева по ключу: \n\n";
			int key;
			cout << "Введите ключ: ";
			cin >> key;
			cout << endl;
			tree.erase(key);
		}
		else if (n == 4)
		{
			cout << "\nБалансировка дерева: \n\n";
			tree.balance();
			cout << "Операция успешно завершена." << endl;
		}
		else if (n == 5)
		{
			cout << "\nВывод дерева в виде дерева: \n\n";
			tree.print_RNL();
			cout << "Операция успешно завершена." << endl;
		}
		else if (n == 6)
		{
			cout << "\nВывод дерева прямым обходом: \n\n";
			tree.print_NLR();
			cout << "Операция успешно завершена." << endl;
		}
		else if (n == 7)
		{
			cout << "\nВывод дерева обратным обходом: \n\n";
			tree.print_LRN();
			cout << "Операция успешно завершена." << endl;
		}
		else if (n == 8)
		{
			cout << "\nВывод дерева в порядке возрастания ключа: \n\n";
			tree.print_LNR();
			cout << "Операция успешно завершена." << endl;
		}
		else if (n == 9)
		{
			int key;
			cout << "Введите ключ: ";
			cin >> key;
			tree.solution(key);
			cout << "\n\nОперация успешно завершена.\n" ;
		}
		else if (n == 10)
		{
			system("cls");
		}
		else if (n == 11)
		{
			cout << "\nВыход из программы.\n\n";
			break;
		}
		else
		{
			cerr << "\nОшибка: нет такой команды\n\n";
		}
	}

	return 0;
}
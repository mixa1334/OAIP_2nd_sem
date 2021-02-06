#include <iostream>
using namespace std;

class Double_Linked_List
{

	struct Node
	{

		Node(int _val) :
			val(_val),
			next(nullptr),
			prev(nullptr)
		{}


		int val;

		Node *next;
		Node *prev;

	};

public:

	Double_Linked_List(int _val) :
		first(new Node(_val)),
		last(first)
	{}
	~Double_Linked_List()
	{
		while (first)
		{
			Node* tmp = first;
			first = first->next;

			delete tmp;
		}
	}

	void push_front(int _val)
	{
		Node *tmp = first;

		first = new Node(_val);

		first->next = tmp;
		tmp->prev = first;
	}

	void push_back(int _val)
	{
		Node *tmp = last;

		last = new Node(_val);

		last->prev = tmp;
		tmp->next = last;
	}

	void print_forward()
	{
		Node *cur = first;

		cout << "Вывод с конца: ";

		while (cur)
		{
			cout << cur->val << " ";
			cur = cur->next;
		}

		cout << endl;
	}

	void print_backward()
	{
		Node *cur = last;

		cout << "Вывод с начала: ";

		while (cur)
		{
			cout << cur->val << " ";
			cur = cur->prev;
		}

		cout << endl;
	}

	void solution()
	{
		Node *nullNode = new Node(INT_MIN);
		nullNode->next = first;

		Node *prev = nullNode;
		Node *cur = first;

		while (prev && cur)
		{
			while (cur && cur->val < 0)
			{
				Node *tmp = cur;
				cur = cur->next;

				delete tmp;
			}

			prev->next = cur;

			if (cur)
			{
				cur->prev = prev;

				last = cur;
			}

			prev = cur;

			if (cur)
				cur = cur->next;
		}

		first = nullNode->next;
		first->prev = nullptr;
	}

private:

	Node *first;
	Node *last;

};

int main()
{
	setlocale(LC_ALL, "Russian");

	Double_Linked_List a(1);

	a.push_back(5);
	a.push_back(3);
	a.push_back(-8);
	a.push_back(14);
	a.push_back(-2);
	a.push_back(-15);
	a.push_back(0);

	a.push_front(7);
	a.push_front(-2);
	a.push_front(-10);
	a.push_front(0);
	a.push_front(14);
	a.push_front(-2);

	a.print_forward();
	a.print_backward();

	cout << endl;

	a.solution();

	cout << "Все отрицательный числа удалены!" << "\n\n";

	a.print_forward();
	a.print_backward();

	return 0;
}
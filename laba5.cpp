#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;
class Stack
{

	struct Node
	{
		Node(int _val) :
			val(new int(_val)),
			next(nullptr)
		{}

		int *val;
		Node *next;

		~Node()
		{
			delete val;
		}
	};

public:

	Stack(int _val) : 
		head(new Node(_val))
	{}
	~Stack()
	{
		while (head)
		{
			Node* tmp = head;
			head = head->next;

			delete tmp;
		}
	}
	void push(int _val)
	{
		Node *node = new Node(_val);

		node->next = head;
		head = node;
	}
	void list()
	{
		Node *cur = head;
		while (cur)
		{
			cout << *cur->val << " ";
			cur = cur->next;
		}
		cout << "\n\n";
	}
	void pop()
	{
		if (head == nullptr)
			return;

		Node *tmp = head;
		head = head->next;

		delete tmp;
	}
	void sort_val()
	{
		bool sorted;

		do {
			sorted = true;

			Node *cur = head;
			while (cur && cur->next)
			{
				if (*cur->val > *cur->next->val)
				{
					int tmp = *cur->val;
					*cur->val = *cur->next->val;
					*cur->next->val = tmp;
					
					sorted = false;
				}

				cur = cur->next;
			}

		} while (!sorted);
		cout << "Сортировка выполнена успешно!\n\n";
	}
	void sort_ptr()
	{
		bool sorted;

		Node *nullNode = new Node(INT_MIN);
		nullNode->next = head;

		do {
			sorted = true;

			Node *cur = nullNode;

			while (cur && cur->next && cur->next->next)
			{
				Node *first = cur->next;
				Node *second = cur->next->next;

				if (*first->val > *second->val)
				{
					Node *tmp = second->next;

					second->next = first;
					cur->next = second;

					first->next = tmp;

					sorted = false;
				}

				cur = cur->next;
			}

		} while (!sorted);


		head = nullNode->next;
		delete nullNode;
		cout << "Сортировка выполнена успешно!\n\n";
	}
	bool empty()
	{
		return head == nullptr;
	}
	void solution()
	{
		Node *nullNode = new Node(INT_MIN);
		nullNode->next = head;

		Node *prev = nullNode;
		Node *cur = head;

		while (prev && cur)
		{
			while (cur && *cur->val < 0)
			{
				Node *tmp = cur;
				cur = cur->next;

				delete tmp;
			}

			prev->next = cur;

			prev = cur;
			
			if (cur)
				cur = cur->next;
		}

		head = nullNode->next;
		cout << "Отрицательные элементы удалены!\n\n";
	}

private:

	Node *head;

};

Stack* getStackInitializedByValues(vector<int>& nums)
{
	if (nums.empty()) 
		return nullptr;

	Stack *s = new Stack(nums[nums.size() - 1]);

	for (int i = (int)nums.size() - 2; i >= 0; --i)
		s->push(nums[i]);

	return s;
}

int main()
{
	system("chcp 1251>nul");
	int N;
	cout << "Введите кол-во эл: ";
	cin >> N;
	vector<int> NUMS(N);
	for (int i = 0; i < NUMS.size(); i++)
	{
		int num;
		cout << "\nВведите " << i + 1 << " элемент ";
		cin >> num;
		NUMS[i] = num;
	}
	cout << "\n\n\n";
	Stack *s = getStackInitializedByValues(NUMS);
	s->list();
	int metod;
	s->solution();
	s->list();
	cout << "\nВыберите метод сортировки: 1-перестановка элементов\n\t\t\t2-перестановка адресов\n";
	cin >> metod;
	if (metod == 1)
	{
		s->sort_val();
	}
	if (metod == 2)
	{
		s->sort_ptr();
	}
	s->list();
	while (!s->empty())
	{
		s->pop();
	}
	return 0;
}
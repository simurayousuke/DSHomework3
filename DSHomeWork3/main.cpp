#include<iostream>

class Node
{
	friend class LinkList;
private:
	int data;
	int ind;
	Node* next;
	Node* before;
public:
	Node(int d, int i, Node* n = 0, Node* b = 0)
	{
		data = d;
		ind = i;
		next = n;
		before = b;
	}
};

class LinkList
{
private:
	Node* head, *tail;
	int num;
public:
	LinkList()
	{
		head = tail = new Node(0, 0);
		num = 0;
	}
	~LinkList()
	{
		delete head;
		delete tail;
	}
	void Creat();
	void Reverse();
	void Print();
};

void LinkList::Creat()
{
	int d, sum;
	std::cout << "输入数据个数" << std::endl;
	std::cin >> sum;
	std::cout << "输入数据" << std::endl;
	while (sum)
	{
		num++;
		std::cin >> d;
		tail->next = new Node(d, num, 0, tail);
		tail = tail->next;
		sum--;
	}
}

void LinkList::Print()
{
	Node *temp = head->next;
	while (temp)
	{
		std::cout << temp->data << "\t";
		temp = temp->next;
	}
	std::cout << std::endl;
}

void LinkList::Reverse()
{
	Node* temp1 = head->next->next;
	Node* temp2 = tail;
	Node* temp3 = 0;
	if (num > 2)
	{
		temp3 = temp1->next->next;
		temp1->before->next = temp1->next;
		temp1->next->before = temp1->before;
		tail->next = temp1;
		temp1->before = tail;
		temp1->next = 0;
		tail = temp1;
		temp1 = temp3;
	}

	for (int i = 0; i < num / 2 - 1 && temp2 != temp1&&num>2; i++)
	{
		temp3 = temp3->next->next;
		temp1->before->next = temp1->next;
		temp1->next->before = temp1->before;
		temp1->next = temp2->next;
		temp2->next->before = temp1;
		temp2->next = temp1;
		temp1->before = temp2;
		temp1 = temp3;
	}
}

int main()
{
	LinkList a;
	a.Creat();
	a.Reverse();
	a.Print();
	return 0;
}

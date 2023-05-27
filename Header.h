#pragma once
template<typename T>		// без typename компилирует переменную как статическую (ошибка)
// template сообщает компилятору, что за ним слудет имя шаблона
void copy(T* begin, T* end, T* dest)
{
	while (begin != end)
	{
		*dest += *begin++;
	}
}
struct Node
{
	int d;
	Node* p;
};

Node* first(int d);
void  push(Node** top, int d);
int pop(Node** top);

Node* first(int d)
{
	Node* pv = new Node;
	pv->d = d;
	pv->p = 0;
	return pv;
}

void push(Node** top, int d)
{
	Node* pv = new Node;
	pv->d = d;
	pv->p = *top;
	*top = pv;
}

int pop(Node** top)
{
	int  temp = (*top)->d;
	Node* pv = *top;
	*top = (*top)->p;
	delete pv;
	return  temp;
}




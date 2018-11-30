#pragma once
#pragma once

template<typename T>
class tForwardList
{
	struct Node
	{
		T data;                     // data for the element stored
		Node * next;                // pointer to node following this node
	};

	Node * head;                    // pointer to head of linked list

public:
	tForwardList();                 // default constructor
	~tForwardList();                // destructor

	void push_front(const T& val);  // adds element to front (i.e. head)
	void pop_front();               // removes element from front

	T& front();                     // returns the element at the head
	const T& front() const;         // returns the element at the head (const)

	void remove(const T& val);      // removes all elements equal to the given value
};

//default constructer 
template<typename T>
tForwardList<T>::tForwardList()
{
	if (head.data == nullptr && head.next == nullptr) { return; }

	if (head != nullptr)
	{
		head = { nullptr,nullptr };
	}
}
//deconstuctor
template<typename T>
tForwardList<T>::~tForwardList()
{
	delete head;
}
//Adds element to the front(head)
template<typename T>
void tForwardList<T>::push_front(const T & val)
{
	Node temp;
	temp.data = val;
	temp.next = front();
	head = &temp.next;
	delete temp;

}
//Removes element from the front(head)
template<typename T>
void tForwardList<T>::pop_front()
{
	Node frontVal = front();
	head = frontVal.next;
	delete frontVal;
}
//Returns element from the head
template<typename T>
T & tForwardList<T>::front()
{
	return head;
}
//returns element at the head(const)
template<typename T>
const T & tForwardList<T>::front() const
{
	return head;
}
//removes all elements that are that vAL
template<typename T>
void tForwardList<T>::remove(const T & val)
{
	for (Node *itNode = head->next; itNode != nullptr; itNode = itNode->next)
	{
		if (head->data == val)
		{
			pop_front();
		}
		if (itNode->data == val)
		{
			Node *tempNode = itNode->next;
			itNode->next = itNode->next->next;
			delete tempNode;
		}
	}
}
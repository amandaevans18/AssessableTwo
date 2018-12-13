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
public:
	class iterator
	{
		Node * cur;                                 // current node being operated upon

	public:
		iterator(Node * head);
		bool operator==(const iterator& rhs) const; // returns true if the iterator points to the same node
		bool operator!=(const iterator& rhs) const; // returns false if the iterator does not point to the same node
		T& operator*() const;                       // returns a reference to the element pointed to by the current node
		iterator& operator++();                     // pre-increment (returns a reference to this iterator after it is incremented)
		iterator operator++(int);                   // post-increment (returns an iterator to current node while incrementing the existing iterator)
	};

	Node * head;                    // pointer to head of linked list


	tForwardList();                 // default constructor
	~tForwardList();                // destructor

	void push_front(const T& val);  // adds element to front (i.e. head)
	void pop_front();               // removes element from front

	T& front();                     // returns the element at the head
	const T& front() const;         // returns the element at the head (const)

	void remove(const T& val);      // removes all elements equal to the given value
	void print();

	iterator begin();
	iterator end();
};

//default constructer 
template<typename T>
tForwardList<T>::tForwardList()
{
	head = nullptr;
}
//deconstuctor
template<typename T>
tForwardList<T>::~tForwardList()
{
	for (Node *itNode = head->next; itNode != nullptr; itNode = itNode->next)
	{
		if (head != nullptr) 
		{
			//missing a step
			Node *tempNode = itNode->next;
			itNode->next = itNode->next->next;
			delete tempNode;
		}
	}
}
//Adds element to the front(head)
template<typename T>
void tForwardList<T>::push_front(const T & val)
{
	Node *temp = new Node;
	temp->data = val;
	temp->next = head;
	head = temp;
}
//Removes element from the front(head)
template<typename T>
void tForwardList<T>::pop_front()
{
	if (head == nullptr) 
	{
		std::cout << "nothing there bud" << std::endl;
		return;
	}
	Node * frontVal = head;
	head = frontVal->next;
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
	if (head == nullptr)
	{
		for (Node *itNode = head->next; itNode != nullptr; itNode = itNode->next)
		{
			if (head->data == val)
			{
				pop_front();
			}
			if (itNode->data == val)
			{
				//missing a step
				Node *tempNode = itNode->next;
				itNode->next = itNode->next->next;
				delete tempNode;
			}
		}
	}
}

template<typename T>
void tForwardList<T>::print()
{
	if (head != nullptr)
	{
		Node * temp = head;
		while (temp != nullptr)
		{
			std::cout << temp->data << std::endl;
			temp = temp->next;
		}
	}
}


//START OF ITERATORS

template<typename T>
tForwardList<T>::iterator::iterator(Node * head)
{
	cur = head;
}

template<typename T>
bool tForwardList<T>::iterator::operator==(const iterator & rhs) const
{
	return cur == rhs.cur;
}

template<typename T>
bool tForwardList<T>::iterator::operator!=(const iterator & rhs) const
{
	return cur != rhs.cur;
}

template<typename T>
T & tForwardList<T>::iterator::operator*() const
{
	return cur->data;
}

template<typename T>
typename tForwardList<T>::iterator &tForwardList<T>::iterator::operator++()
{
	cur = cur->next;
	return (*this);
}

template<typename T>
typename tForwardList<T>::iterator tForwardList<T>::iterator::operator++(int)
{
	iterator temp;
	temp = cur;
	cur = cur->next;
	return temp;
}

template<typename T>
typename tForwardList<T>::iterator tForwardList<T>::begin()
{

	return iterator(head);
}

template<typename T>
typename tForwardList<T>::iterator tForwardList<T>::end()
{
	return iterator(nullptr);
}

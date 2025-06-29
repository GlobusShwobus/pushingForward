#pragma once

/************************************************************************************************************************
* GUIDE:
* 
* When the first element in pushed into the stack the stack grows "vertically". Last in, first out.
* 
* An element is created with whatever data, plus a pointer to the previous element. This is important to rememeber becasue
* the behavior is dependant on default behavior which is not explicitly seen in code.
* 
* In case a stack is copied, the element will recursivly create new elements going down the chain using the '=' operator
* The '=' operator does this because of default behavior of constructors. so when 'pNext = new Element' is invoked,
* it behaves recursivly/in a cascading manner until it reaches the bottom.
* 
* The destructor of element works exactly the same. It causes recursive destruction of all elements.
* 
* Additionally the countElements method behaves in the same manner, recursivly adding +1 each call until it reaches the bottom.
* 
* If the pop function is called, it will disconnect the top element in the chain so it does not cause a recursive destruction
* chain, making it safe to delete. Also returns the value
* 
* 
************************************************************************************************************************/

class Stack 
{
private:
	class Element
	{
		Element* pNext = nullptr;
		int val;
	public:
		Element(int val, Element* pNext) :val(val), pNext(pNext) {}
		Element(const Element& src):val(src.val)
		{
			if (src.pNext != nullptr) {
				pNext = new Element(*src.pNext);
			}
		}
		int getVal()const
		{
			return val;
		}
		Element* disconnect() {
			Element* pTemp = pNext;
			pNext = nullptr;
			return pTemp;
		}
		int countElements()const
		{
			if (pNext != nullptr) {
				return pNext->countElements() + 1;
			}
			else {
				return 1;
			}
		}
		~Element()
		{
			delete pNext;
			pNext = nullptr;
		}
	};

	Element* pTop = nullptr;
public:
	Stack() = default;
	Stack(const Stack& src)
	{
		*this = src;
	}
	Stack& operator=(const Stack& src)
	{
		if (!empty()) {
			delete pTop;
			pTop = nullptr;
		}
		if (!src.empty()) {
			pTop = new Element(*src.pTop);
		}
		return *this;
	}
	~Stack()
	{
		delete pTop;
		pTop = nullptr;
	}

	void push(int val)
	{
		pTop = new Element(val, pTop);
	}
	int pop()
	{
		if (!empty()) {
			const int tempVal = pTop->getVal();
			Element* oldTop = pTop;
			pTop = pTop->disconnect();
			delete oldTop;
			return tempVal;
		}
		else {
			return -1;
		}
	}
	int size()const
	{
		if (!empty()) {
			return pTop->countElements();
		}
		else {
			return 0;
		}
	}
	bool empty()const
	{
		return pTop == nullptr;
	}
};
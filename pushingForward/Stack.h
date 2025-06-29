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

	class Element {

		Element* pPrevious = nullptr;
		int val;

	public:

		Element(int val, Element* currentTop):val(val),pPrevious(currentTop) {}

		Element(const Element& src) :val(src.val){
			if (src.pPrevious != nullptr) {
				pPrevious = new Element(*src.pPrevious);
			}
		}
		~Element() {
			if (pPrevious) {
				delete pPrevious;
				pPrevious = nullptr;
			}
		}

		Element* disconnect() {
			Element* temp = pPrevious;
			pPrevious = nullptr;
			return temp;
		}
		int getVal() {
			return val;
		}
		int count(Element* elem) {
			if (elem->pPrevious != nullptr) {
				return count(elem->pPrevious) + 1;
			}
			else {
				return 1;
			}
		}
	};

	Element* pTop = nullptr;
	
public:

	Stack() = default;
	
	Stack(const Stack& src) {
		*this = src;
	}
	Stack& operator=(const Stack& src) {

		if (pTop)
			delete pTop;
		if (!src.empty()) {
			pTop = new Element(*src.pTop);
		}
		return*this;
	}
	~Stack(){
		if (pTop) {
			delete pTop;
			pTop = nullptr;
		}
	}

	void push(int val)
	{
		pTop = new Element(val, pTop);
	}
	int pop()
	{
		if (!empty()) {
			const int payload = pTop->getVal();
			Element* tempTop = pTop;
			pTop = pTop->disconnect();
			delete tempTop;

			return payload;
		}
		else {
			return -1;
		}
	}
	int size()const
	{
		if (!empty()) {
			return pTop->count(pTop);
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
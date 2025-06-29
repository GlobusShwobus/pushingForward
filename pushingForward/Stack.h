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

template <typename T> class Stack
{
private:

	class Element {

		Element* pPrevious = nullptr;
		T val;

	public:

		Element(const T& val, Element* currentTop) :val(val), pPrevious(currentTop) {}

		Element(const Element& src) :val(src.val) {
			if (src.pPrevious != nullptr) {
				pPrevious = new Element(*src.pPrevious);
			}
		}
		Element& operator=(const Element& src) = delete;
		~Element() {
			delete pPrevious;
			pPrevious = nullptr;
		}

		Element* disconnect() {
			Element* temp = pPrevious;
			pPrevious = nullptr;
			return temp;
		}
		T& getVal() {
			return val;
		}
		int count(Element* elem)const {
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
	~Stack() {
		if (pTop) {
			delete pTop;
			pTop = nullptr;
		}
	}

	void push(const T& val)
	{
		pTop = new Element(val, pTop);
	}
	T pop()
	{
		if (empty()) {
			throw std::out_of_range("can't pop an empty stack");
		}
		T payload = pTop->getVal();
		Element* tempTop = pTop;
		pTop = pTop->disconnect();
		delete tempTop;

		return payload;

	}
	int size()const
	{
		return empty() ? 0 : pTop->count();
	}
	bool empty()const
	{
		return pTop == nullptr;
	}
};
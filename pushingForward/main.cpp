#include <iostream>
#include "Stack.h"

void test1()
{
	Stack<int> s;
	s.push(5);
	s.push(3);
	if (s.pop() == 3 && s.pop() == 5 && s.empty())
	{
		printf("    Test 1 passed!\n");
	}
	else
	{
		printf("*** Test 1 failed!\n");
	}
}

void test2()
{
	Stack<int> s;
	s.push(5);
	s.push(3);
	s.push(3);
	s.push(3);
	int i = s.size();
	int b=i;
	if (s.size() == 4)
	{
		printf("    Test 2 passed!\n");
	}
	else
	{
		printf("*** Test 2 failed!\n");
	}
}

void test3()
{
	Stack<int> s;
	s.push(5);
	s.push(3);
	s.pop();
	s.push(69);
	s.push(69);
	s.push(69);
	s.push(69);
	s.pop();
	s.pop();
	s.pop();
	if (s.size() == 2)
	{
		printf("    Test 3 passed!\n");
	}
	else
	{
		printf("*** Test 3 failed!\n");
	}
}

void test4()
{
	Stack<int> s;
	s.push(5);
	s.push(3);
	s.pop();
	s.pop();
	s.pop();
	s.pop();
	if (s.size() == 0)
	{
		printf("    Test 4 passed!\n");
	}
	else
	{
		printf("*** Test 4 failed!\n");
	}
}

void test5()
{
	Stack<int> s;
	s.push(5);
	s.push(3);

	Stack<int> s2 = s;
	s2.pop();

	if (s.size() == 2 && s2.pop() == 5)
	{
		printf("    Test 5 passed!\n");
	}
	else
	{
		printf("*** Test 5 failed!\n");
	}
}

void test6()
{
	Stack<int> s;
	s.push(5);
	s.push(3);

	{
		Stack<int> s2 = s;
		s2.pop();
	}

	if (s.size() == 2 && s.pop() == 3)
	{
		printf("    Test 6 passed!\n");
	}
	else
	{
		printf("*** Test 6 failed!\n");
	}
}

void test7()
{
	Stack<int> s;
	s.push(5);
	s.push(3);

	Stack<int> s2;
	s2 = s;
	s2.pop();

	if (s.size() == 2 && s2.pop() == 5)
	{
		printf("    Test 7 passed!\n");
	}
	else
	{
		printf("*** Test 7 failed!\n");
	}
}

void test8()
{
	Stack<int> s;
	s.push(5);
	s.push(3);

	{
		Stack<int> s2;
		s2 = s;
		s2.pop();
	}

	if (s.size() == 2 && s.pop() == 3)
	{
		printf("    Test 8 passed!\n");
	}
	else
	{
		printf("*** Test 8 failed!\n");
	}
}

void test9()
{
	Stack<int> s;
	s.push(5);
	s.push(3);

	{
		Stack<int> s2;
		s2.push(828374);
		s2.push(3454);
		s2 = s;
		s2.pop();
	}

	if (s.size() == 2 && s.pop() == 3)
	{
		printf("    Test 9 passed!\n");
	}
	else
	{
		printf("*** Test 9 failed!\n");
	}
}


int main()
{
	_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDERR);
	_CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_ERROR, _CRTDBG_FILE_STDERR);
	_CrtSetReportMode(_CRT_ASSERT, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_ASSERT, _CRTDBG_FILE_STDERR);

	test1();
	test2();
	test3();
	test4();
	test5();
	test6();
	test7();
	test8();
	test9();


	_CrtDumpMemoryLeaks();
	return 0;
}
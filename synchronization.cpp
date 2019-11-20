#include <iostream>
#include <thread>
using namespace std;

bool firstTurn = true;

void fun1(int num)
{
	for(int i = 1; i <= num; i += 2)
	{
	    while(!firstTurn);
	    cout << i << " ";
	    firstTurn = false;
	}
}

void fun2(int num)
{
	for(int i = 2; i <= num; i += 2)
	{
	    while(firstTurn);
	    cout << i << " ";
	    firstTurn = true;
	}
}

int main()
{
	thread t1(fun1, 1000);
	thread t2(fun2, 1000);
	t1.join();
	t2.join();
	return 0;
}
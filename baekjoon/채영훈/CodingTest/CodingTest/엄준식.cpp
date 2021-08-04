#include "TripleLong.h"
#include <iostream>

int main()
{
	TripleLong op1("-56");
	TripleLong op2("-89");
	TripleLong op3 = op1 * op2;

	cout << op3.GetVal() << "\n";

	return 0;
}
#include "MyDerived.h"
///
int MyDerived::AddSomething(int initVal) {
	return initVal + 100 + MyBase::AddSomething(11);
}
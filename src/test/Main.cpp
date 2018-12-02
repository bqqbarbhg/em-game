#include <test/Precompiled.h>
#include <test/Test.h>

int main(int argc, char **argv)
{
	bool anyFailed = em::runTests();
	return anyFailed ? 1 : 0;
}


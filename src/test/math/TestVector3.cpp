#include <test/Precompiled.h>
#include <test/Test.h>

TestCase(length)
{
	em::Vector3 vec = { 1.0f, 2.0f, 3.0f };
	testAssert(em::approxEqual(length(vec), 3.7416573f));
}


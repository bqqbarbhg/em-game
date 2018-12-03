#include <test/Precompiled.h>
#include "Test.h"
#include <stdio.h>

namespace em {

namespace {

	TestCaseStruct g_testCases[4096];
	uint32_t g_numTestCases = 0;
	bool g_didFail = false;

}

uint32_t addTest(const char *name, const char *file, void (*func)())
{
	uint32_t index = g_numTestCases++;
	TestCaseStruct &ts = g_testCases[index];
	ts.name = name;
	ts.file = file;
	ts.func = func;
	return index;
}

bool runTests()
{
	uint32_t numFail = 0;

	for (uint32_t i = 0; i < g_numTestCases; i++)
	{
		g_didFail = false;
		g_testCases[i].func();
		if (g_didFail)
			numFail++;
	}

	printf("Passed %u/%u tests\n", g_numTestCases - numFail, g_numTestCases);

	return numFail > 0;
}

void testAssertImp(bool cond, const char *expression, const char *file, int line)
{
	if (cond) return;

	fprintf(stderr, "Test failed %s:%d: %s\n", file, line, expression);
	g_didFail = true;
}

bool approxEqual(float a, float b)
{
	return fabsf(a - b) < 0.001f;
}

}


#include <test/Precompiled.h>
#include "Test.h"
#include <stdio.h>

namespace em {

namespace {

	TestCaseStruct g_testCases[4096];
	uint32_t g_numTestCases = 0;
	bool g_anyFailed = false;

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
	for (uint32_t i = 0; i < g_numTestCases; i++)
	{
		g_testCases[i].func();
	}

	return g_anyFailed;
}

void testAssertImp(bool cond, const char *expression, const char *file, int line)
{
	if (cond) return;

	fprintf(stderr, "Test failed %s:%d: %s\n", file, line, expression);
	g_anyFailed = true;
}

bool approxEqual(float a, float b)
{
	return fabsf(a - b) < 0.001f;
}

}


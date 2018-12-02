#pragma once

namespace em {

struct TestCaseStruct
{
	const char *name;
	const char *file;
	void (*func)();
};

#define TestCase(name) \
void test_##name(); \
uint32_t testIx_##name = ::em::addTest(#name, __FILE__, &test_##name); \
void test_##name()

uint32_t addTest(const char *name, const char *file, void (*func)());
bool runTests();

#define testAssert(cond) ::em::testAssertImp(cond, #cond, __FILE__, __LINE__)

void testAssertImp(bool cond, const char *expression, const char *file, int line);

bool approxEqual(float a, float b);

}


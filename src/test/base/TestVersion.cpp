#include <test/Precompiled.h>
#include <test/Test.h>
#include <base/Version.h>

TestCase(version)
{
	testAssert(em::builtVersion == EM_VERSION);
}


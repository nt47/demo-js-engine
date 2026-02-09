#include"js_global.h"

void RegisterGlobalFunctions(js_State* J) {
	Console::Register();
	TestClass::RegisterTestClass(J);
}
#include "js_engine.h"
#include"js_global.h"

JsEngine::JsEngine() {}


JsEngine& JsEngine::GetInstance() {
	static JsEngine  instance;//全局变量，只定义一次
	return instance;
}

void JsEngine::UnloadScript(std::string name) {
	std::map<std::string, JsState>::const_iterator it = scripts_.find(name);
	if (it != scripts_.end()) {
		scripts_.erase(name);
	}
}

void JsEngine::LoadScript(std::string name) {
	UnloadScript(name);
	v8::HandleScope scope(scripts_[name].isolate);
	if (name == "main.js")
		RegisterGlobalFunctions(scripts_[name].state.get());//注册自定义全局函数
	if (scripts_[name].loader->LoadDomain(name) == false) {
		UnloadScript(name);
	}
}

void JsEngine::UnloadAllScripts() {
	scripts_.clear();
}
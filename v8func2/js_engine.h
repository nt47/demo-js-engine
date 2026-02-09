#pragma once
#include"js_state.h"
#include <map>
#include <string>
class JsEngine
{
public:
	void LoadScript(std::string name);
	void UnloadScript(std::string name);
	void UnloadAllScripts();
	void ExecuteScript(std::string name);
	static JsEngine& GetInstance();

private:
	std::map<std::string, JsState> scripts_;

	JsEngine();
	//explicit JsEngine(JsEngine const&);//禁止隐式转换比如A a=10;必须A a(10)
	//禁止复制和赋值
	JsEngine& operator=(JsEngine const&) = delete;
	JsEngine(JsEngine const&) = delete;
};


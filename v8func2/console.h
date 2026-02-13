#pragma once
#include <fmt/color.h>
#include<v8.h>
#include<v8pp/module.hpp>

class Console
{
public:
	static void Log(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void Warn(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void Info(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void Error(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void Success(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void Debug(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void Register();
};


#include"console.h"
#include<iostream>
void Console::Log(const v8::FunctionCallbackInfo<v8::Value>& args) {
	v8::Isolate* isolate = args.GetIsolate();
	v8::HandleScope handle_scope(isolate);

	for (int i = 0; i < args.Length(); i++) {
		v8::String::Utf8Value str(isolate, args[i]);
		if (*str) {
			printf("%s", *str);
		}
		if (i + 1 < args.Length()) {
			printf(" ");
		}
	}
	printf("\n");
}

void Console::Warn(const v8::FunctionCallbackInfo<v8::Value>& args) {
	v8::Isolate* isolate = args.GetIsolate();
	v8::HandleScope handle_scope(isolate);

	for (int i = 0; i < args.Length(); i++) {
		v8::String::Utf8Value str(isolate, args[i]);
		if (*str) {
			fmt::print(fg(fmt::color::yellow), "{}", *str);
		}
		if (i + 1 < args.Length()) {
			printf(" ");
		}
	}
	printf("\n");
}

void Console::Info(const v8::FunctionCallbackInfo<v8::Value>& args) {
	v8::Isolate* isolate = args.GetIsolate();
	v8::HandleScope handle_scope(isolate);

	for (int i = 0; i < args.Length(); i++) {
		v8::String::Utf8Value str(isolate, args[i]);
		if (*str) {
			fmt::print(fg(fmt::color::aqua), "{}", *str);
		}
		if (i + 1 < args.Length()) {
			printf(" ");
		}
	}
	printf("\n");
}

void Console::Error(const v8::FunctionCallbackInfo<v8::Value>& args) {
	v8::Isolate* isolate = args.GetIsolate();
	v8::HandleScope handle_scope(isolate);

	for (int i = 0; i < args.Length(); i++) {
		v8::String::Utf8Value str(isolate, args[i]);
		if (*str) {
			fmt::print(fg(fmt::color::red), "{}", *str);
		}
		if (i + 1 < args.Length()) {
			printf(" ");
		}
	}
	printf("\n");
}

void Console::Success(const v8::FunctionCallbackInfo<v8::Value>& args) {
	v8::Isolate* isolate = args.GetIsolate();
	v8::HandleScope handle_scope(isolate);

	for (int i = 0; i < args.Length(); i++) {
		v8::String::Utf8Value str(isolate, args[i]);
		if (*str) {
			fmt::print(fg(fmt::color::green), "{}", *str);
		}
		if (i + 1 < args.Length()) {
			printf(" ");
		}
	}
	printf("\n");
}

void Console::Register() {
	v8::Isolate* isolate = v8::Isolate::GetCurrent();
	v8::Local<v8::Context> context = isolate->GetCurrentContext();

	v8pp::module console(isolate);
	console
		.function("log", &Console::Log)
		.function("warn", &Console::Warn)
		.function("info", &Console::Info)
		.function("error", &Console::Error)
		.function("success", &Console::Success);
	isolate->GetCurrentContext()->Global()->Set(context, v8pp::to_v8(isolate, "console"), console.new_instance());
}
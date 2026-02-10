#include"js_state.h"
#include"bug.h"

void JsState::Create() {
	state = std::make_unique<js_State>();
	isolate = state->isolate();
	v8::HandleScope scope(isolate);
	isolate->SetPromiseRejectCallback(Bug::PromiseRejectCallback);
	isolate->AddMessageListener(Bug::MessageCallback);
	// 设置动态 import 回调
	isolate->SetHostImportModuleDynamicallyCallback(
		ModuleLoader::ImportModuleDynamicallyCallback);

	context = isolate->GetCurrentContext();

	loader = std::make_unique<ModuleLoader>(isolate);

}

void JsState::Destroy() {

}
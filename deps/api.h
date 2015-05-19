#ifndef RUSTJS_DEPS_C_API_H_
#define RUSTJS_DEPS_C_API_H_

#include "v8.h"

using namespace v8;

#ifdef __cplusplus
extern "C" {
#endif

typedef void (*rust_callback)();

int32_t v8_runtime(char *data);
bool v8_free_platform();
bool v8_initialize_platform();
bool v8_initialize();
bool v8_dispose();
bool v8_set_array_buffer_allocator();

bool v8_locker_is_locked();
bool v8_locker_is_active();
void v8_locker(rust_callback callback);
void v8_handle_scope(rust_callback callback);

void v8_isolate_new();
void v8_isolate_dispose();
void v8_isolate_enter();
void v8_isolate_exit();

void v8_context_new();
void v8_context_enter();
void v8_context_exit();
void v8_context_global();

bool v8_value_isArgumentsObject(void *data);
bool v8_value_isArray(void *data);


Local<Script> v8_script_compile(Isolate *isolate, char *data);
void v8_script_run(Script *script);

#ifdef __cplusplus
}
#endif

#endif

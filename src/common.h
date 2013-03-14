#include <Horde3D.h>
#include <node.h>

#define JS_FUNC(name) Handle<Value> name(const Arguments &args) \
{\
  HandleScope scope;

#define JS_RETURN_BOOL(expr) return scope.Close(Boolean::New(expr)); }

#define JS_RETURN_INT(expr) return scope.Close(Integer::New(static_cast<int>(expr))); }

#define JS_RETURN_STRING(expr) return scope.Close(String::New(expr)); }

#define JS_RETURN_FLOAT(expr) return scope.Close(Number::New(expr)); }

#define JS_RETURN_UNDF(expr) expr;\
  return scope.Close(Undefined()); }

#define JS_ARG_INT(indx) args[indx]->Int32Value()

#define JS_ARG_FLOAT(indx) args[indx]->NumberValue()

#define JS_ARG_BOOL(indx) args[indx]->Int32Value()

#define JS_ARG_STRING(indx) *String::AsciiValue((args[indx]->ToString()))

#include <pybind11/pybind11.h>

#include "typesystem/struct.h"
#include "typesystem/optional.h"
#include "typesystem/serialization/json.h"

#include <memory>

CURRENT_STRUCT(AddInput) {
  CURRENT_FIELD(a, int64_t);
  CURRENT_FIELD(b, int64_t);
};

CURRENT_STRUCT(AddOutput) {
  CURRENT_FIELD(c, Optional<int64_t>);
  CURRENT_FIELD(e, Optional<std::string>);
};

PYBIND11_MODULE(cpp_lib, py) {
  py.def("add", [](int a, int b) { return a+b; }, "Adds two numbers.");

  py.def("duplicate", [](std::string const& s) { return s + s; }, "Duplicates a string.");

  py.def("s1m", []() { return std::string(1'000'000, '*'); }, "Returns an 1MiB string.");

  auto s = std::make_shared<std::string>(1'000'000'000, '-');
  py.def("growing_s", [s]() { (*s) += '+'; return *s; }, "Return an 1GiB string that is growing by 1 char each call.");

  py.def("add_from_json", [](std::string const& s) {
    AddOutput out;
    auto const in = TryParseJSON<AddInput>(s);
    if (Exists(in)) {
      out.c = Value(in).a + Value(in).b;
    } else {
      out.e = "Wrong input JSON.";
    }
    return JSON<JSONFormat::Minimalistic>(out);
  }, R"(Returns {"c":42} for {"a":10,"b":32}.)");
}

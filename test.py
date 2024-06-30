import cpp_lib
import json

print(f"1+2: {cpp_lib.add(1, 2)}")

print(f"DUP: {cpp_lib.duplicate('foo')}")

print(f"ADD: {cpp_lib.add_from_json(json.dumps({'a':1,'b': 2}))}")
print(f"ERR: {cpp_lib.add_from_json(json.dumps({'foo':'bar'}))}")

s0 = cpp_lib.s1m()
print(f"S1M[-5:]: {s0[-5:]}, len={len(s0)}")

for i in range(0, 5):
  s1 = cpp_lib.growing_s()
  print(f"SPP[-5:]: {s1[-5:]}, len={len(s1)}")

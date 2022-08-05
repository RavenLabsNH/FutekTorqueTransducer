import sys, os
sys.setdlopenflags(os.RTLD_GLOBAL | os.RTLD_LAZY)

import bind_test

print("hi")

print(bind_test.python_name())

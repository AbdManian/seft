target = "seft"


env = Environment(CPPPATH = ['src'])

runtest = ARGUMENTS.get("run-test", None)

if runtest:
	runner = env.Object('src/TestRunner.cpp', CPPDEFINES=[('__EXT_TEST_COMMAND__',runtest)])
else:
	runner = 'src/TestRunner.cpp'
	

test_src = ['src/Test.cpp', 'src/TestRegistry.cpp', runner]


srcs = test_src + Glob('test/*.cpp')


env.Program(target, srcs)
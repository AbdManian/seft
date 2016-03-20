target = "seft"

env = Environment(CPPPATH = ['src'])

runtest = ARGUMENTS.get("run-test", None)

if runtest:
	runner = env.Object('src/TestRunner.cpp', CPPDEFINES=[('__EXT_TEST_COMMAND__',runtest)])
else:
	runner = 'src/TestRunner.cpp'
	

test_src = ['src/Test.cpp', 'src/TestRegistry.cpp', runner]


srcs = test_src + Glob('test/*.cpp')


program = env.Program(target, srcs)

###########################################################
# Based on your platform, replace execution by 
# downloading the generated file into the target machine.
###########################################################
if runtest:
	execution = env.Command('execution',None,program[0].abspath)
	Depends(execution,program)
	AlwaysBuild('execution')

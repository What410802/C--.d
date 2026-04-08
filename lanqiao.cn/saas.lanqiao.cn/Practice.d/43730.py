import typing, sys
_stdin = sys.stdin.read().split()
_stdin_iter = iter(_stdin)
def I(T: typing.Type):
	return T(next(_stdin_iter))
_stdout: typing.List[str] = []
def O(*oo):
	for o in oo:
		_stdout.append(str(o))

n=I(int)
ins=[I(int) for i in range(n)]
for i in range(n):
	pass

sys.stdout.write(''.join(_stdout))
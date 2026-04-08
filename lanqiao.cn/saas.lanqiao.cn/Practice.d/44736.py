import typing, sys
_stdin = sys.stdin.read().split()
_stdin_iter = iter(_stdin)
def I(T: typing.Type):
	return T(next(_stdin_iter))
_stdout = []
def O(*oo):
	for o in oo:
		_stdout.append(str(o))

import bisect
n=I(int)
ins = [[i,I(int),0] for i in range(n)]
ins.sort(key=lambda a: a[1])
# now ins is ordered on the passed problems
insvals = [insi[1] for insi in ins]
left_skew_rm1: bool = n-bisect.bisect_right(insvals, insvals[n>>1]) > bisect.bisect_left(insvals, insvals[n>>1]) - 1
left_skew_rm0: bool = n-bisect.bisect_right(insvals, insvals[n>>1]) > bisect.bisect_left(insvals, insvals[n>>1])

# 0123456 012345
#    ^^      ^
#if --      --
# The number below is all under n//2, so themselves should be considered, using - 1 above
i=0
while i<n:
	if insvals[i]>=insvals[n>>1]:
		break
	ins[i][2]=insvals[n>>1]+(1 if left_skew_rm1 else 0)-insvals[i]
	i+=1
if left_skew_rm0:
	while i<n:
		if insvals[i]>insvals[n>>1]:
			break
		ins[i][2]=1
		i+=1
		
ins.sort(key=lambda a: a[0])
for i in range(n):
	O(ins[i][2], ' ')

sys.stdout.write(''.join(_stdout))
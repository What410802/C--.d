import typing, sys
_stdin = sys.stdin.read().split()
_stdin_iter = iter(_stdin)
def I(T: typing.Type):
	return T(next(_stdin_iter))
_stdout: typing.List[str] = []
def O(o):
	_stdout.append(str(o))

import math

def get_max(s: str, curi: int)->typing.Tuple[int,int]: # ans len, curi next
	bar_sides = [0] # brothers
	while curi<len(s) and s[curi]!=')': # ')', so this fun call should end, leaving ')' unread.
		if s[curi]=='x':
			bar_sides[-1]+=1
			curi+=1
		elif s[curi]=='|':
			bar_sides.append(0)
			curi+=1
		elif s[curi]=='(':
			curi+=1
			tmp_len, tmp_curi = get_max(s, curi)
			bar_sides[-1]+=tmp_len
			curi=tmp_curi+1
	return max(bar_sides), curi

s = I(str)
ans, s_end = get_max(s, 0)
O(ans)

sys.stdout.write(''.join(_stdout))
import typing, sys
# # print(sys.get_int_max_str_digits()) # 4300
# sys.setrecursionlimit(0x7fff_ffff)
_stdin=sys.stdin.read().split()
_stdin_it=iter(_stdin)
def I(T: typing.Type):
	return T(next(_stdin_it))
_stdout: typing.List = [] # [Any]
def O(*oo: typing.Any):
	for o in oo:
		_stdout.append(str(o))

# import math
# import random
# import bisect, heapq
# import array, queue, collections, itertools
# import enum
# import copy, functools

n=I(int)
ans=[]
for i in range(n):
	inn=I(int)
	while(inn in ans):
		inn+=1
	ans.append(inn)
O('\n')
for i in range(n):
	O(ans[i], ' ')

sys.stdout.write("".join(_stdout))
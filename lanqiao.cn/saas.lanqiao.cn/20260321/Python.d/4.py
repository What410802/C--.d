import typing, sys
# # print(sys.get_int_max_str_digits()) # 4300
# sys.setrecursionlimit(0x7fff_ffff)

_stdin=sys.stdin.read().split()
_stdin_it=iter(_stdin)
def I(T: typing.Type):
	return T(next(_stdin_it))
_stdout: typing.List = [] # [Any]
def O(o: typing.Any):
	_stdout.append(o)

# import math
# import random
# import bisect, heapq
# import array, queue, collections, itertools
# import enum
# import copy, functools

w=I(int)
h=I(int)
v=I(int)
for i in range(h):
	for j in range(w):
		O('Q')
	O('\n')
for i in range(w):
	for j in range(w+v):
		O('Q')
	O('\n')

sys.stdout.write("".join(_stdout))
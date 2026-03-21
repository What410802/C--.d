import typing, sys
# # print(sys.get_int_max_str_digits()) # 4300
# sys.setrecursionlimit(0x7fff_ffff)
_stdin=sys.stdin.read().split()
_stdin_it=iter(_stdin)
def I(T: typing.Type):
	return T(next(_stdin_it))
_stdout: typing.List = [] # [Any]
def O(o: typing.Any):
	_stdout.append(str(o))

# import math
# import random
# import bisect, heapq
# import array, queue, collections, itertools
# import enum
# import copy, functools

h=I(int)
w=I(int)
cnt=0
get_2025 = lambda cnt: "2025"[cnt]
for i in range(h):
	cnt = i%4
	for j in range(w):
		O(get_2025(cnt))
		cnt = (cnt+1)%4
	O('\n')

sys.stdout.write("".join(_stdout))
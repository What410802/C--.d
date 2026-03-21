import typing, sys
# print(sys.get_int_max_str_digits()) # 4300
sys.setrecursionlimit(0x7fff_ffff)

_stdin=sys.stdin.read().split()
_stdin_it=iter(_stdin)
def I():
	return next(_stdin_it)
_stdout=[]
def O(o: typing.Any):
	_stdout.append(o)

# import math
# import random
# import bisect, heapq
# import array, queue, collections, itertools
# import enum
# import copy, functools

n=I()

sys.stdout.write(str(_stdout))
import typing, sys
# # print(sys.get_int_max_str_digits()) # 4300
# sys.setrecursionlimit(0x7fff_ffff)
_stdin=sys.stdin.read().split()
_stdin_it=iter(_stdin)
def I(T: typing.Type):
	return T(next(_stdin_it))
_stdout: typing.List = [] # [Any]
def O(*args: typing.Any):
	for arg in args:
		_stdout.append(str(arg))

# import math
# import random
# import bisect, heapq
# import queue, collections, itertools
# import enum
import copy, functools

n=I(int)
arr=[[0 for _ in range(1+n)] for _ in range(n+2)]
for i in range(n):
	for j in range(1+i):
		arr[i][j]=I(int)
		# O(arr[i][j],' ')#
	# O('\n')#
hfn=n//2+1
dp=[[0 for _ in range(hfn+1)] for _ in range(hfn+1)] # for i-1
for i in range(hfn):
	for j in range(hfn):
		dp[i][j]=arr[i+j][j]
		# O(dp[i][j], ' ')#
		dp[i][j]+=max(dp[i-1][j],dp[i][j-1])
	# O('\n')#
O(dp[hfn-1][hfn-1], '\n')

sys.stdout.write("".join(_stdout))
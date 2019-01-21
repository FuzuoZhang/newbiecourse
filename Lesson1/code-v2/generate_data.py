'''
python generate_data.py 10 
python generate_data.py > data.txt
'''

import sys
import numpy as np

def generate_data(n):
	assert(n>0)
	c = pow(2,31)
	a = np.random.randint(-1*c,c,size = n,dtype = np.int32)
	print(n)
	for i in range(n):
		print(a[i])


if __name__=='__main__':
	if len(sys.argv)<2:
		n = pow(2,30)
	else:
		n = int(sys.argv[1])
	generate_data(n)

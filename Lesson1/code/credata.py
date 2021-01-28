import random
import time
import numpy as np

if __name__=='__main__':
	starttime = time.process_time()
	n = pow(2,30)
	c = pow(2,32)
	print(n)
	A = np.random.randint(0,c,size = n,dtype = 'int64')
	for i in range(n):
		print(A[i])
	endtime = time.process_time()
	#print("cpu: %f s" %(endtime-starttime))

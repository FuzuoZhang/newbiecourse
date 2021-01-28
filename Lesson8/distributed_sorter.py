import sys
import os
import numpy as np
import config
import requests
from multiprocessing import Pool
from data_generator import generate_data

def is_sorted(data):
	n = len(data)
	for i in range(n-1):
		if data[i]>data[i+1]:
			return 0
	return 1

# 远程调用
def call_slave_receive_data(args):
    #print(args)
    _data, _config = args
    res = requests.post("http://{addr}:{port}/sort".format(addr=_config['address'],port=_config['port']), json={"N":len(_data), "data":_data})
    data_sorted = res.json()['data']
    return np.array(data_sorted, dtype=np.int32)

if __name__ == '__main__':
	'''
	N: number of figures waiting for sort
	M: number of processes 
	'''
	if(len(sys.argv)<2):
		print("Deficiency of N[,M] !")
		sys.exit()
	N = int(sys.argv[1])
	if(len(sys.argv)==2):
		M = os.cpu_count()
	else:
		M = int(sys.argv[2])

	data = generate_data(N)

	#split data into M parts based on bucket-sort
	split_linspace = np.linspace(data.min(),data.max()+1,M+1)
	split_data = [0]*M
	for i in range(M):
		f = filter(lambda x: x>=split_linspace[i] and x<split_linspace[i+1],data)
		split_data[i] = np.fromiter(f, dtype = np.int32).tolist()
	'''
	这里之所以使用了fromiter+tolist函数将iterable转为list是因为数字类型为np.int32，该类型不能序列化为json格式。
	如果只用：split_data[i] = list(f)，数字格式仍为np.int32，在调用函数call_slave_...时无法转为json格式。 
	'''
	
	slaves_config = config.slaves()
	
	pool = Pool(M)
	result_parts = list(pool.map(call_slave_receive_data,zip(split_data,slaves_config)))
	pool.close()
	pool.join()

	sort_result = np.concatenate(result_parts).tolist()
	if(is_sorted(sort_result)):
		print("Sort Successfully.\n")

	result_dict = {"N":len(sort_result),"sorted_data":sort_result}
	print(result_dict)



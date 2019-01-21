'''
python data_generator.py 100 > data.txt
python data_generator.py 100 -o data.txt
python data_generator.py 100 --type bin > data.bin
python data_generator.py 100 --type bin -o data.bin
'''

import sys
import numpy as np

def generate_data(N, file_output=sys.stdout):
    assert(N > 0)
    a = np.ndarray((N,), dtype=np.int32)
    file_output.write('%d\n'%N)
    np.savetxt(file_output, (a,), delimiter=' ', fmt='%d')
    return a

if __name__ == '__main__':
    #N = input()
    N = int(sys.argv[1])
    generate_data(N)
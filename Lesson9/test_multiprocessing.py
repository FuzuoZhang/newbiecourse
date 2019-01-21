from multiprocessing import Pool

def f(x):
    return x*x

if __name__ == '__main__':
    with Pool(2) as p:
        res = (p.map(f, [1, 2, 3]))
    print(res)

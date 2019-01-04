#### SortProject

-------

Li Daoming，Zhang Fuzuo



##### 模块设计

1. 数据生成
   - 使用python随机生成$2^{30}$个32位的int(有符号)类型整数。
   - 使用标准输出(print)输出到缓存区。
2. 排序代码
   - 读取来自python的缓存区内的待排序数据，保存为data.txt。
   - 调用排序函数（快速排序）。
   - 将排序后的数据保存为sort.txt文档。
3. 一个测试示例（在服务器上运行）：
   - 生成数据时间为：6.04s
   - 排序算法时间为：246.54s


##### 使用说明

1. 编译sort.cpp文件： `g++ sort.cpp -o sort`
2. 同时运行数据生成+排序程序：
    - Linux: `python credata.py | ./sort`
    - Windows: `python credata.py | sort`
    
3. 关于程序运行时间测试
   - credata.py程序
   已设置跟踪程序运行时间的变量，默认注释，可去掉注释，单独运行该程序（将`print A[i]`的循环注释掉，不然输出一大堆）。
   - sort.cpp程序
   跟踪了排序程序的运行时间，默认输出，无需手动设置。
   

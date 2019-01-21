2019
2020

# 新人训练课程
## 课程信息

### 课程内容
1. 协作开发基础(markdown, ssh, git, env, gcc, make, ipython, jupyter)
2. 数据结构与算法：上篇(sort, hash, priority queue)
3. 数据结构与算法：下篇(dfs, bfs, dp, backtracking)
4. 最优化理论与传统机器学习
5. GPU计算与框架设计(pytorch autograd)
6. 深度学习与CNN、RNN
7. 强化学习与DQN
8. 并行计算(hadoop/spark类, openmp类, multiprocessing类, dask类)
9. 远程调用(Http server flask, RESTful API)

### 课时计划
- 第1课：1月3日至6日（本周）
- 第2~5课：1月7日至13日（下周）
第- 6~8课：1月14日至20日（下下周）
- 【征集意见】1月10日逸飞离开，1月7日家豪返回
### 课程形式
- 知识要点重演示操作
- 课后作业重编程实践
- 【征集主讲】道明讲并行计算



## 第1课：协作开发基础

### 知识要点

- markdown（演示vscode, gitlab）
- shell, vim（演示Ubuntu子系统，ssh登陆）
- c++类: gcc, g++, make （演示hello world编译）
- python类：ipython, jupyter （演示本地和远程服务）
- git（init, add, commit, push, pull, branch, merge)


### python与cpp的io
#### 文件io
#### 管道操作
#### python c 混合编程(ctypes)


### 课后作业

#### 作业要求
- 分组完成：成员人数2人以上，3人以下
- git协作：使用gitlab，每成员至少2次commit、2次push、2次merge、2次pull
- 文档先行：写代码前先提交模块设计和任务分工文档给主讲人审批
- 组间review：第2课前半段，阅读他组文档与代码，攻击对方代码漏洞（可以从运行时间、扩展性、可读性等多方面论证自己小组的优劣）

#### 作业内容：对N=2^30个32位int整数排序
- 使用至少2种语言（至少包含c++和python)
- 支持至少2种操作系统（至少包含Linux, windows）
- 提供他组便与编译、运行、测试的脚本/文档说明等
- 分别实现数据生成、数据排序、排序验证功能
- 排序算法不得调用库函数（只需实现1种排序算法即可）


## 第9课：远程调用(先做第9课，再做第8课，第2~7课自学)

### 知识要点

- 网络通信 (ip, port, http, client-server模式)
- Server端：Web Service (flask: http server, GET/POST: RESTful API)
- Client端：Web 请求 (requests: python库, curl: Linux命令行工具)

### 课后作业：远程排序

#### 作业内容
- Server端至少实现两个RESTful API：
  - `"POST /upload_data"`: 接收Client上传的数据文件`data.txt`（格式见后文）,临时保存到本地（排序函数需要基于`第1课`的程序）
  - `"GET /sort"`: 对之前临时保存的Client上传的数据文件进行排序，返回排序后的数据文件data.sorted.json（格式见后文）
- Client端至少实现：
  - 生成数据文件`data.txt`（需要基于`第1课`的程序）
  - 访问Server端的`"POST /upload_data"`这个API，上传数据文件`data.txt`
  - 访问Server端的`"GET /sort"`这个API，接收Server所返回的排序结果`data.sorted.json`
  - 对`data.sorted.json`中的排序结果进行验证（需要基于`第1课`的程序）
- 选做：
  - Server欺骗Client：`"GET /sort"`有时返回正确的排序结果，有时故意返回错误的排序结果
  - Client看破Server：能够正确的验证Server所返回的`data.sorted.json`是否是从小到大排列的

#### 作业要求
- Server和Client均独立实现
- Server可以参考示例代码`app.py`和`app.sh`（实例代码中只实现了`"GET /sort_verify"作为参考`，并未实现作业所要求的`"GET /sort"`)
- Client可以选择用python的requests库实现，也可以用Linux的curl工具实现，也可以两个都实现
- `data.txt`的格式：一个纯文本文件，分2行，第1行是数据个数N，第2行是空格分隔的N个整数，形如
```
5
9 3 7 1 2
```

- `data.sorted.json`的格式，形如
```json
{
    "N":5,
    "data":[1,2,3,7,9]
}
```

## 第8课：并行计算、分布式计算

### 知识要点
- 串行排序（也即单机单核排序，`第1课`内容）
- 远程调用（`第9课`内容）
- 并行桶排序算法（master按值域分配子任务，slave(s)独立串行排序，master合并子任务结果）

### 课后作业：并行排序、分布式排序

#### 作业内容
- 实现client功能(`第9课`内容)
  - 生成数据文件`data.txt`
  - 访问master的`"POST /upload_data"`接口，上传数据文件`data.txt`
  - 访问master的`"GET /sort"`接口，接收master所返回的排序结果`data.sorted.json`
- 实现master功能
  - 实现`"POST /upload_data"`接口， 接收Client上传的数据文件`data.txt`（格式见后文）,临时保存到本地(`第9课`内容)
  - 实现`"GET /sort"`接口，指挥slave(s)进行分布式排序，给client返回排序结果
  - 实现`"GET /register"`接口，记录各slave的ip,port
  - 实现`"send_data()"`接口，访问slave(s)
  - 实现`POST /receive_data`接口，接收已排序数据
- 实现slave功能
  - 实现`"POST /receive_data"`接口，接收待排序数据
  - 实现`"send_data()"`接口，发送已排序数据


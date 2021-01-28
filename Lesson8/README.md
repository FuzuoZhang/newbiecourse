#### 分布式排序

---

##### 知识要点

- 串行排序（也即单机单核排序，`第1课`内容）

- 远程调用（`第9课`内容）

- 并行桶排序算法（master按值域分配子任务，slave(s)独立串行排序，master合并子任务结果）


##### 课后作业：并行排序、分布式排序

**作业内容**

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



##### 运行程序

```bash
sh run.sh
```

注：`config.py`和`run.sh`中的IP，Port设置要一致。

##### 程序功能



1. 生成待排序数，`distributed_sorter.py`需要传入N（数据个数），M（并行进程个数，若该项参数空默认为cpu个数）；
2. 将待排数据按照桶排序的规则分为M份；
3. `app.sh`启动三个在监听的进程；
4. 将M份数据上传至进程的`/sort` url，并接收返回的已排序的数据；
5. 将M份已排序数据组合为原数据的有序数据，验证，以`json`格式打印出来。
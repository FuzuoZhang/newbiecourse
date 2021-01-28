# client
## python (requests库)
暂无
## curl

### 1. 启动master
```
sh app.sh
```
或者
```
export FLASK_APP=app.py
export FLASK_ENV=development
export FLASK_DEBUG=1
python -m flask run --host=node2 --port=34567
```

### 2. 启动client
client代码见`client.curl.sh`
#### 2.1 生成数据
```
N=100
python data_generator.py $N > tmp/data.txt
```
或者将`data.txt.default`重命名为`data.txt`

#### 2.2 调用master的"POST /sort", 将数据传递给master， 接收返回的排序结果
```
curl -X POST -F "file=@tmp/data/txt" node2:34567
```

### 3. 浏览器访问master
从自己电脑浏览器中访问`node2:34567`，按提示操作


# curl 用法
注意：curl只能在Linux shell中使用
## GET
```
curl net.tsinghua.edu.cn
curl net.tsinghua.edu.cn/wired
curl net.tsinghua.edu.cn/wired/ #结尾的'/'有与没有是不同的
```

## POST
`-X`指明`POST`
`-H`指明`json`
`-d`指明参数
`-v` verbose
```
curl localhost:34567 -X POST -H "Content-Type:application/json" -d '"title":"comewords","content":"articleContent"' -v
```

## POST 上传文件
`-F "file=@__FILE__PATH__"`要上传的文件路径
```
curl localhost:34567 -F "file=@./tmp/data.txt" -v
```
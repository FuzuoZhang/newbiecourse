export FLASK_APP=app.py
export FLASK_ENV=development

# 在后台启动3各slave进程。注意地址和端口要和config.yaml文件一致
nohup python -m flask run --host=localhost --port=1234 > slave0.log &
nohup python -m flask run --host=localhost --port=1235 > slave1.log &
nohup python -m flask run --host=localhost --port=1236 > slave2.log &

# 运行分布式排序
N=100 #数据的个数
M=3 #slave的个数
python distributed_sorter.py $N $M
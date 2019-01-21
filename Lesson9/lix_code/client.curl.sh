#这里是用curl工具实现的client，与master进行交互
# 设定参数
N=100 #数据个数 $N
TEMP_DIR="./tmp"
mkdir -p $TEMP_DIR
DATA_TXT="$TEMP_DIR/data.txt"
MASTER_ADDR="localhost"
MASTER_PORT="34567"
#设定子程序路径
BASE_DIR=".."  
DATA_GENERATOR=$BASE_DIR/Lesson1/data_generator.py

# 生成数据, 符合 data.txt 格数要求，首行为$N，次行为空格分隔的N个整数
python $DATA_GENERATOR $N > $DATA_TXT

# 访问master的"POST /upload_data", 将data.txt发送给master
curl $MASTER_ADDR:$MASTER_PORT # 测试master的"GET /"
curl $MASTER_ADDR:$MASTER_PORT/upload_data # 测试master的"GET /upload_data"
curl $MASTER_ADDR:$MASTER_PORT/upload_data -X POST -F "file=@$DATA_TXT" -v # 测试master的"POST /upload_data", 并上传文件

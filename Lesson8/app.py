import os
import sys
from flask import Flask, flash, request, Response, redirect, session 
from werkzeug.utils import secure_filename
import numpy as np
import json

UPLOAD_FOLDER = '.'  #上传文件所保存的文件夹
ALLOWED_EXTENSIONS = set(['txt', 'json'])
os.makedirs(UPLOAD_FOLDER, exist_ok=True) #确保文件夹存在
#os.popen('mkdir -p {}'.format(UPLOAD_FOLDER)) 

app = Flask(__name__)
app.config['UPLOAD_FOLDER'] = UPLOAD_FOLDER
app.config['SECRET_KEY'] = os.urandom(24)


# 处理根'/'
@app.route('/', methods=['GET'])
def main():
    return redirect('/upload_data')


# 处理文件上传
def allowed_file(filename):
    return '.' in filename and \
           filename.rsplit('.', 1)[1].lower() in ALLOWED_EXTENSIONS

@app.route('/upload_data', methods=['GET', 'POST'])
def upload_file():        
    print(request.files)
    print(request.form)
    if request.method == 'POST':
        # check if the post request has the file part
        if 'file' not in request.files:
            print('No file part')           
            return redirect(request.url)
        
        file = request.files['file']
        # N = int(request.json['N'])
        # if user does not select file, browser also
        # submit an empty part without filename
        if file.filename == '':
            print('No selected file')
            return redirect(request.url)
        
        if file and allowed_file(file.filename):
            filename = secure_filename(file.filename)
            filename_save = filename + '.' + request.environ['REMOTE_ADDR'] + '.txt'
            filepath_save = os.path.join(app.config['UPLOAD_FOLDER'], filename_save)
            session['filepath_save'] = filepath_save            
            file.save(filepath_save) #将用户上传的文件保存到本地磁盘
            return redirect('/sort') #执行排序，返回排序后的data.sorted.json
    return '''
    <!doctype html>
    <title>Upload new File</title>
    <h1>Upload new File</h1>
    <form method=post enctype=multipart/form-data>
      <p>
        <input type=file name=file>
        <input type=submit value="Upload data.txt">
      </p>
    </form>

    '''

# 排序,接收一个data.json，形如{"N":3,"data":[1,6,3]}
def sort(data):
    return np.sort(data)
@app.route('/sort', methods=['POST'])
def sort_handler():
    content = request.json #是一个dict,形如{"N":3,"data":[1,6,3]}
    data = np.array(content['data'], dtype=np.int32)
    data.sort()    
    content['data'] = data.tolist()
    #return Response(json.dumps(ret),  mimetype='application/json')
    return json.dumps(content)


if __name__ == '__main__':
    app.run(host='0.0.0.0', port=60000, debug=1)
    '''
    curl http://node2:60000/sort -X POST -H "Content-Type: application/json" -d '{"N":3,"data":[1,6,3]}'

    python -c 'import requests; print(requests.post("http://localhost:60000/sort", json={"N":3,"data":[1,6,3]}).json())'
    '''


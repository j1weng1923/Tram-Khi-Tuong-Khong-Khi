from flask import Flask, request, jsonify, render_template
from flask_cors import CORS
import time

app = Flask(__name__)
CORS(app)  # Cho phép frontend gọi từ cùng server

data_store = []

@app.route('/')
def home():
    return render_template("index.html")

@app.route('/api/data', methods=['GET'])
def get_data():
    return jsonify(data_store)

@app.route('/airquality', methods=['POST'])
def post_data():
    new_data = request.json
    if not new_data:
        return jsonify({"error": "No data received"}), 400

    # Cập nhật vị trí trạm tại Hà Đông, Hà Nội
    new_data["timestamp"] = time.time()
    new_data["lat"] = 20.959968       # Vĩ độ Hà Đông
    new_data["lng"] = 105.758247      # Kinh độ Hà Đông
    new_data["name"] = "Trạm Hà Đông"

    data_store.append(new_data)
    print(f"📥 Dữ liệu nhận được: {new_data}")
    return jsonify({"status": "received"}), 200

if __name__ == '__main__':
    app.run(host='0.0.0.0', port=5000)

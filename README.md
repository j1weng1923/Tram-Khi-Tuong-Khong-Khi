# Trạm Khí Tượng Không Khí

## Giới Thiệu
Dự án **Trạm Khí Tượng Không Khí** xây dựng một hệ thống thu thập, giám sát và phân tích dữ liệu môi trường khí quyển theo thời gian thực. Mục tiêu của hệ thống là cung cấp các chỉ số quan trọng như nhiệt độ, độ ẩm, áp suất và chất lượng không khí, hỗ trợ dự báo thời tiết và cảnh báo ô nhiễm, góp phần bảo vệ sức khỏe cộng đồng.

![Giao diện trạm khí tượng không khí](images/GiaoDien.png)

## Tính Năng Chính
- **Thu thập dữ liệu môi trường**: Hệ thống thu thập thông tin về nhiệt độ, độ ẩm, áp suất và các chất ô nhiễm từ các cảm biến môi trường như MQ135, DHT22, v.v.
- **Hiển thị dữ liệu thời gian thực**: Dữ liệu từ các cảm biến được cập nhật và hiển thị trên giao diện web, cho phép người dùng theo dõi các chỉ số môi trường ngay lập tức.
- **Lưu trữ và phân tích dữ liệu lịch sử**: Dữ liệu thu thập được lưu trữ và có thể phân tích để nhận diện xu hướng thay đổi của các yếu tố môi trường.
- **Cảnh báo ô nhiễm**: Hệ thống tự động cảnh báo khi các chỉ số môi trường vượt quá ngưỡng cho phép, giúp người dân và cơ quan quản lý kịp thời đưa ra các biện pháp phòng ngừa.

![Biểu Đồ](images/BieuDo.png)

## Công Nghệ Sử Dụng

- **Phần cứng**:
  - **ESP32**: Vi điều khiển để thu thập và truyền dữ liệu từ các cảm biến.
  - **Cảm biến khí**: MQ135 (chất ô nhiễm không khí), DHT22 (nhiệt độ và độ ẩm).
  
- **Phần mềm**:
  - **Python**: Ngôn ngữ lập trình chính cho backend của hệ thống.
  - **Django**: Framework Python để phát triển backend và API cho hệ thống.
  
- **Frontend**:
  - **ReactJS**: Sử dụng ReactJS để xây dựng giao diện web, hiển thị dữ liệu môi trường thời gian thực.
  - **HTML/CSS/JavaScript**: Các công nghệ cơ bản cho giao diện người dùng.

- **Cơ sở dữ liệu**:
  - **PostgreSQL** hoặc **SQLite**: Hệ quản trị cơ sở dữ liệu được sử dụng để lưu trữ dữ liệu môi trường và lịch sử.

## Hướng Dẫn Cài Đặt

Để triển khai và chạy dự án, bạn có thể làm theo các bước dưới đây:

### Bước 1: Clone Repository

git clone https://github.com/j1weng1923/Tram-Khi-Tuong-Khong-Khi.git
cd Tram-Khi-Tuong-Khong-Khi

Bước 2: Cài Đặt Các Thư Viện Phụ Thuộc
Chạy lệnh sau để cài đặt các thư viện cần thiết:

pip install -r requirements.txt
Bước 3: Chạy Server
Khởi động server Django để ứng dụng có thể hoạt động:

python manage.py runserver
Bước 4: Truy Cập Giao Diện Web
Sau khi chạy server thành công, bạn có thể truy cập ứng dụng thông qua trình duyệt tại địa chỉ:

http://127.0.0.1:8000
Liên Hệ
Tác giả: Nguyễn Duy Quang

Email: quangduy1923@gmail.com

Chúc bạn thành công với dự án Trạm Khí Tượng Không Khí!

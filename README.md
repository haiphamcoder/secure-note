# SecureNote

**SecureNote** là một phần mềm ghi chú bảo mật dành cho hệ điều hành **Ubuntu 20.04**, được xây dựng với giao diện đồ họa sử dụng **GTK3**. SecureNote cho phép bạn tạo các ghi chú và mã hóa chúng bằng mật khẩu để bảo vệ thông tin cá nhân.

## 🎯 Tính năng chính

- Tạo và lưu trữ ghi chú bảo mật.
- Đặt mật khẩu cho từng ghi chú để bảo vệ thông tin.
- Mã hóa nội dung ghi chú sử dụng thuật toán AES-256 thông qua thư viện OpenSSL.
- Giao diện người dùng trực quan, dễ sử dụng.

## 📂 Cấu trúc thư mục

```
secure-note/
├── src/               # Mã nguồn chính
│   ├── main.c         # Điểm bắt đầu của ứng dụng
│   ├── gui.c          # Các hàm liên quan đến giao diện GTK3
│   ├── gui.h          # Header file cho gui.c
│   ├── crypto.c       # Các hàm liên quan đến mã hóa
│   └── crypto.h       # Header file cho crypto.c
├── assets/            # Các tài nguyên như icon, hình ảnh
├── data/              # Thư mục lưu các file ghi chú đã mã hóa
├── include/           # Các file header chung
├── Makefile           # Tệp Makefile để build project
└── README.md          # Thông tin và hướng dẫn sử dụng project
```

## 🛠️ Yêu cầu hệ thống

- **Ubuntu 20.04**
- **GTK3** (libgtk-3-dev)
- **OpenSSL** (libssl-dev)
- **GCC** (Compiler)

## 🔧 Cài đặt và Build

### Bước 1: Cài đặt các thư viện cần thiết

Trên Ubuntu 20.04, sử dụng lệnh sau để cài đặt các thư viện:

```bash
sudo apt update
sudo apt install libgtk-3-dev libssl-dev
```

### Bước 2: Clone repository và build project

```bash
git clone https://github.com/haiphamcoder/secure-note.git
cd secure-note
make
```

### Bước 3: Chạy chương trình

```bash
./secure-note
```

## 📝 Hướng dẫn sử dụng

1. Mở ứng dụng SecureNote.
2. Nhấp vào nút "Create New Note" để tạo ghi chú mới.
3. Nhập nội dung ghi chú và đặt mật khẩu để mã hóa ghi chú.
4. Lưu ghi chú và ghi chú sẽ được lưu trữ dưới dạng mã hóa trong thư mục `data/`.

## 🔒 Bảo mật

SecureNote sử dụng thuật toán mã hóa **AES-256** thông qua thư viện **OpenSSL**, giúp bảo vệ nội dung ghi chú khỏi truy cập trái phép.

## 🤝 Đóng góp

Nếu bạn muốn đóng góp cho dự án, hãy:

1. Fork repository.
2. Tạo nhánh mới (`git checkout -b feature/your-feature`).
3. Commit thay đổi (`git commit -m 'Thêm tính năng mới'`).
4. Push lên nhánh (`git push origin feature/your-feature`).
5. Tạo Pull Request.

## 📜 Giấy phép

Dự án này được phát hành theo giấy phép **MIT License**. Xem thêm trong file [LICENSE](./LICENSE).

## 📧 Liên hệ

Nếu bạn có bất kỳ câu hỏi hoặc góp ý nào, vui lòng liên hệ qua:

- Email: [ngochai285nd@gmail.com](mailto:ngochai285nd@gmail.com)
- GitHub: [https://github.com/haiphamcoder](https://github.com/haiphamcoder)
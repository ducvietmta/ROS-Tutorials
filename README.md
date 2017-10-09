# ROS-Tutorials
## 1. Install Prerequisites
* __Install [Ubuntu 14.04](http://www.ubuntu.com)__
* [ROS installation](http://wiki.ros.org/ROS/Installation)
## 2 .ROS file system level
### * ROS Packages:
![screenshot from 2017-10-06 10-01-06](https://user-images.githubusercontent.com/24909880/31261292-6e85cf12-aa7d-11e7-9c98-2e640be14450.png)

Gồm những folder sau: config, include, scripts, src, launch, msg, srv, action và những file: package.xml, CMakeLists.txt.
- config: các file cấu hình của package
- include: các header và các thư viện (library) 
- scripts: các file python
- src:  các file C++
- launch: các launch file để chạy 1 hoặc nhiều node
- msg: các file message tự tạo
- srv: các file service
- action: các file action (*actionlib)
- package.xml: file chứa các khai xuất của package (package này có những gì và dùng những gì)
- CMakeLists.txt: CMake file của package (để hướng dẫn máy tính tạo các folder, executables, dependencies, target libraries)
### * ROS Computational Graph Level:
![computational graph level](https://user-images.githubusercontent.com/24909880/31260959-b508487c-aa7b-11e7-84ec-7f08d927430c.PNG)
* ROS Node:
Là các process mà thi hành các tính toán trong dùng thư viện của ROS (C++/Python)
* ROS Message:
ROS node có thể publish các dữ liệu. Loại dữ liệu sẽ dc khai ở trong ROS Message. Các message thường có 2 phần: field và constant. Field gồm field type (loại dữ liệu - string, int8, float, time…) và field name. Constant gồm các giá trị ko đổi.
ROS message còn có các header. Các header dùng để cho người lập trình biết dc mốc thời điểm gửi message, ai gửi hay thứ tự của message.
* ROS Topic:
1 loại trao đổi thông tin giữa 2 node 1 chiều. ROS Topic thường dùng TCP/IP (TCPROS), nhưng cũng có thể dùng UDP/IP (UDPROS) cho các trao đổi mà cần tốc độ chuyển giao cao, thời điểm thông tin dc chuyển giao ko cần quá chính xác. UDPROS thường đc dùng cho teleoperation (dung lượng+băng truyền thấp).
ROS Service:
1 loại thông tin 2 chiều (request ←→ respond) giữa các node. 1 node sẽ gửi 1 request và đợi respond của node còn lại. Giao tiếp giữa 2 node vẫn dùng ROS message. Thường được dùng cho camera hoặc cảm biến 3D (dung lượng và băng truyền cao)
* ROS Bags:
Dùng để giữ lại dữ liệu ROS Message từ các topic và các service. Các Bag có thể ghi lại, chơi lại và sửa lại các dữ liệu. Thường dùng cho việc data logging.
* ROS Master: 
Giống 1 hệ thống DNS, khi bất kì node nào khởi động, nó sẽ tìm đến ROS Master và đăng kí tên của mình. Khi node thay đổi, ROS Master sẽ có lệnh call-back đến node đó và ghi lại sự thay đổi. Khi node pubish 1 topic, dữ liệu của topic đc đẩy đến ROS Master và ROS Master sẽ kiểm tra xem còn node nào khác subscribe đến cái topics đó ko. Nếu có, ROS Master sẽ chia sẻ thông tin topic đến node đó
* ROS Parameter:
Công cụ dùng để ghi nhớ dữ liệu mà các node có thể truy cập vào, đọc và chỉnh sửa. Thường được dùng cho các dữ liệu như các tham số P, I, D trong 1 PID loop.


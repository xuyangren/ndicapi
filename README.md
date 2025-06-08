# 1.配置USB串口
将70-ttyusb.rules放到/etc/udev/rules.d/目录下，重新插入串口
```shell
sudo usermod -aG dialout <YOUR non-root USER>
```


# 2.编译gst-plugins-base:
首先安装gstreamer
```sehll
sudo apt-get install libgstreamer1.0-dev
```
然后跳转到gst-plugins-base-1.16.1的文件夹下，执行configure文件，该文件无扩展名
```sehll
./configure
make
sudo make install
```

# 3.这里有两个API版本，先编译ndicapi-master，在该文件夹下运行:
```sehll
mkdir build
cmake ..
make -j  
sudo make install
```
然后可以通过find_package 找到 ndicapi

# 4.编译NDI-master  
直接make
运行:
```sehll
./build/linux/capisample /dev/ttyUSB0 
```
## 4.1 使用ttyUSB0的时候，如果是在wsl系统中运行，需要先穿过Windows系统绑定usb
1 **列出和绑定 USB 设备**：
   - 在 Windows 的 PowerShell（**以管理员身份运行**）中，列出所有 USB 设备：
     ```powershell
     usbipd list
     ```
     - 找到你的 USB 串口设备（例如 Silicon Labs CP210x USB to UART Bridge），记下其 `BUSID`。
   - 绑定设备以共享到 WSL：
     ```powershell
     usbipd bind --busid <BUSID>
     
     ```

2. **将 USB 设备附加到 WSL2**：
   - 附加设备到 WSL：
     ```powershell
     usbipd attach --busid <BUSID>
     ```
     - 如果需要自动附加，可以使用：
       ```powershell
       usbipd wsl attach --auto-attach --busid <BUSID>
       ```
# 5.编译project文件夹下的文件
 需要更改CMakeLists.txt文件夹下的set(NDI_FILE /home  这一行的path到NDI-master实际所在path
 更改set( CMAKE_BUILD_TYPE "Debug" )到set( CMAKE_BUILD_TYPE "Release" )
 然后
 ``` shell
mkdir build
cd build/
cmake ..
```
 

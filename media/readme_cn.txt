1.  media 顶层 Makefile 使用说明

具体命令如下：

(1)编译整个media目录：
   make  clean
   make

(2)查看编译配置
    make  info

(3)清除整个media目录的编译文件：
    make  clean

(4)单独编译各个模块：
    举例：编译RKAIQ（即isp目录）模块
        (4.1) 先确认cfg/cfg.mk 里已配置 CONFIG_RK_RKAIQ=y
        (4.2) cd isp; make clean; make

2. 编译生成的文件存放目录说明
out
├── avs_calib --------------------------------- 全景拼接标定数据
├── bin---------------------------------------- 各个模块的测试sample
├── include------------------------------------ 各个模块的头文件
├── isp_iqfiles-------------------------------- Camera Sensor的IQ文件
├── lib---------------------------------------- 各个模块的库件
├── root--------------------------------------- 必须放在根文件系统里的对应目录的文件
└── share-------------------------------------- 各个模块的配置文件

3.  media目录结构说明：
media
├── alsa-lib----------------------------------- Advanced Linux Sound Architecture (ALSA) library
├── cfg/cfg.mk--------------------------------- 针对不同SOC平台配置不同模块
├── common_algorithm--------------------------- 音频3A算法、移动检测、遮挡检测
├── isp---------------------------------------- isp图像处理算法
├── libdrm------------------------------------- Direct Rendering Manager
├── libv4l------------------------------------- video4linux2设备用户层接口
├── Makefile----------------------------------- media Makefile
├── Makefile.param----------------------------- media Makefile的配置文件
├── out---------------------------------------- media 编译输出目录
├── rga---------------------------------------- RGA是一个独立的2D硬件加速器，可用于加速点和线绘制
│                                               执行图像缩放、旋转、bitBlt、alpha混合等常见的2D图形操作
│
├── mpp---------------------------------------- 编解码接口,给rkmedia和rockit调用，不建议直接调用mpp
├── rkmedia------------------------------------ 多媒体处理框架,封装isp、rga、mpp等多媒体相关接口（适用部分平台）
└── rockit------------------------------------- 多媒体处理框架,和rkmedia是两套对外的接口


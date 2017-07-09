# SKEye-Linux-SDK
SKEye-Linux-SDK for Object Recognition Service 
###  更新日志
v1.0.0
- 发布常见物体识别、水果识别功能
###  目录介绍
- libs:include包含的头文件和.so文件。
- SKEyeSDKDemo:物体识别的demo(main.cpp)、资源文件resources(包含demo的图片)。
- 说明文档(SKEye-Linux-SDK说明文档V1.0.0.pdf)
###  使用步骤
- 下载SDK文件包。
- 将.so文件加载到对应工程目录下，并包含头文件"head.h"。
- 将资源文件resources下的图片放入对应的路径下。
- 运行代码。
- 更多使用介绍请参考 [《SKEye-Linux-SDK说明文档V1.0.0》](https://github.com/interjoy/SKEye-Linux-SDK/blob/master/SKEye-Linux-SDK%E8%AF%B4%E6%98%8E%E6%96%87%E6%A1%A3V1.0.0.pdf)。
###  调用示例
```
bool ReadBmp(char *filename, unsigned char *data)
{
	FILE *fp;
	fp = fopen(filename, "rb");
	if (fp == NULL) return false;
	fseek(fp, 54, SEEK_SET);
	int rlen = fread(data, 1, 640 * 480 * 3, fp);
	if (rlen != 640 * 480 * 3) return false;
	fclose(fp);
	return true;
}
void _JsonData(char *JsonData)
{
    printf("%s\n",JsonData);
}
char Api_Key[] = "466da4221010f834191q2da500b4a23b";
char Api_Secret[] = "ddc8bd498e7c29f929862ab1391a7b89";
char Image_Url[] = "http://pic.58pic.com/58pic/12/92/83/39j58PIChF6.jpg";
char service_name[] = "objects";
char PATH[1024] = "object3.jpg";
char  *JsonData;
unsigned char *data = new unsigned char[640 * 480 * 3];
if (!ReadBmp("4.bmp", data)) //读取图片
{
	printf("Open is error\n");
	return 0;
}
SKEyeSDK_Init(Api_Key, Api_Secret);
//URL
JsonData = SKEyeSDK_ImagePath(Image_Url, service_name);
//路径
JsonData = SKEyeSDK_ImagePath(PATH, service_name);
//URL(回调)
SKEyeSDK_ImagePath(Image_Url, service_name, _JsonData);
//路径(回调)
SKEyeSDK_ImagePath(PATH, service_name, _JsonData);
//rgb 
JsonData = SKEyeSDK_Image(data, With, Height, service_name);
//rgb 回调
SKEyeSDK_Image(data, With, Height, service_name, _JsonData);
```
###  SDK问题反馈
- SKEye开放平台QQ群：617518775

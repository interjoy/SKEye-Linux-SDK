# SKEye-Linux-SDK
SKEye-Linux-SDK for Object Recognition Service 
###  更新日志
v1.0.3
- 扩充图像识别接口，加入ImageId参数，方便确认请求顺序和返回顺序是否一致

v1.0.2
- 修改优化物体识别结果内存分配问题及Demo的修改

v1.0.1
- 修改优化网络部分

v1.0.0
- 发布常见物体识别、水果识别功能
###  目录介绍
- libs:include包含的头文件和.so文件。
- SKEyeSDKDemo:物体识别的demo(main.cpp)、资源文件resources(包含demo的图片)。
- 说明文档[《SKEye-Linux-SDK说明文档V1.0.3》](https://github.com/interjoy/SKEye-Linux-SDK/blob/master/SKEye-Linux-SDK%E8%AF%B4%E6%98%8E%E6%96%87%E6%A1%A3V1.0.3.pdf)
###  使用步骤
- 下载SDK文件包。
- 将.so文件加载到对应工程目录下，并包含头文件"head.h"。
- 将资源文件resources下的图片放入对应的路径下。
- 运行代码。
- 更多使用介绍请参考 [《SKEye-Linux-SDK说明文档V1.0.3》](https://github.com/interjoy/SKEye-Linux-SDK/blob/master/SKEye-Linux-SDK%E8%AF%B4%E6%98%8E%E6%96%87%E6%A1%A3V1.0.3.pdf)。
###  调用示例
```
//图片结果回调函数
void CallBackImageResultFunction(char *ImageResult)
{
	//这里添加代码
	printf("%s\n", ImageResult);
}
//将图像转成BGR、倒立、无行对齐位数据格式
int GetImageData(const char *ImagePath, unsigned char *&ImageData, unsigned int &ImageWidth, unsigned int &ImageHeight)
{
	CxImage Image;
	Image.Load(ImagePath);
	ImageWidth = Image.GetWidth();
	ImageHeight = Image.GetHeight();
	int ImageBMPSize = 0;
	unsigned char *ImageDataBuff = NULL;
	if (!Image.Encode(ImageDataBuff, ImageBMPSize, CXIMAGE_SUPPORT_BMP))
		return 0;
	ImageData = new unsigned char[ImageBMPSize];
	memcpy(ImageData, ImageDataBuff, ImageBMPSize);
	Image.FreeMemory(ImageDataBuff);
	return 1;
}
//图像识别回调Demo
void ImageCallBackDemoFuntion()
{
	//Image的本地绝对路径
	char ImageLocalPath[] = "4.bmp";
	char ServiceName[] = "objects";
	unsigned int ImageWidth, ImageHeight;
	unsigned char *ImageData = NULL;
	//得到处理后的图片数据ImageData
	if (!GetImageData(ImageLocalPath, ImageData, ImageWidth, ImageHeight))
	{
		printf("Get data failed\n");
		return;
	}
	SKEyeSDK_Image(ImageData, ImageWidth, ImageHeight, ServiceName, CallBackImageResultFunction);
	//需要外部释放
	delete[] ImageData;
}

//Url回调Demo
void UrlCallBackDemoFuntion()
{
	//图像url
	char ImageUrl[] = "http://pic.58pic.com/58pic/12/92/83/39j58PIChF6.jpg";
	//服务名
	char ServiceName[] = "objects";
	SKEyeSDK_ImagePath(ImageUrl, ServiceName, CallBackImageResultFunction);
}
//本地路径回调Demo
void LocalCallBackDemoFuntion()
{
	//Image的本地绝对路径
	char ImageLocalPath[] = "object3.jpg";
	//服务名
	char ServiceName[] = "objects";
	SKEyeSDK_ImagePath(ImageLocalPath, ServiceName, CallBackImageResultFunction);
}
//本地路径回调Demo+ImageId
void LocalCallBackDemoFuntion_ImageId()
{
    //Image的本地绝对路径
	char ImageLocalPath[] = "object3.jpg";
	int ImageId=0;
	//服务名
	char ServiceName[] = "objects";
	SKEyeSDK_ImagePath(ImageId,ImageLocalPath, ServiceName, CallBackImageResultFunction);
}
//本地路径Demo
void LocalDemoFuntion()
{
	//Image的本地绝对路径
	char ImageLocalPath[] = "object3.jpg";
	//服务名
	char ServiceName[] = "objects";
	//图像识别结果
	char  *ImageResult = SKEyeSDK_ImagePath(ImageLocalPath, ServiceName);
	printf("%s\n", ImageResult);
}
//Url Demo
void UrlDemoFuntion()
{
	//图像url
	char ImageUrl[] = "http://pic.58pic.com/58pic/12/92/83/39j58PIChF6.jpg";
	//服务名
	char ServiceName[] = "objects";
	//图片识别结果
	char  *ImageResult =SKEyeSDK_ImagePath(ImageUrl, ServiceName);
	printf("%s\n", ImageResult);
}
//图像识别Demo
void ImageDemoFuntion()
{
	//Image的本地绝对路径
	char ImageLocalPath[] = "4.bmp";
	char ServiceName[] = "objects";
	//图片处理函数
	unsigned int ImageWidth, ImageHeight;
	unsigned char *ImageData = NULL;
	char *ImageResult = NULL;
	//得到处理后的图片数据ImageData
	GetImageData(ImageLocalPath, ImageData, ImageWidth, ImageHeight);
	ImageResult = SKEyeSDK_Image(ImageData, ImageWidth, ImageHeight, ServiceName);
	delete [] ImageData;
	printf("%s\n", ImageResult);
}
int main()
{
	//SKEyeSDK_Init()初始化函数只初始化一次(不允许初始化多次)  将ApiKey和ApiSecret放入初始化函数内
	char ApiKey[] = "466da4221010f834191e2dac00b4a23b";
	char ApiSecret[] = "ddc8bd498e7c29f929862ab7391f7b89";
	SKEyeSDK_Init(ApiKey, ApiSecret);
	//本地路径Demo
	LocalDemoFuntion();
	//Url Demo
	UrlDemoFuntion();
	//图像识别Demo
	ImageDemoFuntion();
	//本地路径回调Demo
	LocalCallBackDemoFuntion();
	//本地路径回调Demo+ImageId
	LocalCallBackDemoFuntion_ImageId();
	//Url回调Demo
	UrlCallBackDemoFuntion();
	//图像识别回调Demo
	ImageCallBackDemoFuntion();
	return 0;
}
```
###  SDK问题反馈
- SKEye开放平台QQ群：617518775
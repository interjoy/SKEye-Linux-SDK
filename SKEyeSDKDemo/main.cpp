#include <iostream>
#include "LibFile.h"
#include "ximage.h"
//图片结果回调函数
void CallBackImageResultFunction(char *ImageResult)
{
	//这里添加代码
	printf("%s\n", ImageResult);
}
//将图像转成BGR、倒立、无行对齐位数据格式图像
int GetImageData(const char *ImagePath, unsigned char *&ImageData, unsigned int &ImageWidth, unsigned int &ImageHeight)
{
	CxImage Image;
	Image.Load(ImagePath);
	ImageWidth = Image.GetWidth();
	ImageHeight = Image.GetHeight();
	long ImageBMPSize = 0;
	unsigned char *ImageDataBuff = NULL;
	if (!Image.Encode(ImageDataBuff, ImageBMPSize, CXIMAGE_FORMAT_BMP))
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
	//图片处理函数
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
	char ApiKey[] = "366da4221010f834191e2da500b4a23b";
	char ApiSecret[] = "4dc8bd498e7c29f929862ab7391a7b89";
	SKEyeSDK_Init(ApiKey, ApiSecret);
	//本地路径Demo
	LocalDemoFuntion();
	//Url Demo
	UrlDemoFuntion();
	//图像识别Demo
	ImageDemoFuntion();
	//本地路径回调Demo
	LocalCallBackDemoFuntion();
	//Url回调Demo
	UrlCallBackDemoFuntion();
	//图像识别回调Demo
	ImageCallBackDemoFuntion();
	getchar();
	return 0;
}


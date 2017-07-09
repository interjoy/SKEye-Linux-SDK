#ifndef _CLIENT_H__
#define _CLIENT_H__
#include<string>
using namespace std;

//数据初始化
void SKEyeSDK_Init(char *ApiKey, char *ApiSecret);
//Url访问 图片路径访问
char *SKEyeSDK_ImagePath(char *UrlOrPath, char *ServiceName);
//图片+宽+高访问
char *SKEyeSDK_Image(unsigned char *ImageData, unsigned int ImageWide, unsigned int ImageHight, char *ServiceName);


typedef void(*CallBackImageResult)(char *ImageResult);
//Url访问 图片路径访问 回调方式
void SKEyeSDK_ImagePath(char *UrlOrPath, char *ServiceName, CallBackImageResult ImageResult);
//图片+宽+高访问 回调方式
void SKEyeSDK_Image(unsigned char *ImageData, unsigned int ImageWide, unsigned int ImageHight, char *ServiceName, CallBackImageResult ImageResult);
#endif

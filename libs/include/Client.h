#ifndef _CLIENT_H__
#define _CLIENT_H__
#include<string>
using namespace std;

//数据初始化
void SKEyeSDK_Init(char *_Api_Key, char *_Api_Secret);
//Url访问 图片路径访问
char *SKEyeSDK_ImagePath(char *UrlOrPath, char *service_name);
//图片+宽+高访问
char *SKEyeSDK_Image(unsigned char *ImageData, unsigned int Wide, unsigned int Hight, char *service_name);

//回调函数
typedef void(*CallBackJson)(char *JsonData);\
//Url访问 图片路径访问 回调方式
void SKEyeSDK_ImagePath(char *Url, char *service_name, CallBackJson _CallBackJson);
//图片+宽+高访问 回调方式
void SKEyeSDK_Image(unsigned char *ImageData, unsigned int Wide,unsigned int Hight,char *service_name,CallBackJson _CallBackJson);
#endif

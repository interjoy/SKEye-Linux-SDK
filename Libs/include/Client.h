#ifndef _CLIENT_H__
#define _CLIENT_H__
#include<string>
using namespace std;
#ifdef DLL_EXPORTS
#define DLLEXPORT __declspec(dllexport)
#else
#define DLLEXPORT __declspec(dllimport)
#endif

//数据初始化
extern "C" void SKEyeSDK_Init(char *_Api_Key, char *_Api_Secret);
//void SKEyeSDK_Init(char *_Api_Key, char *_Api_Secret);
//Url访问 图片路径访问
extern "C" char *SKEyeSDK_ImagePath(char *UrlOrPath, char *service_name);
//char *SKEyeSDK_ImagePath(char *UrlOrPath, char *service_name);
//图片+宽+高访问
extern "C" char *SKEyeSDK_Image(unsigned char *ImageData, unsigned int Wide, unsigned int Hight, char *service_name);
//char *SKEyeSDK_Image(unsigned char *ImageData, unsigned int Wide, unsigned int Hight, char *service_name);

//extern "C" char *SKEyeSDK_Jpg(char *JpgData, int JpgDataSize, char *service_name, char *C_JsonData);
//char *SKEyeSDK_Jpg(char *JpgData, int JpgDataSize, char *service_name, char *C_JsonData);


extern "C" typedef void(*CallBackJson)(char *JsonData);
//typedef void(*CallBackJson)(char *JsonData);
//Url访问 图片路径访问 回调方式
extern "C" void SKEyeSDK_ImagePath_CallBack(char *Url, char *service_name, CallBackJson _CallBackJson);
//void SKEyeSDK_ImagePath(char *Url, char *service_name, CallBackJson _CallBackJson);
//图片+宽+高访问 回调方式
extern "C" void SKEyeSDK_Image_CallBack(unsigned char *ImageData, unsigned int Wide,unsigned int Hight,char *service_name,CallBackJson _CallBackJson);
//void SKEyeSDK_Image(unsigned char *ImageData, unsigned int Wide,unsigned int Hight,char *service_name,CallBackJson _CallBackJson);
#endif

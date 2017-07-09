#ifndef _CLIENT_H__
#define _CLIENT_H__
#include<string>
using namespace std;

//���ݳ�ʼ��
void SKEyeSDK_Init(char *ApiKey, char *ApiSecret);
//Url���� ͼƬ·������
char *SKEyeSDK_ImagePath(char *UrlOrPath, char *ServiceName);
//ͼƬ+��+�߷���
char *SKEyeSDK_Image(unsigned char *ImageData, unsigned int ImageWide, unsigned int ImageHight, char *ServiceName);


typedef void(*CallBackImageResult)(char *ImageResult);
//Url���� ͼƬ·������ �ص���ʽ
void SKEyeSDK_ImagePath(char *UrlOrPath, char *ServiceName, CallBackImageResult ImageResult);
//ͼƬ+��+�߷��� �ص���ʽ
void SKEyeSDK_Image(unsigned char *ImageData, unsigned int ImageWide, unsigned int ImageHight, char *ServiceName, CallBackImageResult ImageResult);
#endif

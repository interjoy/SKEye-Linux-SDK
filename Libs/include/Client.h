#ifndef _CLIENT_H__
#define _CLIENT_H__
#include<string>
using namespace std;

//���ݳ�ʼ��
void SKEyeSDK_Init(char *_Api_Key, char *_Api_Secret);
//Url���� ͼƬ·������
char *SKEyeSDK_ImagePath(char *UrlOrPath, char *service_name);
//ͼƬ+��+�߷���
char *SKEyeSDK_Image(unsigned char *ImageData, unsigned int Wide, unsigned int Hight, char *service_name);

//�ص�����
typedef void(*CallBackJson)(char *JsonData);\
//Url���� ͼƬ·������ �ص���ʽ
void SKEyeSDK_ImagePath(char *Url, char *service_name, CallBackJson _CallBackJson);
//ͼƬ+��+�߷��� �ص���ʽ
void SKEyeSDK_Image(unsigned char *ImageData, unsigned int Wide,unsigned int Hight,char *service_name,CallBackJson _CallBackJson);
#endif

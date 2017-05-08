#include <iostream>
#include <stdio.h>
#include <string.h>
#include <unistd.h>  
#include "Head.h"
void _JsonData(char *JsonData)
{

	printf("%s\n", JsonData);
}
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

//·���ص�
void SKEyeSDK_ImagePath_CallBackFunction(char *PATH, char *service_name)
{
	SKEyeSDK_ImagePath(PATH, service_name, _JsonData);
}
//reb
void SKEyeSDK_Image_Function(int With, int Height, char *service_name)
{
	unsigned char *data = new unsigned char[640 * 480 * 3];
	if (!ReadBmp("4.bmp", data)) //��ȡͼƬ
	{
		printf("Open is error\n");
		return;
	}
	char *JsonData=SKEyeSDK_Image(data, With, Height, service_name);
	printf("%s\n", JsonData);
	delete[]JsonData;
}
//rgb�ص�
void SKEyeSDK_Image_CallBackFunction(int With, int Height, char *service_name)
{
	unsigned char *data = new unsigned char[640 * 480 * 3];
	char *JsonData;
	if (!ReadBmp("4.bmp", data)) //��ȡͼƬ
	{
		printf("Open is error\n");
		return;
	}
	SKEyeSDK_Image(data, With, Height, service_name, _JsonData);
}
unsigned char *ReadData(char *File, int &Datalen)
{
	FILE *fp;
	fp = fopen(File, "rb");
	fseek(fp, 0, SEEK_END);
	Datalen = ftell(fp);
	fseek(fp, 0, SEEK_SET);
	unsigned char *DataText = NULL;
	DataText = new unsigned char[Datalen];
	fread(DataText, Datalen, 1, fp);
	fclose(fp);
	fp = NULL;
	return DataText;
}

//·��
/**/
void SKEyeSDK_ImagePath_Function(char *PATH, char *service_name)
{ 
	char  *JsonData ;
	JsonData=SKEyeSDK_ImagePath(PATH, service_name);
	printf("%s\n", JsonData);
}

int main()
{
	char Api_Key[] = "466da4221010f834191e2da500b4a23b";
	char Api_Secret[] = "ddc8bd498e7c29f929862ab7391a7b89";
	char Image_Url[] = "http://pic.58pic.com/58pic/12/92/83/39j58PIChF6.jpg";
	char service_name_ob[] = "objects";
	char service_name_fr[] ="fruits";
	char PATH[1024]="object3.jpg";
	SKEyeSDK_Init(Api_Key, Api_Secret);
	SKEyeSDK_ImagePath_Function(Image_Url, service_name_fr);
	SKEyeSDK_ImagePath_CallBackFunction(PATH, service_name_ob);
	SKEyeSDK_Image_Function(640, 480, service_name_ob);
	SKEyeSDK_Image_CallBackFunction(640, 480, service_name_ob);
	getchar();
	return 0;
}

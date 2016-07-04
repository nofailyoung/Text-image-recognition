#include "BMP_Info.h"
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>	
using namespace std;

/****************************************************************
*	函数:	BMP_Info
*   参数:	_fd:图片文件的文件描述符
*	返回值: 无返回值
*   功能:	获得图片文件的文件描述符fd
*****************************************************************/
BMP_Info::BMP_Info(int _fd)
{
	fd = _fd;
}

/****************************************************************
*	函数:	BMP_Info
*   参数:	filename:图片文件的绝对路径
*	返回值: 无返回值
*   功能:	获得图片文件的文件描述符fd
*****************************************************************/
BMP_Info::BMP_Info(const char* filename)
{
	fd = open(filename,O_RDWR);
	if(fd == -1)
	{
		perror("open:");
		exit(-1);
	}
}

/****************************************************************
*	函数:	BmpShowHead
*   参数:	无参
*	返回值: 无返回值
*   功能:	打印输出位图的文件头信息
*****************************************************************/
void BMP_Info::BmpShowHead()
{
	BitMapFileHeader BmpHead;
	memset(&BmpHead,0,sizeof(BmpHead));
	read(fd,&BmpHead,sizeof(BmpHead));

	cout<<"位图文件头:"<<endl;    
    cout<<"文件头类型:"<<BmpHead.bfType<<endl;    
    cout<<"文件大小:"<<BmpHead.bfSize<<endl;    
    cout<<"保留字_1:"<<BmpHead.Reserverd1<<endl;    
    cout<<"保留字_2:"<<BmpHead.Reserverd2<<endl;    
    cout<<"实际位图数据的偏移字节数:"<<BmpHead.bfOffetBits<<endl<<endl;  
}

/****************************************************************
*	函数:	BmpShowInforHead
*   参数:	无参
*	返回值: 无返回值
*   功能:	打印输出位图的信息头信息
*****************************************************************/
void BMP_Info::BmpShowInforHead()
{
	BitMapInfoHeader BmpInfo;
	memset(&BmpInfo,0,sizeof(BmpInfo));
	lseek(fd,sizeof(BitMapFileHeader),SEEK_SET);
	read(fd,&BmpInfo,sizeof(BmpInfo));

	cout<<"位图信息头:"<<endl;    
    cout<<"结构体的长度:"<<BmpInfo.biSize<<endl;    
    cout<<"位图宽:"<<BmpInfo.biWidth<<endl;    
    cout<<"位图高:"<<BmpInfo.biHeight<<endl;    
    cout<<"biPlanes平面数:"<<BmpInfo.biPlanes<<endl;    
    cout<<"biBitCount采用颜色位数:"<<BmpInfo.biBitCount<<endl;    
    cout<<"压缩方式:"<<BmpInfo.biCompression<<endl;    
    cout<<"biSizeImage实际位图数据占用的字节数:"<<BmpInfo.biSizeImage<<endl;    
    cout<<"X方向分辨率:"<<BmpInfo.biXPelsPerMeter<<endl;    
    cout<<"Y方向分辨率:"<<BmpInfo.biYPelsPerMeter<<endl;    
    cout<<"使用的颜色数:"<<BmpInfo.biClrUsed<<endl;    
    cout<<"重要颜色数:"<<BmpInfo.biClrImportant<<endl;    
}


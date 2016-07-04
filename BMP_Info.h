/*
	时间:2016.07.03
	作者:龚高杰
	地点:中南林业科技大学
	内容:bmp图片文件的编码格式
*/

#ifndef _BMP_INFO_H_
#define _BMP_INFO_H_

#pragma pack(2)    //定义以2进行对齐

/*
	BitMapFileHeader:表示bmp文件头,提供文件的格式、大小等信息
	大小是:14个字节
*/
typedef struct BitMapFileHeader
{
	unsigned short  bfType;    		//文件的类型,必须是0x4D42,也就是字符'BM'   
	unsigned int    bfSize;          //说明该位图文件的大小,包括这个结构体   
	unsigned short  Reserverd1;      //保留字,必须将其设置为0                 
	unsigned short  Reserverd2;      //保留字,必须将其设置为0                
	unsigned int    bfOffetBits;     //说明从文件头开始到实际图像数据之间的字节偏移量
}BitMapFileHeader;

/*
	BitMapInfoHeader:表示位图的信息头,提供图像数据的尺寸、位平面数、压缩方式、颜色索引等信息
*/
typedef struct BitMapInfoHeader
{
	unsigned int biSize;       // 表示BitMapInfoHeader结构所需要的
	unsigned int biWidth;      // 说明图像的宽度,用像素为单位
    int biHeight;              // 说明图像的高度,以像素为单位,这个值还可以用来判断图像是不是倒置的
	unsigned short biPlanes;   // 为目标设备说明颜色平面数,值总是1
	unsigned short biBitCount; // 说明比特数/像素,其值为1,4,8,16,24或32
	unsigned int biCompression;// 说明图像的压缩类型.通常为0,表示不压缩
	unsigned int biSizeImage;  // 说明图像的大小,以字节为单位,当biCompression为BI_RGB的时候,可以将该值设置为0
	int biXPelsPerMeter;       // 说明水平分辨率
	int biYPelsPerMeter;       // 说明垂直分辨率
	unsigned int biClrUsed;    // 指定本图象实际用到的颜色数，如果该值为零，则用到的颜色数为2的biBitCount次方
	unsigned int biClrImportant; //指定本图象中重要的颜色数，如果该值为零，则认为所有的颜色都是重要的
}BitMapInfoHeader;


class BMP_Info
{
public:
	BMP_Info(int fd);
	BMP_Info(const char* filename);
	void BmpShowHead();    		 //显示bmp文件头的信息
	void BmpShowInforHead();     //显示位图的信息头的信息
private:
	int fd;	
};

#endif	



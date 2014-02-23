#include <stdio.h>
#include <windows.h>

#define LEN 8

int CutMp3(double strat,double end)
{
	FILE *fp_Read_Mp3,*fp_Write_Mp3;
	int i;
	char Buf[LEN];  //(128/8)*1024等于16KB，所以每次缓存16kb。且每次切割也是16kb
    long start=strat*1000;
    long endd=end*1000;
	fp_Read_Mp3 = fopen("E:/aa.mp3","rb");
	fp_Write_Mp3 = fopen("E:/la1.mp3","wb");

	if(fp_Read_Mp3 == NULL || fp_Write_Mp3 == NULL)
	{
		puts("Open the mp3 source failure!~");
		return 0;
	}
	
	fseek(fp_Read_Mp3,(long)(start*LEN),SEEK_CUR);


	puts("文件正在截取....");
	for (i=start; i<endd; i++)
	{
		fread(Buf,LEN,1,fp_Read_Mp3);
		fwrite(Buf,LEN,1,fp_Write_Mp3);
	}
	Sleep(1000);
	fclose(fp_Read_Mp3);
	fclose(fp_Write_Mp3);

	puts("音频截取成功！~");

	return 1;
}


int main()
{
	double m,n;
	int i;
	puts("请输入您要截取的时间：开始-->结束：");
	scanf("%lf %lf",&n,&m);
	printf("您要截取的时间段为：%lf~%lf\n",n,m);
	i = CutMp3(n,m);
	if (i == 1)
	{
		puts("恭喜您！~");
	}else
	{
		puts("截取失败！~");
	}
   return 0;
	/*根据不同的歌曲需要改变LEN的大小*/

}

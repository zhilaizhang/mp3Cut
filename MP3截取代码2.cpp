#include <stdio.h>
#include <windows.h>

#define LEN 8

int CutMp3(double strat,double end)
{
	FILE *fp_Read_Mp3,*fp_Write_Mp3;
	int i;
	char Buf[LEN];  //(128/8)*1024����16KB������ÿ�λ���16kb����ÿ���и�Ҳ��16kb
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


	puts("�ļ����ڽ�ȡ....");
	for (i=start; i<endd; i++)
	{
		fread(Buf,LEN,1,fp_Read_Mp3);
		fwrite(Buf,LEN,1,fp_Write_Mp3);
	}
	Sleep(1000);
	fclose(fp_Read_Mp3);
	fclose(fp_Write_Mp3);

	puts("��Ƶ��ȡ�ɹ���~");

	return 1;
}


int main()
{
	double m,n;
	int i;
	puts("��������Ҫ��ȡ��ʱ�䣺��ʼ-->������");
	scanf("%lf %lf",&n,&m);
	printf("��Ҫ��ȡ��ʱ���Ϊ��%lf~%lf\n",n,m);
	i = CutMp3(n,m);
	if (i == 1)
	{
		puts("��ϲ����~");
	}else
	{
		puts("��ȡʧ�ܣ�~");
	}
   return 0;
	/*���ݲ�ͬ�ĸ�����Ҫ�ı�LEN�Ĵ�С*/

}

     #include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>

#define LEN (128/8)

int CutMp3(double strat,double end,char a[])
{
	FILE *fp_Read_Mp3,*fp_Write_Mp3;
	int i;
	char Buf[LEN];  //(128/8)等于16B，所以每次缓存16b。且每次切割也是16b
    int   start=strat*1000;
    int   endd = end*1000;
	fp_Read_Mp3 = fopen("E:/song.mp3","rb");
	char name[80];
	strcpy(name,"E:/");
	int lena=strlen(a);
	for(int y=lena;y>0;y--)
	{
        if(a[lena]=='\r'||a[lena]=='\n'||a[lena]=='\0')
        {
            lena--;
        }
         else
         {
            continue;
         }
    }
    char temp[30];
    memset(temp,0,sizeof(temp));
    for(int y=0;y<=lena;y++)
    {
        temp[y]=a[y];
    }
	strcat(name,temp);
	strcat(name,".mp3");

	fp_Write_Mp3 = fopen(name,"wb");

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

double  stringToDouble(char buf[])
{
           char *endptr;
           double value=strtod(buf,&endptr);
           return value;
}

int main()
{
	double m,n;
	int i,h=0,k=0;
	int x=0;
	char str[500][30]; //用来保存所有的MP3文件名
	char buf[1024];    //临时存储一个MP3文件名
    double time1[500];   //用来保存时间点，每两个时间点确定一个MP3文件
     FILE *fp;
     int len;

     if((fp=fopen("E:/test1.txt","rb"))==NULL)
     {
    	puts("Open the txt source failure!~");
		return 0;
     }
      else
      {
        while(fgets(buf,1024,fp) != NULL)
        {
        len = strlen(buf);   //求字符串的长度
       // printf("%s\n",buf);
         char a1[6];
         memset(a1,0,sizeof(a1));
        int j=0;
         for(i=0;i<6;i++)       //从字符串中提取起始时间的字符串
         {
             a1[j++]=buf[i];
         }
         j=0;
         //printf("%s\n",a1);
        double startTime=stringToDouble(a1); //将起始时间的字符串变为double型的
        time1[k++]=startTime;
         memset(a1,0,sizeof(a1));
         for(i=7;i<13;i++)                // 从字符串中提取终止时间的字符串
         {
               a1[j++]=buf[i];
         }
         // printf("%s\n",a1);
         j=0;
         double endTime=stringToDouble(a1);  //将终止时间的字符串变为double型的
         time1[k++]=endTime;

         char name[100];
         memset(name,0,sizeof(name));
          for(i=14;i<len;i++)
          {
             name[j++]=buf[i];
          }
           printf("%s\n",name);
           strcat(str[h++],name);
        }
        fclose(fp);
      }
       for(i=0;i<k;i=i+2)
       {
        printf("%lf %lf %s",time1[i],time1[i+1],str[x]);
         int flag=CutMp3(time1[i],time1[i+1],str[x++]);
          	
	if (flag == 1)
	{
		puts("恭喜您！~");
	}
    else
	{
		puts("截取失败！~");
	}	
       }
	
	
//
   return 0;
	/*根据不同的歌曲需要改变LEN的大小*/
}





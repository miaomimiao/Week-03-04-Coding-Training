//合并两课四叉树黑色像素的个数
#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
#define len 32
#define Max 1024+10
char s[Max];
int buf[len][len],cnt;
void draw(const char*s,int& p,int r,int c,int w)
{
	char ch=s[p++];
	if(ch=='p')
	{
		draw(s,p,r,c+w/2,w/2);
		draw(s,p,r,c,w/2);
		draw(s,p,r+w/2,c,w/2);
		draw(s,p,r+w/2,c+w/2,w/2);
	}
	else if(ch=='f')
	{
		for(int i=r;i<r+w;i++)
			for(int j=c;j<c+w;j++)
				if(buf[i][j]==0)
				{
					buf[i][j]=1;
					cnt++;
				}
	}
}
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		memset(buf,0,sizeof(buf));
		cnt=0;
		for(int i=0;i<2;i++)
		{
			scanf("%s",s);
			int p=0;
			draw(s,p,0,0,len);
		}
		printf("There are %d black pixels.\n",cnt);
	}
	return 0;
}

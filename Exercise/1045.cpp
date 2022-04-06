#include <stdio.h>
#include <string.h>
int main(void)
{
    char s1[120], s2[120];
    while((scanf("%s %s",s1,s2))!=EOF)
    {
        int time[101]={0}, n1[51]={0}, n2[51]={0}, i, coe, exp, pro, sig;//coe：系数，exp：次数，pro：进程，sig：符号
        int m=strlen(s1), n=strlen(s2);
        //读第一个多项式
        for(i=0, coe=0, exp=1, pro=0, sig=1; i<m; i++)
        {
            if(s1[i]=='x'&&pro!=0) 
            {
                n1[0] = 0;
                n1[1] = coe;
                pro = 1;
            } //进程1，计算x的次数
            else if(s1[i]=='x'&&pro==0)
            {
                if(s1[i+1]=='^') 
                {
                    coe = 1 * sig;
                    pro = 1;
                }
                else 
                {
                    coe = 1 * sig;
                    n1[1] = coe;
                    pro = 1;
                }
            }
            else if(s1[i]=='^') 
            {
                continue; 
            }
            else if(pro!=1&&s1[i]=='+') 
            {
                sig = 1;
            } //加法
            else if(pro==1&&s1[i]=='+') 
            {
                pro = 0;
                sig = 1;
            }
            else if(pro!=1&&s1[i]=='-') 
            {
                sig = -1;
            } //减法
            else if(pro==1&&s1[i]=='-') 
            {
                pro = 0;
                sig = -1;
            }
            else if(pro==1)
            {
                exp=0;
                while(s1[i]>='0'&&s1[i]<='9')
                {
                    exp += s1[i] - '0';
                    if (s1[i + 1] >= '0' && s1[i + 1] <= '9')
                    {
                        exp *= 10;
                        i++;
                    }
                    else
                        break;
                }
                n1[exp]=coe;
                n1[1]=0;
                n1[0]=0;
            }
            else if(pro==0)//进程0，计算x的系数
            {
                coe=0;
                while (s1[i] >= '0' && s1[i] <= '9')
                {
                    coe += s1[i] - '0';
                    if (s1[i + 1] >= '0' && s1[i + 1] <= '9')
                    {
                        coe *= 10;
                        i++;
                    }
                    else 
                        break;
                }
                coe*=sig;
                n1[0]=coe;//暂时存储到0次项
                pro=2;//进程2，读取x
            }
        }

        
        //以下读第二个多项式
        for(i=0, coe=0, exp=1, pro=0, sig=1; i<n; i++)
        {
            if(s2[i]=='x'&&pro!=0) {n2[0]=0; n2[1]=coe; pro=1;}//进程1，计算x的次数
            else if(s2[i]=='x'&&pro==0)
            {
                if(s2[i+1]=='^') {coe=1*sig; pro=1;}
                else {coe=1*sig; n2[1]=coe; pro=1;}
            }
            else if(s2[i]=='^') continue;
            else if(pro!=1&&s2[i]=='+') {sig=1;}//加法
            else if(pro==1&&s2[i]=='+') {pro=0;sig=1;}
            else if(pro!=1&&s2[i]=='-') {sig=-1;}//减法
            else if(pro==1&&s2[i]=='-') {pro=0;sig=-1;}
            else if(pro==1)
            {
                exp=0;
                while(s2[i]>='0'&&s2[i]<='9')
                {
                    exp+=s2[i]-'0';
                    if(s2[i+1]>='0'&&s2[i+1]<='9'){exp*=10;i++;}
                    else break;
                }
                n2[exp]=coe;
                n2[1]=0;
                n2[0]=0;
            }
            else if(pro==0)//进程0，计算x的系数
            {
                coe=0;
                while(s2[i]>='0'&&s2[i]<='9')
                {
                    coe+=s2[i]-'0';
                    if(s2[i+1]>='0'&&s2[i+1]<='9'){coe*=10;i++;}
                    else break;
                }
                coe*=sig;
                n2[0]=coe;//暂时存储到0次项
                pro=2;//进程2，读取x
            }
        }
        //以下计算结果多项式的系数
        int j, ans[101], cnt=0;
        for(i=0; i<51; i++)
            for(j=0; j<51; j++)
                time[i+j]+=n1[i]*n2[j];
        for(i=100; i>=0; i--)
            if(time[i])
                ans[cnt++]=time[i];
        for(i=0; i<cnt-1; i++)
            printf("%d ",ans[i]);
        printf("%d\n",ans[i]);
    }
    return 0;
}
#include <stdio.h>
#include <string.h>


void bina(int x,int len)
{
    int temp;
    int list[len];
    for(int i=0;i<len;i++)
    {
        temp = x % 2;
        x = (x - x % 2) / 2;
        list[i] = temp;
    }
    for(int i=len-1;i>=0;i--)
    {
        printf("%d",list[i]);
    }
}

int main()
{
    char num[500];
    scanf("%s",&num);
    int length = strlen(num);
    int yu_shu = length % 3;
    int temp[((length-yu_shu) / 3) + 1];
    int sum = 0;
    for(int i=0;i<yu_shu;i++)
    {
        sum *= 10;
        sum += num[length-yu_shu+i] - 48;
    }
    temp[((length-yu_shu) / 3)] = sum;
    int j=0;
    for(int i=0;i<length-yu_shu;i+=3)
    {
        temp[j] =  (num[i] - 48) * 100 + (num[i+1] - 48) * 10 + (num[i+2] - 48);
        j++;
    }
    for(int i=0;i<(length-yu_shu)/3+1;i++)
    {
        //printf("%d ",temp[i]);
    }
    printf("0001");
    bina(length,10);
    for(int i=0;i<(length-yu_shu)/3;i++)
    {
        bina(temp[i],10);
    }
    switch (yu_shu)
    {
        case 1:
            bina(temp[(length-yu_shu)/3],4);
            break;
        case 2:
            bina(temp[(length-yu_shu)/3],7);
            break;
        default:
            break;
    }
    return 0;
}
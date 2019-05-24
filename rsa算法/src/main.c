#include<stdio.h>
#include"rsa.h"

int main()
{
    int p,q,e,m_c,mode;
    p=29;
    q=53;
    printf("两个素数是：%d,%d\n他们的乘积是：%d\n现在输入要加密或者解密的数字(小于乘积)：\n",p,q,p*q);
    scanf("%d",&m_c);
    printf("\n输入模式（加密是1，解密是2）：");
    scanf("%d",&mode);
    // printf("\n输入e(小于%d,且互质):",(p-1)*(q-1));
    // scanf("%d",&e);
    e=89;
    int MC;
    MC=rsa(p,q,e,m_c,mode);
    switch(mode)
    {
        case 1://加密
            printf("加密后的结果是：%d\n",MC);
            break;
        case 2://解密
            printf("解密后的结果是：%d\n",MC);
            break;
    }
    printf("%d\n",MC);
    return 0;
}
#include"rsa.h"

int rsa(int p,int q,int e,int m_c,int mode)
{
    int n=p*q;
    int t=(p-1)*(q-1);
    int M_C;
    if(e<1||e>t)
    {
        printf("e is error;\n");
        return -1;
    }
    int d=1;
    while(((e*d)%t)!=1){
        d++;
        if(d==t)return 0;
    }
    
    switch(mode)
    {
        case 1://加密
            M_C=candp(m_c,e,n);
            break;
        case 2://解密
            M_C=candp(m_c,d,n);
            break;
    }
    return M_C;
}

int candp(int a,int b,int c)
{
    int r=1;
    while(b!=0)
    {
        r=r*a;
        r=r%c;
        b--;
    }
    return r;
}

// int sushu(int m,int n)
// {
//     int rand=random(m,n);
//     while(!is(rand))rand++;
//     return rand;
// }

// int is(int n)
// {
//     if(n<=1)return 0;
//     for(int i=2;i<=(double)sqrt(n);i++)
//     {
//         if(n%i==0)return 0;
//     }
//     return 1;
// }

// int random(int m,int n) 
// { 
// srand((int)time(NULL)); 
// return(int)(m+rand()%n); 
// } 
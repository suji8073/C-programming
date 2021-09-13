#include <stdio.h>
int main(void)
{
    char ch, *cp;//char형 변수와 포인터 변수 정의
    int num, *ip;//int형 변수와 포인터 변수 정의
    float f_num, *fp;//float형 변수와 포인터 변수 정의
    double d_num, *dp;//double형 변수와 포인터 변수 정의
 
    ch = 'A'; num = 100;
    f_num = 5.6; d_num = 17.5;
    cp = &ch;//cp에 ch의 주소값 저장
    ip = &num;//ip에 num의 주소값 저장
    fp = &f_num;//fp에 f_num의 주소값 저장
    dp = &d_num;//dp에 d_num의 주소값 저장
 
    printf("1 증가하기 전 변수와 포인터 변수.\n");
    printf("변수들의 값 : %5c %5d %10.2f %10.2lf \n", ch, num, f_num, d_num);//A,100,5.6,17.5
    printf("포인터 변수에 저장된 주소 : %p %p %p %p \n\n", cp, ip, fp, dp);
 
    ch++; num++; f_num++; d_num++;//변수들 값 증가
    cp++; ip++; fp++; dp++;//포인터에 저장된 주소 값 증가
 
    printf("1 증가한 후 변수와 포인터 변수.\n");
    printf("변수들의 값 : %5c %5d %10.2f %10.2lf \n", ch, num, f_num, d_num);
    printf("포인터 변수에 저장된 주소 : %p %p %p %p \n\n", cp, ip, fp, dp);
    //cp는 char형: +1 증가
    //ip는 int형 : +4 증가
    //fp는 float형 : +4 증가
    //dp는 double형 : +8 증가
 
    return 0;
 
}

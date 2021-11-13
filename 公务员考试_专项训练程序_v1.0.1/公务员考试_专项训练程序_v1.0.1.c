#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main()
{
    int i1,i2=100,i3=0,i4=0,i5;
    double d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13,d14,d15;
    clock_t c1,c2,c3;

    c1=clock();
    printf("出题位数（输入小于且等于14的正整数）:\n");
    scanf("%lf",&d2);//设定出题位数
    printf("答题位数（输入小于且等于6的正整数）:\n");
    scanf("%lf",&d13);//设定答题位数
    printf("\n----------\n\n");

    for(;;)
    {
        c2=clock();//开始答题时间
        d3=(c2-c1)%251;//取0-250随机数
        d4=(c2-c1)%361;//取0-360随机数
        d5=(c2-c1)%491;//取0-490随机数
        d6=pow(10,d2);//出题位数的范围
        d14=pow(10,d13);//出题位数的范围
        d7=fabs(sin(d3+0.1));//取0-1随机数，+0.1是为了避免正弦为0
        d8=fabs(sin(d4+0.1));//取0-1随机数，+0.1是为了避免正弦为0
        d9=d6*d7;//取出题位数内的一个数，作为被除数
        d10=d6*d8;//取出题位数内的一个数，作为除数
        d11=d7/d8;//出题答案

        //------取答案前若干位数
        i1=(int)(d11*1000000);
        i5=(int)(d14);
        for(;i1>=i5;)//使答案不大于出题位数
        {
            i1=i1/10;
        }
        for(;i1<(i5/10);)//使答案不小于出题位数
        {
            i1=i1*10;
        }
        //------

        printf("%.2lf/%.2lf的前%.0lf位数是:\n",d9,d10,d13);
        scanf("%d",&i2);//答题
        c3=clock();//结束答题时间
        d12=(c3-c2)/1000.0;//本次答题时间
        if(i2==i1)
        {
            printf("\n对\n");
            i3++;
            d15=((c3-c1)/1000.0)/(double)i3;//平均答题时间
            printf("\n%.2lf秒（平均：%.2lf秒）",d12,d15);
        }
        else
        {
            printf("\n错【%d】\n",i1);
            i4++;
            d15=((c3-c1)/1000.0)/(double)i3;//平均答题时间
            printf("\n%.2lf秒（平均：%.2lf秒）",d12,d15);

        }
        printf("\n对\t错\n");
        printf("%d\t%d\n",i3,i4);
        printf("\n----------\n\n");
    }

    return 0;
}

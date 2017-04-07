#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "main.h"

int  main()
{
    FILE* fw;
    fw=fopen("4KB sequence.trace","w");
    srand((unsigned)time(NULL));
    int num=0;

    double timestamp=0;
    int sector_num=8;
    int start_sector=0;

    int rand1;//读写比例
    int rand2;//冷 热访问比例
    while(num<100000)
    {
        /*rand2=rand()%10;
        if(rand2<8)
        {
            start_sector=get_rand_num(hot_space);
        }
        else
        {
          start_sector=hot_space+get_rand_num(user_space-hot_space-sector_num);
        }*/
        if(start_sector>=user_space-sector_num)
        {
            start_sector=0;
        }

        rand1=rand()%10; //读写比例
        if(rand1>=0 &&rand1 <7)
        {
             fprintf(fw,"0,%d,%d,r,%lf\n",start_sector,sector_num*512,timestamp);
        }
        else
        {
            fprintf(fw,"0,%d,%d,w,%lf\n",start_sector,sector_num*512,timestamp);
        }
        start_sector+=sector_num;

/*20%的时间戳20-400ms  80%的时间戳0-20ms
        rand2=rand()%10;
        if(rand2<8)
        {
             timestamp += (rand()%21)*0.001;
        }
        else
        {
            timestamp += (rand()%381)*0.001+0.02;
        }*/
        timestamp += (rand()%11)*0.001;

        num++;

    }
   fclose(fw);
   return 0;

}

//生成num之内的随机数
int get_rand_num(int num)
{
    int return_num=0;
    if(num<=0)
    {
        printf("valid rand num request!!\n");
        return -1;
    }
    if(num<=max_default_rand_num)
    {
        return rand()%num;
    }
    else
    {
        int count=num/(max_default_rand_num-1);
        int rem=num%(max_default_rand_num-1);
        int i=rand();

        return_num=i*count+rand()%rem;
    }
    return return_num;
}



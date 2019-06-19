#include "mean.h"
#include<stdint.h>

void sig_mean(double *sig_src_arr,uint32_t blockSize, double *result){
    double sum=0.0;
    uint32_t blkCnt;
    //double in1,in2,in3,in4;
    blkCnt = blockSize>>2U; //blkCnt = blockSize/2^2 = blockSize/4;

    while(blkCnt>0){
        /*c = A[0]+A[1]+A[3]+.......+A[blockSize-1]*/
        /*in1=*sig_src_arr++;
        in2=*sig_src_arr++;
        in3=*sig_src_arr++;
        in4=*sig_src_arr++;

        sum+=in1;
        sum+=in2;
        sum+=in3;
        sum+=in4;*/

        sum+=*sig_src_arr++;
        sum+=*sig_src_arr++;
        sum+=*sig_src_arr++;
        sum+=*sig_src_arr++;
        blkCnt--;
    }
    blkCnt = blockSize%0x4;
    while(blkCnt>0){
        sum+=*sig_src_arr++;
        blkCnt--;
    }
    *result=sum/(double)blockSize;
}

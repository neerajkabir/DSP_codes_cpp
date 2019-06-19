#include <iostream>
#include "mean.h"
#define BLOCKSIZE 320

using namespace std;
extern double InputSignal_f32_1kHz_15kHz[BLOCKSIZE];
double mean;
int main()
{
    sig_mean(InputSignal_f32_1kHz_15kHz,BLOCKSIZE,&mean);
    cout << "Mean = " <<mean<< endl;
    return 0;
}

#include <iostream>
#include "SignalStatistics.h"
#include<cmath>

using namespace std;
extern double InputSignal_f32_1kHz_15kHz[320];

double signal_mean, signal_variance, signal_std;
int main()
{
    SignalStatistics *test_signal = new SignalStatistics(&InputSignal_f32_1kHz_15kHz[0],(sizeof(InputSignal_f32_1kHz_15kHz)/sizeof(InputSignal_f32_1kHz_15kHz[0])));

    signal_mean = test_signal->calc_sign_mean();
    signal_variance = test_signal->calc_sign_variance();
    signal_std = test_signal->calc_sign_std();
    cout<<"\n\nMean = "<<signal_mean<<endl;
    cout<<"\nVariance = "<<signal_variance<<endl;
    cout<<"\nSTD = "<<signal_std<<endl;
    return 0;
}

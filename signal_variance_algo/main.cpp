#include <iostream>
#include<cmath>>
#define SIG_LENGTH 320

using namespace std;
extern double InputSignal_f32_1kHz_15kHz[SIG_LENGTH];
double calc_sign_mean(double *sig_src_arr, int sig_length);
double calc_sign_variance(double *sig_src_arr, double sig_mean, int sig_length);

double signal_mean, signal_variance;
int main()
{
    signal_mean = calc_sign_mean(&InputSignal_f32_1kHz_15kHz[0],SIG_LENGTH);
    signal_variance = calc_sign_variance(&InputSignal_f32_1kHz_15kHz[0],signal_mean,SIG_LENGTH);
    cout<<"\n\nMean = "<<signal_mean<<endl;
    cout<<"\nVariance = "<<signal_variance<<endl;
    return 0;
}

double calc_sign_mean(double *sig_src_arr, int sig_length){
    double _mean=0.0;
    for(int i=0; i<sig_length;i++){
        _mean+=sig_src_arr[i];
    }
    _mean=_mean/sig_length;
    return _mean;
}

double calc_sign_variance(double *sig_src_arr, double sig_mean, int sig_length){
    double _variance=0.0;
    for (int i=0;i<sig_length;i++){
        _variance += pow((sig_src_arr[i]-sig_mean),2);
    }
    _variance = _variance/(sig_length-1);
    return _variance;
}

#include "SignalStatistics.h"
#include<cmath>

SignalStatistics::SignalStatistics(double* _sig_src_arr, int _sig_length){
    sig_src_arr = _sig_src_arr;
    sig_length = _sig_length;
}

double SignalStatistics::calc_sign_mean(){
    double _mean=0.0;
    for(int i=0; i<sig_length; i++){
        _mean += sig_src_arr[i];
    }
    _mean = _mean/(double)sig_length;
    return _mean;
}

double SignalStatistics::calc_sign_variance(){
    double sig_mean = calc_sign_mean();
    double _variance;
    for(int i=0; i<sig_length; i++){
        _variance += pow((sig_src_arr[i]-sig_mean),2);
    }
    _variance=_variance/(sig_length-1);
    return _variance;
}

double SignalStatistics::calc_sign_std(){
    double sig_variance = calc_sign_variance();
    double _std = sqrt(sig_variance);
    return _std;
}

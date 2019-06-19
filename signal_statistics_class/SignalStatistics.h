#ifndef SIGNALSTATISTICS_H
#define SIGNALSTATISTICS_H

class SignalStatistics{
private:
    double *sig_src_arr;
    int sig_length;
public:
    SignalStatistics(double *_sig_src_arr, int _sig_length);
    double calc_sign_mean();
    double calc_sign_variance();
    double calc_sign_std();
};
#endif // SIGNALSTATISTICS_H

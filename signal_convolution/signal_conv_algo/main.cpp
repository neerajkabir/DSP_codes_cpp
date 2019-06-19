#include <iostream>
#include<fstream>
#define SIG_LENGTH 320
#define IMP_LENGTH 29
using namespace std;
extern double InputSignal_f32_1kHz_15kHz[SIG_LENGTH];
extern double  Impulse_response[IMP_LENGTH];
double output_signal[SIG_LENGTH+IMP_LENGTH];
//void convolution(double *sig_src_arr, double *sig_dest_arr, double *imp_resp_arr, int sig_src_lengt, int imp_resp_length);

void convolution(double *sig_src_arr,double *sig_dest_arr,double *imp_resp_arr,int  sig_src_length,int  imp_resp_length);
int main()
{
    ofstream file1, file2;
    convolution(
                (double *)InputSignal_f32_1kHz_15kHz,
                (double *)output_signal,
                (double *)Impulse_response,
                (int) SIG_LENGTH,
                (int) IMP_LENGTH
                );
    file1.open("input_signal.dat");
    file2.open("output_signal.dat");
    for(int i=0;i<(SIG_LENGTH+IMP_LENGTH);i++){
        if (i<SIG_LENGTH){
            file1<<InputSignal_f32_1kHz_15kHz[i]<<endl;
        }

        file2<<output_signal[i]<<endl;
    }
    file1.close();
    file2.close();
    return 0;
}

void convolution(
                double *sig_src_arr,
                double *sig_dest_arr,
                double *imp_resp_arr,
                int sig_src_length,
                int imp_resp_length
                )
{
    int i,j;
    for(i=0;i<(sig_src_length+imp_resp_length);i++){
        sig_dest_arr[i]=0;
    }
    for(i=0;i<sig_src_length;i++){
        for(j=0;j<imp_resp_length;j++){
            sig_dest_arr[i+j] += sig_src_arr[i]*imp_resp_arr[j];
        }
    }

}

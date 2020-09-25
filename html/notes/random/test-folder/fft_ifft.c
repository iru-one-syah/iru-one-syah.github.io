#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846264338327950288 

typedef struct{float Re; float Im;} Complex;

void FFT(Complex *v, int N, Complex *temp){
    if (N==1) return;
    
    Complex *ve=temp, *vo=temp+N/2;
    for (int k=0; k<N/2; k++){
        ve[k] = v[2*k];
        vo[k] = v[2*k+1];
    }
    FFT(ve,N/2,v);
    FFT(vo,N/2,v);
    
    Complex w;
    for (int m=0; m<N/2; m++){
        w.Re =  cos(2*PI*m/(double)N);
        w.Im = -sin(2*PI*m/(double)N);
        v[  m  ].Re = ve[m].Re + (w.Re*vo[m].Re - w.Im*vo[m].Im);
        v[  m  ].Im = ve[m].Im + (w.Re*vo[m].Im + w.Im*vo[m].Re);
        v[m+N/2].Re = ve[m].Re - (w.Re*vo[m].Re - w.Im*vo[m].Im);
        v[m+N/2].Im = ve[m].Im - (w.Re*vo[m].Im + w.Im*vo[m].Re);
    }
    return;
}

void IFFTsub(Complex *v, int N, Complex *temp){
    if (N==1) return;
    
    Complex *ve=temp, *vo=temp+N/2;
    for (int k=0; k<N/2; k++){
        ve[k] = v[2*k];
        vo[k] = v[2*k+1];
    }
    IFFTsub(ve,N/2,v);
    IFFTsub(vo,N/2,v);
    
    Complex w;
    for (int m=0; m<N/2; m++){
        w.Re = cos(2*PI*m/(double)N);
        w.Im = sin(2*PI*m/(double)N);
        v[  m  ].Re = ve[m].Re + (w.Re*vo[m].Re - w.Im*vo[m].Im);
        v[  m  ].Im = ve[m].Im + (w.Re*vo[m].Im + w.Im*vo[m].Re);
        v[m+N/2].Re = ve[m].Re - (w.Re*vo[m].Re - w.Im*vo[m].Im);
        v[m+N/2].Im = ve[m].Im - (w.Re*vo[m].Im + w.Im*vo[m].Re);
    }
    return;
}

void IFFT(Complex *v, int N, Complex *temp){
    IFFTsub(v,N,temp);
    for (int k=0;k<N;k++){
        v[k].Re /= N;
        v[k].Im /= N;
    }
    return;
}

int main()
{
	int nfft = pow(2,3);
	
    Complex v[nfft], temp[nfft];
    for (int k=0; k<nfft; k++){
        v[k].Re = k;
        v[k].Im = 0;
    }
    
    printf("Original v[n]:\n");
    for (int k=0; k<nfft; k++){
        printf("%.4f\n",v[k].Re);
    }
    
    printf("\nFFT of v[n]:\n");
    FFT(v,nfft,temp);
    for (int k=0; k<nfft; k++){
        if (v[k].Im>=0.0) printf("%.4f +  %.4fi\n",v[k].Re,v[k].Im);
        else printf("%.4f -  %.4fi\n",v[k].Re,-v[k].Im);
    }
    
    printf("\nIFFT of V[k]:\n");
    IFFT(v,nfft,temp);
    for (int k=0; k<nfft; k++){
        printf("%.4f\n",v[k].Re);
    }
} 

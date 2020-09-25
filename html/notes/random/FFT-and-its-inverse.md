# Fast Fourier Transform & Its Inverse

<p style="text-align:left;"><a href="../../../notes.html"><b>NOTES</b></a> <span style="float:right;">         August 30, 2018 </span></p>

## Algorithm

Reference - <a href="https://www.sciencedirect.com/book/9780127484518/mathematics-for-multimedia" target=_blank>Mathematics for Multimedia</a>

**Fast Fourier Transform (FFT)**

```
FFT(v,N):
[0] If N==1 then return.
[1] For k = 0 to N/2-1, let ve[k] = v[2*k]
[2] Compute FFT(ve, N/2);
[3] For k = 0 to N/2-1, let vo[k] = v[2*k+1]
[4] Compute FFT(vo, N/2);
[5] For m = 0 to N/2-1, do [6] through [9]
[6]   Let w.re = cos(2*PI*m/N)
[7]   Let w.im = -sin(2*PI*m/N)
[8]   Let v[m] = ve[m] + w*vo[m]
[9]   Let v[m+N/2] = ve[m] - w*vo[m]
```

**Inverse Fast Fourier Transform (IFFT)**

```
IFFTsub(v,N):
[0] If N==1 then return.
[1] For k = 0 to N/2-1, let ve[k] = v[2*k]
[2] Compute IFFTsub(ve, N/2);
[3] For k = 0 to N/2-1, let vo[k] = v[2*k+1]
[4] Compute IFFTsub(vo, N/2);
[5] For m = 0 to N/2-1, do [6] through [9]
[6]   Let w.re = cos(2*PI*m/N)
[7]   Let w.im = sin(2*PI*m/N)
[8]   Let v[m] = ve[m] + w*vo[m]
[9]   Let v[m+N/2] = ve[m] - w*vo[m]

IFFT(v,N):
[0] For k = 0 to N, let v[k] = v[k]/N
```

## C-CODE

File : `fft_ifft.c`

```c
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
```

To compile:

```bash
gcc -o RunThis fft_ifft.c -s -O4 -lm
```

Then run,

```bash
./RunThis
```

Output:

```bash
irwansyah@irwansyah-CF-NX2:~/IRWANSYAH$ ./RunThis 
Original v[n]:
0.0000
1.0000
2.0000
3.0000
4.0000
5.0000
6.0000
7.0000

FFT of v[n]:
28.0000 +  0.0000i
-4.0000 +  9.6569i
-4.0000 +  4.0000i
-4.0000 +  1.6569i
-4.0000 +  0.0000i
-4.0000 -  1.6569i
-4.0000 -  4.0000i
-4.0000 -  9.6569i

IFFT of V[k]:
0.0000
1.0000
2.0000
3.0000
4.0000
5.0000
6.0000
7.0000
```
#ifndef CUDA_CALL_H
#define CUDA_CALL_H
#ifdef __cplusplus
extern "C"
#endif
void cuda_call_mandelbrot(unsigned int* a_h, unsigned int constw, unsigned int consth, float middlex, float middley, float scale, unsigned int max, unsigned int reset);
#endif

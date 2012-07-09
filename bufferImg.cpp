#include "bufferImg.hpp"

bufferImg::bufferImg(void)
{
  elementosMaximos = 2;
  bufferImagenes = new IplImage[elementosMaximos];
  inPtr = outPtr = cuentaNum = 0;
  pthread_mutex_init(&mutedBuff, NULL);
  pthread_cond_init(&bufLleno, NULL);
  pthread_cond_init(&bufVacio, NULL);
} // constructor del buffer


void bufferImg::pushData(IplImage imgData)
{
  pthread_mutex_lock(&mutedBuff);

  while (cuentaNum == elementosMaximos) // si el buffer esta lleno lo ponemos en pausa
    pthread_cond_wait(&bufLleno, &mutedBuff);

  bufferImagenes[inPtr] = imgData;
  inPtr = (inPtr + 1) % elementosMaximos;
  cuentaNum++;

  pthread_cond_signal(&bufVacio);

  pthread_mutex_unlock(&mutedBuff);
} // fin Push datos al buffer

IplImage bufferImg::popData(void)
{
  IplImage data;
  pthread_mutex_lock(&mutedBuff);

  while (cuentaNum == 0) // si esta vacío no se saca más wait
    pthread_cond_wait(&bufVacio, &mutedBuff);

  data = bufferImagenes[outPtr];
  outPtr = (outPtr + 1) % elementosMaximos;
  cuentaNum--;

  pthread_cond_signal(&bufLleno);

  pthread_mutex_unlock(&mutedBuff);

  return data;
} // fin Pop datos al buffer

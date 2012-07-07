class imgBuffer
{
	IplImage  *bufferImg;
	int elementosMaximos, inPtr, outPtr, cuentaNum;
	
	// Mecanismo para bloquear variables que vayan dentro de mutedBuff lock XXX unlock
	// pthread_mutex_lock(&mutedBuff); y pthread_mutex_unlock(&mutedBuff);	
	pthread_mutex_t mutedBuff;
	
	// A condition (short for ‘‘condition variable’’) is a synchronization device that allows threads to suspend execution and relinquish the processors until some predicate on shared data is satisfied. The basic operations on conditions are: signal the condition (when the predicate becomes true), and wait for the condition, suspending the thread execution until another thread signals the condition.
	pthread_cond_t bufLleno, bufVacio;
	
	public:
		imgBuffer(void);
		void pushData(IplImage imgData);
		IplImage popData(void);

}

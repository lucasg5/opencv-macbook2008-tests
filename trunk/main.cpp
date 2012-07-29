#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <pthread.h>
#include "bufferImg.hpp"

bufferImg *b;

int main( int argc, const char* argv[] )
{
	CvCapture *capture = 0;
    	IplImage  *frame = 0;
	int       key = 0;
	cvNamedWindow("2seeWin", CV_WINDOW_AUTOSIZE);

	//capture = cvCaptureFromCAM( 0 );

	if(!capture) {
	printf("\n Cannot open iSight\n");
	//return 1;	
	}

	printf( "\nSoftware for adquiring and process iSight images\n\n" );
	printf( "Testing purposes -- MacBook Late 2008\n"); 	

	while(1)
	{
	capture = cvCaptureFromCAM( 0 );
	frame = cvQueryFrame(capture);	
	cvShowImage("2seeWin", frame );
	if ( (cvWaitKey(10) & 255) == 27 ) break;
	}

	 // wait for a key
 	 //cvWaitKey(0);

  	// release the image
  	//cvReleaseCapture(&capture);
	cvReleaseImage(&frame);
  	return 0;

}

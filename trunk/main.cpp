#include <stdio.h>
#include <opencv2/opencv.hpp>

int main( int argc, const char* argv[] )
{
	CvCapture *capture = 0;
    	IplImage  *frame = 0;
	int       key = 0;
	cvNamedWindow("2seeWin", CV_WINDOW_AUTOSIZE);

	capture = cvCaptureFromCAM( 0 );

	if(!capture) {
	printf("\n Cannot open iSight\n");
	return 1;	
	}

	printf( "\nSoftware for adquiring and process iSight images\n\n" );
	printf( "Testing purposes -- MacBook Late 2008\n"); 	

	frame = cvQueryFrame(capture);	
	cvShowImage("2seeWin", frame );	

	 // wait for a key
 	 cvWaitKey(0);

  	// release the image
  	cvReleaseImage(&frame);
  	return 0;

}

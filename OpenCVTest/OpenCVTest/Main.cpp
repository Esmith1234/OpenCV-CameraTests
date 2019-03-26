#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>  // cv::Canny()
#include <iostream>
#include <vector>
#include <thread>

using namespace cv;
using std::cout; using std::cerr; using std::endl; using std::vector;
using namespace std;
//Assigns cameras to variables

bool pause = false;
VideoCapture capture1(0);
VideoCapture capture2(1);
VideoCapture capture3(2);
VideoCapture capture4(3);
VideoCapture capture5(4);
VideoCapture capture6(5);
Mat blueFrame = imread("Bb_blue.jpg", IMREAD_COLOR);
Mat resize1;
Mat frame1;
Mat frame2;
Mat frame3;
Mat frame4;
Mat frame5;
Mat frame6;
Mat top;
Mat bot;
std::vector<Mat> matArray1;
std::vector<Mat> matArray2;
Mat3b finalFrame;
//Creates the frame to hold the feed
double frameRatio = 0.6;

void stopStream()
{
	pause = true;
}

int camCount() {
	int numCams = 0;
	double frameRatio = 0.6;
	cout << "checking for cams" << endl;

	for (int i = 0; i < 7; ++i) {
		VideoCapture capture0(i);
		if (capture0.isOpened()) {
			numCams++;
		}
	}
	return numCams;
}

void displayCams(int numCams) {
	pause = false;
	
	while (!pause)
	{
		//Mat3b finalFrame;
		switch (numCams) {
		case 0: cout << "no cams detected" << endl;
			exit(0);
			break;
		case 1: {
			capture1 >> frame1;
			resize(frame1, frame1, Size(), frameRatio, frameRatio);
			resize(blueFrame, blueFrame, Size(frame1.cols, frame1.rows), 0, 0);
			frame2 = blueFrame;
			frame3 = blueFrame;
			frame4 = blueFrame;
			frame5 = blueFrame;
			frame6 = blueFrame;
			matArray1 = { frame1, frame2, frame3 };
			matArray2 = { frame4, frame5, frame6 };
			hconcat(matArray1, top);
			hconcat(matArray2, bot);
			vconcat(top, bot, finalFrame);
			imshow("Camera Feed", finalFrame);
			break;
		}
		case 2: {
			capture1 >> frame1;
			capture2 >> frame2;
			resize(frame1, frame1, Size(), frameRatio, frameRatio);
			resize(blueFrame, blueFrame, Size(frame1.cols, frame1.rows), 0, 0);
			resize(frame2, frame2, Size(frame1.cols, frame1.rows), 0, 0);
			frame3 = blueFrame;
			frame4 = blueFrame;
			frame5 = blueFrame;
			frame6 = blueFrame;
			matArray1 = { frame1, frame2, frame3 };
			matArray2 = { frame4, frame5, frame6 };
			hconcat(matArray1, top);
			hconcat(matArray2, bot);
			vconcat(top, bot, finalFrame);
			imshow("Camera Feed", finalFrame);
			break;
		}
		case 3: {
			capture1 >> frame1;
			capture2 >> frame2;
			capture3 >> frame3;
			resize(frame1, frame1, Size(), frameRatio, frameRatio);
			resize(blueFrame, blueFrame, Size(frame1.cols, frame1.rows), 0, 0);
			resize(frame2, frame2, Size(frame1.cols, frame1.rows), 0, 0);
			resize(frame3, frame3, Size(frame1.cols, frame1.rows), 0, 0);
			frame4 = blueFrame;
			frame5 = blueFrame;
			frame6 = blueFrame;
			matArray1 = { frame1, frame2, frame3 };
			matArray2 = { frame4, frame5, frame6 };
			hconcat(matArray1, top);
			hconcat(matArray2, bot);
			vconcat(top, bot, finalFrame);
			imshow("Camera Feed", finalFrame);
			break;
		}
		case 4: {
			capture1 >> frame1;
			capture2 >> frame2;
			capture3 >> frame3;
			capture4 >> frame4;
			resize(frame1, frame1, Size(), frameRatio, frameRatio);
			resize(blueFrame, blueFrame, Size(frame1.cols, frame1.rows), 0, 0);
			resize(frame2, frame2, Size(frame1.cols, frame1.rows), 0, 0);
			resize(frame3, frame3, Size(frame1.cols, frame1.rows), 0, 0);
			resize(frame4, frame4, Size(frame1.cols, frame1.rows), 0, 0);
			frame5 = blueFrame;
			frame6 = blueFrame;
			matArray1 = { frame1, frame2, frame3 };
			matArray2 = { frame4, frame5, frame6 };
			hconcat(matArray1, top);
			hconcat(matArray2, bot);
			vconcat(top, bot, finalFrame);
			
			imshow("Camera Feed", finalFrame);
			break;
		}
		case 5: {
			capture1 >> frame1;
			capture2 >> frame2;
			capture3 >> frame3;
			capture4 >> frame4;
			capture5 >> frame5;
			resize(frame1, frame1, Size(), frameRatio, frameRatio);
			resize(blueFrame, blueFrame, Size(frame1.cols, frame1.rows), 0, 0);
			resize(frame2, frame2, Size(frame1.cols, frame1.rows), 0, 0);
			resize(frame3, frame3, Size(frame1.cols, frame1.rows), 0, 0);
			resize(frame4, frame4, Size(frame1.cols, frame1.rows), 0, 0);
			resize(frame5, frame5, Size(frame1.cols, frame1.rows), 0, 0);
			frame6 = blueFrame;
			matArray1 = { frame1, frame2, frame3 };
			matArray2 = { frame4, frame5, frame6 };
			hconcat(matArray1, top);
			hconcat(matArray2, bot);
			vconcat(top, bot, finalFrame);
			imshow("Camera Feed", finalFrame);
			break;
		}
		case 6: {
			capture1 >> frame1;
			capture2 >> frame2;
			capture3 >> frame3;
			capture4 >> frame4;
			capture5 >> frame5;
			capture6 >> frame6;
			resize(frame1, frame1, Size(), frameRatio, frameRatio);
			resize(frame2, frame2, Size(frame1.cols, frame1.rows), 0, 0);
			resize(frame3, frame3, Size(frame1.cols, frame1.rows), 0, 0);
			resize(frame4, frame4, Size(frame1.cols, frame1.rows), 0, 0);
			resize(frame5, frame5, Size(frame1.cols, frame1.rows), 0, 0);
			resize(frame6, frame6, Size(frame1.cols, frame1.rows), 0, 0);
			matArray1 = { frame1, frame2, frame3 };
			matArray2 = { frame4, frame5, frame6 };
			hconcat(matArray1, top);
			hconcat(matArray2, bot);
			vconcat(top, bot, finalFrame);
			imshow("Camera Feed", finalFrame);
			break;
		}
		}
		char keypress = waitKey(1);
		if (keypress == 27) {//if pressed Esc key breaks from method
			pause = false;
			break;
		}
		if (keypress == 32) {//if Spacebar
			stopStream();
		}
	}

}
//cam0 - cam5 methods for displaying individual camera feeds. This can be used later for camera selection GUI

void singleDisplay(VideoCapture capture, Mat frame) {
	pause = false;
	while (!pause) {
		if (capture.isOpened()) { //avoid reading from an unopened device
			
			capture >> frame;
			imshow("Camera Feed", frame); //Display Frame
		}
		else {
			break; // If no camera, breaks from method
		}
		int keypress = waitKey(1); //saving the pressed key
		if (keypress == 27) {//if pressed Esc key breaks from method
			pause = false;
			break;
		}
		if (keypress == 32) {//if Spacebar
			pause = true;
			break;
		}
	}
}

void zoomCam(VideoCapture capture, Mat frame) {

	double count = 1.0;
	double inc = .2;
	double dec = .1;

	while (true) {
		if (capture.isOpened()) { //avoid reading from an unopened device
			capture.read(frame); //Reads frame
			imshow("Camera Feed", frame); //Display Frame
		}
		else {
			break; // If no camera, breaks from method
		}
		int keypress = waitKey(1); //saving the pressed key
		if (keypress == 0) { // if arrow keys pressed (placeholder for button click)
			count += inc; //counter for incrementing
			while (true) {

				if (capture.isOpened()) {
					capture.isOpened();
				ZoomIn: //zoom in jump placeholder when switching between zooming in and out
					capture.read(frame);
					resize(frame, resize1, Size(frame.cols * count, frame.rows * count)); //resizing of the window
					imshow("Zooming In", resize1);
				}
				else {
					break;
				}
				int keypress = waitKey(1);
				if (keypress == 0) { //for further zooming in 
					count += inc;
					if (count < 1.0 || count > 1.6) { //checks for certain magnification to reset if too large or small
						count = 1.2;
					}
					goto ZoomIn; //send back to zoomin jump placeholder
				}
				if (keypress == 27) { //exits zooming in window
					destroyWindow("Zooming In");
					break;
				}
				if (keypress == 32) { //sends to zooming out function with spacebar (placeholder for button click)
					destroyWindow("Zooming In");
					goto ZoomOut;
				}
			}
		}
		if (keypress == 32) { //if spacebar(32) pressed it zooms out window. Currently placeholder for button click.
			count -= dec; //counter for decrementing 
			while (true) {

				if (capture.isOpened()) {
				ZoomOut:
					capture.isOpened();
					//ZoomOut: //jump area for zooming out from other window/loop
					capture.read(frame);
					resize(frame, resize1, Size(frame.cols * count, frame.rows * count)); //resizing frame for zooming out winbdow
					imshow("Zooming Out", resize1);
				}
				else {
					break;
				}
				int keypress = waitKey(1);
				if (keypress == 32) {//if spacebar continuously selected then will continue to zoom out
					count -= dec; //dec counter
					if (count < .6 || count > 1.0) {////checks for certain magnification to reset if too large or small
						count = 1.0;
					}
					goto ZoomOut;
				}
				if (keypress == 27) { // destroys zooming out window
					destroyWindow("Zooming Out");
					break;
				}
				if (keypress == 0) { //sends to zooming In function with arrow keys (placeholder for button click)
					destroyWindow("Zooming Out");
					goto ZoomIn;
				}
			}
		}
		if (keypress == 27) {//if pressed Esc key breaks from method
			break;
		}

	}
}

int main(int, char**)
{
	int numCams = camCount();
	cout << "Open Cams = " << numCams << endl;
	//Instructions
	cout << "Once opened, press ESC to scroll through cameras" << endl;
	cout << "Press Spacebar to stop and start the stream" << endl;
	//Endlessly scroll through loop using ESC
	
	while (true) {
		displayCams(numCams);
		while (true) {
			char key = waitKey(1);
			switch (key) {
			case 32: {
				if (pause == true)
					displayCams(numCams);
				else
					break;
			}
			}
			if (pause == false) {
				break;
			}
		}
		if (capture1.isOpened()) {
			singleDisplay(capture1, frame1);
			while (true) {
				char key = waitKey(1);
				switch (key) {
				case 32: {
					if (pause == true)
						singleDisplay(capture1, frame1);
					else
						break;
				}
				}
				if (pause == false) {
					break;
				}
			}
		}
		if (capture2.isOpened()) {
			singleDisplay(capture2, frame2);
			while (true) {
				char key = waitKey(1);
				switch (key) {
				case 32: {
					if (pause == true)
						singleDisplay(capture2, frame2);
					else
						break;
				}
				}
				if (pause == false) {
					break;
				}
			}
		}
		zoomCam(capture1, frame1);
		zoomCam(capture2, frame2);

	}
	return 0;
}

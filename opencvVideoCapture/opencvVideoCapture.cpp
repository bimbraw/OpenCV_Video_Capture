// opencvVideoCapture.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;//Namespace where all the C++ OpenCV functionality resides.
using namespace std;//For input output operations.

int main()
{
    VideoCapture cap("C:/Users/Keshav Bimbraw/source/repos/opencvVideoCapture/Shimon_Sitar.mp4");
    //Always put in the full file extension
    //cap is the object of class video capture that tries to capture the video file
    
    //Check if camera opened successfully
    if (!cap.isOpened()) {
        cout << "Error opening video stream or file" << endl;
        return -1;
    }

    while (1) {

        Mat frame;
        //Capture frame-by-frame
        cap >> frame;

        //If the frame is empty, break immediately
        if (frame.empty())
            break;

        //Display the resulting frame
        imshow("Frame", frame);

        //Press ESC on keyboard to exit
        char c = (char)waitKey(25);
        if (c == 27)
            break;
    }

    //When everything done, release the video capture object
    cap.release();

    //Closes all the frames
    destroyAllWindows();

    return 0;
}
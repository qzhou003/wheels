#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <stdio.h>

using namespace cv;
using namespace std;

/** @function main */
// cv::namedWindow( "Hough Circle Transform Demo", CV_WINDOW_AUTOSIZE );
void process_frame(Mat& src){
      /// Convert it to gray
  Mat src_gray;
  cvtColor( src, src_gray, CV_BGR2GRAY );

  /// Reduce the noise so we avoid false circle detection
  GaussianBlur( src_gray, src_gray, Size(19, 19), 2, 2 );
  // imshow("src_gray",src_gray);

  vector<Vec3f> circles;

  /// Apply the Hough Transform to find the circles
  HoughCircles( src_gray, circles, CV_HOUGH_GRADIENT, 1, src_gray.rows/10, 50, 100, 0, 0 );

    /// Draw the circles detected
  for( size_t i = 0; i < circles.size(); i++ )
  {
      Point center(cvRound(circles[i][0]), cvRound(circles[i][1]));
      int radius = cvRound(circles[i][2]);
      // circle center
      circle( src, center, 3, Scalar(0,255,0), -1, 8, 0 );
      // circle outline
      circle( src, center, radius, Scalar(0,0,255), 3, 8, 0 );
   }

     /// Show your results
  imshow( "Hough Circle Transform Demo", src );
  waitKey(5);
}


int main(int argc, char** argv)
{
  Mat src;
  string action(argv[1]);
  if(action == "image"){
      /// Read the image
    src = imread( argv[2], 1 );
    // resize(src,src,cv::Size(640,480));
    if( !src.data )
      { return -1; }
    process_frame(src);
  } else if(action == "video"){
//    string video_src = "/Users/qizhou/Documents/Videos/Client/tacovideo.mov";
      string video_src = "/Users/qizhou/Documents/Videos/Julio/Mexico/2016-09-15 15.53.54.mp4";
    cv::VideoCapture capture =  VideoCapture(video_src);
    while(true){
      if(!capture.read(src)) {cout << " cannot read frame";break;}
      process_frame(src);
      waitKey(10);
    }
  }
  // cout << "argv[1] = " << argv[1] << endl;

  waitKey(0);
  return 0;
}


/*int main(int argc, char** argv)
{
  Mat src, src_gray;

  /// Read the image
  src = imread( argv[1], 1 );
  // resize(src,src,cv::Size(640,480));

  if( !src.data )
    { return -1; }

  /// Convert it to gray
  cvtColor( src, src_gray, CV_BGR2GRAY );

  /// Reduce the noise so we avoid false circle detection
  GaussianBlur( src_gray, src_gray, Size(9, 9), 2, 2 );
  // imshow("src_gray",src_gray);

  vector<Vec3f> circles;

  /// Apply the Hough Transform to find the circles
  HoughCircles( src_gray, circles, CV_HOUGH_GRADIENT, 1, src_gray.rows/20, 100, 100, 0, 0 );

  /// Draw the circles detected
  for( size_t i = 0; i < circles.size(); i++ )
  {
      Point center(cvRound(circles[i][0]), cvRound(circles[i][1]));
      int radius = cvRound(circles[i][2]);
      // circle center
      circle( src, center, 3, Scalar(0,255,0), -1, 8, 0 );
      // circle outline
      circle( src, center, radius, Scalar(0,0,255), 3, 8, 0 );
   }

  /// Show your results
  namedWindow( "Hough Circle Transform Demo", CV_WINDOW_AUTOSIZE );
  imshow( "Hough Circle Transform Demo", src );

  waitKey(0);
  return 0;
}*/

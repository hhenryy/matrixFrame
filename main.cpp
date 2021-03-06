
#include "./dep/element.hpp"
#include "./dep/functions.hpp"

using namespace std;



int main( int argc, char** argv )
{
    
    string imageName("/home/henry/Documents/github_dev/matrixFrame/images/V3.jpg"); // by default
    cv::Mat image;


    int exit = 0;
    if( argc > 1)
    {
        imageName = argv[1];
    }

    // Defining image objects

    //Loading Image to be Processed
    image = cv::imread(imageName.c_str(), cv::IMREAD_COLOR); // Read the file
    if( image.empty() )                      // Check for invalid input
    {
        cout <<  "Could not open or find the image" << std::endl ;
        return -1;
    }

    int* thresh = new int(255);
    setThreshold(image,thresh,255 );

    cout << *thresh << endl;




    vector<element>* bar = new vector<element>();

    cout << "Entering Memory allocated class type funtion \n";
    cv::Point charSize2 = initMatrixMem(cv::Point(image.rows,image.cols), bar, 10.0);
    cout << "Exciting Memory allocated class type funtion \n";

    cout << "Drawing Initial Frame \n";
    drawFrame(image,bar, 10.0);
    cout << "Finished Initial Frame \n\n";


    cout << "getContours \n";
    vector<vector<cv::Point>> contours = getContours(image, *thresh);
    cout << "Done with getContours \n";

    
    updateFrame(contours, bar, cv::Point(8,8));
    drawFrame(image,bar, 10.0);
    cv::imwrite("./output.jpg", image);


    cout << "To exit press Escape \n";
    while(exit != 27){
        exit = cv::waitKey(0); // Wait for Escape to exit
    }



    return 0;
}


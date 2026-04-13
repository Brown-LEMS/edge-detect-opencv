#include "detect.hpp"

namespace edt {
Mat grayscale(const Mat& img_orig) {
    Mat img_gray;
    cvtColor(img_orig, img_gray, COLOR_BGR2GRAY);
    return img_gray;
}

Mat blur(const Mat& img_orig) {
    Mat img_blur;
    GaussianBlur(img_orig, img_blur, Size(3, 3), 0);
    return img_blur;
}

Mat sobel(const Mat& img_orig, SobelDir dir) {
    uint8_t dx = 0;
    uint8_t dy = 0;
    switch (dir) {
    case SobelDir::dx:
        dx = 1;
        break;
    case SobelDir::dy:
        dy = 1;
        break;
    case SobelDir::dxdy:
        dx = 1;
        dy = 1;
        break;
    }
    Mat sobel;
    Sobel(img_orig, sobel, CV_64F, dx, dy, 5);
    return sobel;
}

Mat canny(const Mat& img_orig) {
    Mat edges;
    Canny(img_orig, edges, 100, 200, 3, false);
    return edges;
}

void display_and_wait_on_window(const std::string& win_name, const Mat& img) {
    imshow(win_name, img);
    waitKey(0);
}

void demo(const char* img_path) {
    using namespace cv;
    using namespace edt;
    // reading image
    Mat img = imread(img_path);

    constexpr auto win_name = "edges detect demo";

    cv::namedWindow(win_name, cv::WINDOW_NORMAL);

    cv::resizeWindow(win_name, 800, 600);

    // display original image
    display_and_wait_on_window(win_name, img);

    // convert to graycsale
    Mat img_gray = grayscale(img);

    // blur the image for better edge detection
    Mat img_blur = blur(img_gray);

    // sobel edge detection
    Mat sobel_x = sobel(img_blur, SobelDir::dx);
    Mat sobel_y = sobel(img_blur, SobelDir::dy);
    Mat sobel_xy = sobel(img_blur, SobelDir::dxdy);

    // display sobel edge detection images
    imshow(win_name, sobel_x);
    waitKey(0);
    imshow(win_name, sobel_y);
    waitKey(0);
    imshow(win_name, sobel_xy);
    waitKey(0);

    // canny edge detection
    Mat edges = canny(img_blur);
    // display canny edge detected image
    imshow(win_name, edges);
    waitKey(0);

    destroyAllWindows();
}

} // namespace edt

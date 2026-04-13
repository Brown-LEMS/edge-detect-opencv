#include <detect.hpp>
#include <opencv2/opencv.hpp>

int main(int argc, char** argv) {
    constexpr auto DEFAULT_IMG = "images/fish.jpg";
    const char* image = DEFAULT_IMG;

    if (argc > 1) {
        image = argv[1];
    }

    edt::demo(image);
    return 0;
}

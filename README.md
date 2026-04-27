### Edge Detector with OpenCV

Build
_____
1. Install or build [OpenCV4](https://github.com/opencv/opencv) with [OpenCV4 Contribution](https://github.com/opencv/opencv_contrib) (build directions are in the latter)
    - Before building, make sure (using a package manager or some other method) that `libgtk2.0-dev` is installed on Debian/Ubuntu or `gtk2-devel` on Fedora. `pkg-config` must also be installed.
2. Build this repo:
```bash
git clone https://github.com/Brown-LEMS/edge-detect-opencv.git
cd edge-detect-opencv
cmake -S . -B build -DCMAKE_PREFIX_PATH="/path/to/opencv/build"
cmake --build build -j$(nproc)
```
3. This executable currently runs a demo of 3 variations of Sobel edges (dx, dy, dxdy) and Canny edges. Usage:
```bash
./build/edt <path/to/image>
# or, no argument and just use the default image:
./build/edt
```

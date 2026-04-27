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
3. Download the Structured Forest Edge model from [here](https://github.com/opencv/opencv_extra/blob/master/testdata/cv/ximgproc/model.yml.gz)
4. This executable runs a demo either outputting edges to a file or displaying them on a window. Usage (argument order must match):
```bash
# to output edges to a file:
./build/edt -m <model_name> -i <input_img> -o <output_name>

# show on window
./build/edt -m <model_name> -i <input_img> -s
```

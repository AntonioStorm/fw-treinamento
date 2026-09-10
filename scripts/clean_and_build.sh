rm -rf build
rm -rf dist

mkdir build
mkdir dist

cd build

cmake -DPICOTOOL_FORCE_FETCH_FROM_GIT=1 ..

make -j"$(nproc)"
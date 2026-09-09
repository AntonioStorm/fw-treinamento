rm -rf build
rm -rf dist

mkdir build
mkdir dist

cd build

cmake ..

make -j"$(nproc)"
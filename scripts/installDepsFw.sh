sudo dnf update -y

# Install depencencies for raspiberry
sudo dnf install arm-none-eabi-gcc-cs arm-none-eabi-newlib \
arm-none-eabi-gcc-cs-c++ arm-none-eabi-binutils-cs

# Install general depencencies 
sudo dnf install -y git cmake gcc-c++ qt5-qtbase-devel \
qt5-qtquickcontrols2-devel gdb valgrind omniORB-devel \
omniORB-servers patch freeglut-devel npm plasma-workspace-x11 \
libpng12 libpng-devel SDL2* qt qt-creator qt-devel \
qt5-qtserialport* qt5-qtconnectivity* qt5-qtmultimedia \
eigen3-devel protobuf-devel libdc1394* libjpeg-turbo \
gtkmm24-devel omniORB* redhat-rpm-config opencv-devel \
golang nodejs grpc-devel ranger lazygit vim neovim \
htop btop


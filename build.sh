# pip3 install pyside6 pyopengl
# wget -O - https://apt.kitware.com/keys/kitware-archive-latest.asc 2>/dev/null | gpg --dearmor - | sudo tee /usr/share/keyrings/kitware-archive-keyring.gpg >/dev/null
# echo 'deb [signed-by=/usr/share/keyrings/kitware-archive-keyring.gpg] https://apt.kitware.com/ubuntu/ jammy main' | sudo tee /etc/apt/sources.list.d/kitware.list >/dev/null
# sudo apt-get update
# sudo apt install libclang-dev libboost-all-dev libosd-dev cmake libtbb2-dev

cmake -B build -G Ninja -DCMAKE_BUILD_TYPE=Release -DPXR_ENABLE_PYTHON_SUPPORT=FALSE -DPXR_ENABLE_GL_SUPPORT=FALSE -DPXR_ENABLE_METAL_SUPPORT=FALSE -DPXR_ENABLE_VULKAN_SUPPORT=FALSE -DPXR_ENABLE_OSL_SUPPORT=FALSE -DPXR_BUILD_DOCUMENTATION=FALSE -DPXR_BUILD_USDVIEW=FALSE
cmake --build build --config Release

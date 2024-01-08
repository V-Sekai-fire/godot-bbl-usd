# sudo apt install libclang-dev libboost-all-dev libtbb-dev libosd-dev libtbb12
# pip3 install pyside6
cmake -B build -G Ninja -DCMAKE_BUILD_TYPE=Release -DPXR_ENABLE_PYTHON_SUPPORT=FALSE -DPXR_ENABLE_GL_SUPPORT=FALSE -DPXR_ENABLE_METAL_SUPPORT=FALSE -DPXR_ENABLE_VULKAN_SUPPORT=FALSE -DPXR_ENABLE_OSL_SUPPORT=FALSE -DPXR_BUILD_DOCUMENTATION=FALSE -DPXR_BUILD_USDVIEW=FALSE
cmake --build build --config Release
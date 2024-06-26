# athena

to do list:

change  CBuff vector to ring buff

#windows  编译protobuf

cmake -G "Visual Studio 17 2022"   -Dprotobuf_MSVC_STATIC_RUNTIME=OFF    -Dprotobuf_BUILD_TESTS=OFF   -DCMAKE_INSTALL_PREFIX=D:/temp  ..

cmake --build .  --config Debug --target install

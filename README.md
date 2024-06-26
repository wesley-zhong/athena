# athena

to do list:

change  CBuff vector to ring buff

# windows 
## 编译protobuf

cmake -G "Visual Studio 17 2022"   -Dprotobuf_MSVC_STATIC_RUNTIME=OFF    -Dprotobuf_BUILD_TESTS=OFF   -DCMAKE_INSTALL_PREFIX=D:/temp  ..

cmake --build .  --config Debug --target install

 ## 运行
   项目->属性->配置属性->调试->环境    path=$(ProjectDir)..\..\libs



echo " ===============  start to build libuv============="
cd ./libuv
mkdir -p build
cd ./build
cmake ..
make
cp libuv.a ../../../libs
cd ../
cp -r ./include ../../3rd/libuv

echo "======================build libuv end========="

ehco "================== start to build sol2=========="

cd ../sol2
mkdir -p build
cd ./build
cmake ..
make
cd ..
cp -r ./include ../../3rd/sol2

echo "============ build sol2 end ================"

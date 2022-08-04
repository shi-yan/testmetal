# testmetal

Strange bug

if build using cmake/cmake

```bash
mkdir build
cd build
cmake ..
make
```

the resulting code can't render, because the MyMTKViewDelegate::drawInMTKView function never gets called.

if build using cmake/xcode

```bash
mkdir build
cd build
cmake .. -G Xcode
# open the xcode project and run
```

the resulting code can render fine. However, if the binary is launched from the terminal, it won't render either. 

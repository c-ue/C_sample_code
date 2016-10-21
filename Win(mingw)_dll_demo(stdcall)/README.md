DLL 編譯:
>gcc print.c -shared -o print.dll
EXE 編譯:
>gcc test_demo.c -lkernel32 -o test_demo.exe

GCC 資訊
>gcc -v
Using built-in specs.
COLLECT_GCC=gcc
COLLECT_LTO_WRAPPER=c:/mingw/bin/../libexec/gcc/mingw32/4.9.3/lto-wrapper.exe
Target: mingw32
Configured with: ../src/gcc-4.9.3/configure --build=x86_64-pc-linux-gnu --host=mingw32 --prefix=/mingw --disable-win32-registry --target=mingw32 --with-arch=i586 --enable-languages=c,c++,objc,obj-c++,fortran,ada --enable-static --enable-shared --enable-threads --with-dwarf2 --disable-sjlj-exceptions --enable-version-specific-runtime-libs --enable-libstdcxx-debug --with-tune=generic --enable-nls
Thread model: win32
gcc version 4.9.3 (GCC)
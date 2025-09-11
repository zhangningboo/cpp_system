- .h/.hpp文件不会被编译
- .cpp 源文件会被编译
- .obj/.out 汇编代码编译为机器指令
- .exe 执行文件

### 代码到程序的过程
- 预处理 > 编译 > 汇编 > 链接 > 执行
- 预处理: 复制#include文件内容到.cpp；输出.cpp文件
    ```shell
    $ g++ -E helloworld.cpp -o helloworld.i
    # -E                      Only run the preprocessor
    ```
- 编译: 把.cpp文件转化为目标机器系统的汇编代码；每个.cpp文件单独编译；输出.s文件
    ```shell
    $ g++ -S helloworld.i -o helloworld.s
    # -S                      Only run preprocess and compilation steps
    ```
- 汇编: 汇编代码编译为机器指令；输出.obj文件
    ```shell
    $ g++ -c helloworld.s -o helloworld.o
    # -c                      Only run preprocess, compile, and assemble steps
    ```
- 链接: 将多个.obj文件合并，并设置程序入口；输出可执行文件
    ```shell
    $ g++ helloworld.o -o helloworld
    # -c                      Only run preprocess, compile, and assemble steps
    ```
- 执行: 运行程序
    ```shell
    $ ./helloworld
    ```
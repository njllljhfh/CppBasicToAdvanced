#include "006_head1.h"
//复现多个cpp文件导入同一个头文件，如果头文件中定义了普通函数的实现，那么该函数被多个cpp导入，相当于该函数被定义了多次。编译器报错。

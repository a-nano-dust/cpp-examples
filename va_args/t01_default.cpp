/**
 * @brief 省略符形参实现可变参数
 * 在参数列表中，可以使用省略符 ... 接收任意数量的参数。要求这些参数必须是c语言支持的类型。
 * 省略符所表示的可变参数数量是不可知的，在实际使用中，往往使用一个额外的参数记录调用者传递的可变参数数量。
 * 在函数内部，可以用 va_list 类型所表示的指针指向可变参数，并且存在一些宏可以操作该指针，这些宏都被包含在头文件 <cstdarg> 中。
 * va_start 宏用于初始化指针，它接收两个参数，第一个是指针本身，第二个是可变参数的数量。
 * va_arg 宏用于移动指针，它接收两个参数，第一个是指针本身，第二个是当前参数的类型。
 * va_end 宏用于析构指针，它只接收一个参数，那就是指针本身。
 */

#include <iostream>
#include <cstdarg>

/**
 * @brief 计算给定可变参数之和
 * @param count 可变参数的数量
 * @param ... 可变参数，要求是整型
 * @return 可变参数之和
 */
int sum(int count, ...) {
    
    if (count <= 0) {
        return 0;
    }
    
    // 构造一个可变参数指针
    va_list arg_ptr;
    // 令上述指针指向可变参数起始参数的位置
    va_start(arg_ptr, count);
    
    int value = 0;
    for (int i = 0; i < count; ++i) {
        // 移动指针
        value += va_arg(arg_ptr, int);
    }
    
    // 将指针置空
    va_end(arg_ptr);
    
    return value;
}

int main(int argc, char** argv) {

    std::cout << sum(2, 1, 2) << std::endl;
    std::cout << sum(3, 1, 2, 3) << std::endl;
    std::cout << sum(4, 1, 2, 3, 4) << std::endl;

    return 0;
}


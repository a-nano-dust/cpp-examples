
/**
 * @brief 使用 std::initializer_list 接收可变参数
 * 使用 std::initializer_list 作为形参可以接收任意数量的参数，并且在函数内部可以直接像操作容器一样遍历参数。
 * 这种方式的局限性很大，它要求传递进来的参数必须是同一种类型。其次，在调用时，所有参数需要被包裹在同一对花括号中，
 * 这就相当于是调用者先构造好了一个 std::initializer_list 对象，然后再传递到函数中。从这个角度来讲，这种方式算不上真正地接收了可变参数。
 */


#include <iostream>

int sum(std::initializer_list<int> items) {
    int value = 0;
    for (const auto &item : items) {
        value += item;
    }
    return value;
}

int main(int argc, char** argv) {
    
    std::cout << sum({1, 2}) << std::endl;
    std::cout << sum({1, 2, 3}) << std::endl;
    std::cout << sum({1, 2, 3, 4}) << std::endl;

    return 0;
}


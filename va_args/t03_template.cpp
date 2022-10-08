//
// Created by 14762 on 2022/10/6.
//

/**
 * @brief 可变参数模板
 * 在模板参数前使用省略号 ... ，这个模板参数被称为模板参数包，表示零个或多个模板参数
 * 在形参列表中，模板参数包类型的形参前也需要使用省略号，这个形参被称为函数参数包，表示零个或多个函数参数
 * 使用可变参数模板需要以递归的形式逐个解析参数包中的参数，每一层递归解析一个参数，并将剩余的参数以参数包的形式继续往下传递
 * 最后一级递归只接收一个参数，不接收函数包，因此需要一个单独的函数重载
 * 为了实现上述的递归效果，需要有两个重载的模板函数，第一个模板函数只有一个形参，实现最后一层递归的功能。
 * 第二个模板函数包含两个形参，第二个形参是函数参数包
 */



#include <iostream>

/**
 * @brief 计算给定可变参数之和，最后一层递归
 * @tparam T 参数类型
 * @param value 参数值
 * @return 直接返回给定的参数值
 */
template<typename T>
T sum(const T& value) {
    return value;
}

/**
 * @brief 计算给定可变参数之和
 * @tparam T 参数类型
 * @tparam Args 模板参数包
 * @param value 第一个参数的值
 * @param rest 函数参数包，其余参数的值
 * @return 参数之和
 */
template<typename T, typename... Args>
T sum(const T& value, const Args&... rest) {
    // 解析一个参数，并将其余的参数传递给下一层递归
    return value + sum(rest...);
}

int main(int argc, char** argv) {
    
    std::cout << sum(1, 2) << std::endl;
    std::cout << sum(1, 2, 3) << std::endl;
    std::cout << sum(1, 2, 3, 4) << std::endl;

    return 0;
}



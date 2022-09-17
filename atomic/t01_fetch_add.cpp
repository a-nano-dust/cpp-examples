//
// Created by 14762 on 2022/9/17.
//

/**
 * @brief 测试原子类的自增操作
 */

#include <iostream>
#include <thread>
#include <atomic>


int g_counter = 0;
std::atomic_uint32_t g_atomicCounter(0);

void increment() {
    for (int i = 0; i < 100000; ++i) {
        g_counter++;
    }
}

void atomicIncrement() {
    for (int i = 0; i < 100000; ++i) {
        // 原子对象中的这两个方法作用相同，都能保证线程安全
        // g_atomicCounter.fetch_add(1);
        g_atomicCounter++;
    }
}


int main(int argc, char** argv) {
    
    std::thread t01(increment);
    std::thread t02(increment);
    std::thread t03(increment);
    std::thread t04(increment);
    
    t01.join();
    t02.join();
    t03.join();
    t04.join();
    
    // 不使用原子对象，期望结果为400000，实际并不是
    std::cout << "expected result: 400000, actual result: " << g_counter << std::endl;
    
    std::thread t05(atomicIncrement);
    std::thread t06(atomicIncrement);
    std::thread t07(atomicIncrement);
    std::thread t08(atomicIncrement);
    
    t05.join();
    t06.join();
    t07.join();
    t08.join();
    
    // 使用原子对象，期望结果为400000，实际结果与预期相符
    std::cout << "expected result: 400000, actual result: " << g_atomicCounter.load() << std::endl;
    
    return 0;
}

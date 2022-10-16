

#ifndef INTEGERS_H
#define INTEGERS_H


#include <iterator> // for std::forward_iterator_tag
#include <cstddef>  // for std::ptrdiff_t


/**
 * @brief 简单的自定义容器，内部主要实现了迭代器得逻辑
 */
class Integers {

public:
    /**
     * @brief 容器的迭代器通常定义为内部类
     */
    struct Iterator {
        
        // 类型别名
        using iterator_category = std::forward_iterator_tag;
        using difference_type = std::ptrdiff_t;
        using value_type = int;
        using pointer = int*;
        using reference = int&;
        
        // 构造函数
        Iterator(pointer ptr) : m_ptr(ptr) {
        
        }
        
        // 重载解引用运算符
        reference operator*() const {
            return *m_ptr;
        }
        
        // 重载箭头运算符
        pointer operator->() {
            return m_ptr;
        }
        
        // 重载前缀自加运算符
        Iterator& operator++() {
            m_ptr++;
            return *this;
        }
        
        // 重载后缀自加运算符
        Iterator operator++(int) {
            Iterator tmp = *this;
            ++(*this);
            return tmp;
        }
        
        // 重载相等关系运算符
        friend bool operator==(const Iterator& left, const Iterator& right) {
            return left.m_ptr == right.m_ptr;
        }
        
        // 重载不等关系运算符
        friend bool operator!=(const Iterator& left, const Iterator& right) {
            return left.m_ptr != right.m_ptr;
        }
    
    private:
        pointer m_ptr;
    };

public:
    // 构造一个指向第一个元素的迭代器对象
    Iterator begin() {
        return Iterator(&m_data[0]);
    }
    
    // 构造一个指向最后一个元素的迭代器对象
    Iterator end() {
        return Iterator(&m_data[200]);
    }

private:
    // 容器本质上是一个数组
    int m_data[200];
};


#endif // !INTEGERS_H

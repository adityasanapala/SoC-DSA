#include "stack.h"
#include <iostream>

int main(){
    Stack<int> s;

    s.push(1);
    s.push(2);
    s.push(3);

    std::cout << "Top: " << s.top() << '\n';
    std::cout << "Size: " << s.size() << '\n';
    std::cout << s << '\n';

    s.pop();

    std::cout << s << '\n';

    Stack<int> t = {1, 2, 32};

    std::cout << t <<'\n';
}
//
// Created by zhongweiqi on 2025/10/15.
//

#ifndef ATHENA_FUNCTION_H
#define ATHENA_FUNCTION_H
template <typename F>
void run(F&& fn) {
    std::forward<F>(fn)();
}
#endif //ATHENA_FUNCTION_H
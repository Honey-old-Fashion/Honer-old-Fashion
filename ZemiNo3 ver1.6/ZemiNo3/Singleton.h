#ifndef _SINGLETON_H_
#define _SINGLETON_H_
#pragma once

#include<assert.h>
#include<mutex>


class SingletonFinalizer {
public:
    typedef void(*FinalizerFunc)();

    static void AddFinalizer(FinalizerFunc func);
    static void Finalize();
};

template <typename T>
class singleton final {
public:
    static T& GetInstance() {
        std::call_once(initFlag, Create);
        assert(instance);
        return *instance;
    }

private:
    static void Create() {
        instance = new T;
        SingletonFinalizer::AddFinalizer(&singleton<T>::Destroy);
    }

    static void Destroy() {
        delete instance;
        instance = nullptr;
    }

    static std::once_flag initFlag;
    static T* instance;
};

template <typename T> std::once_flag singleton<T>::initFlag;
template <typename T> T* singleton<T>::instance = nullptr;

#endif // !_SINGLETON_H_                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              
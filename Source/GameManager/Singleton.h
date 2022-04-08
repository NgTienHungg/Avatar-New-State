#pragma once
#include <mutex>
using namespace std;

template <class T>
class Singleton
{
private:
    static T* m_instance;
    static mutex m_locker;

protected:
    Singleton() {}
    ~Singleton() {
        if (m_instance != nullptr) {
            delete m_instance;
            m_instance = nullptr;
        }
    }

public:
    static T* getInstance() {
        m_locker.lock();
        if (m_instance == nullptr) {
            m_instance = new T();
        }
        m_locker.unlock();
        return m_instance;
    }

    static bool hasInstance() {
        return m_instance != 0;
    }
    static void freeInstance() {
        if (m_instance) {
            delete m_instance;
        }
    }
};

template <class T>
T* Singleton<T>::m_instance = nullptr;

template <class T>
mutex Singleton<T>::m_locker;
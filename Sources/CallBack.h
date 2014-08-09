//
//  CallBack.h
//  callback
//
//  Created by 小林　伸 on 2014/07/22.
//  Copyright (c) 2014年 小林　伸. All rights reserved.
//

#ifndef __callback__CallBack__
#define __callback__CallBack__


class callChild{
public:
    virtual void call() = 0;
    virtual ~callChild(){};
};

class NomalPointer: public callChild{
public:
    void (*m_func)();
    NomalPointer( void ( (*func )(void)) ){
        m_func = func;
    }
    void call() override{
        m_func();
    }
};

template <typename T> class MenbaPointer: public callChild{
public:
    void (T::*m_func)(void);
    T* m_instance;
    MenbaPointer(T* instance, void (T::*func)(void) ){
        m_func = func;
        m_instance = instance;
    }
    void call() override{
        (m_instance->*m_func)();
    }
};
                           

class CallBack{
public:
    CallBack& operator=(const CallBack& obj);
    callChild* m_child;
    CallBack ( void (*func)() ){
        m_child = new NomalPointer(func);
    };
    template <typename T> CallBack (T* instance, void (T::*func)(void) ){
        m_child = new MenbaPointer<T>(instance, func);
    };
    void call(){
        m_child->call();
    }
};

#endif /* defined(__callback__CallBack__) */

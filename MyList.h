#ifndef MYLIST_H
#define MYLIST_H

#include <list>
#include <initializer_list>
using namespace std;

template<class T>
class MyList:public list<T>
{
private:
    T result;

public:
    MyList();
    MyList(initializer_list<T> li);
    T operator [](int i);
};


template<class T>
T MyList<T>::operator [](int i){
    auto temp = this->begin();
    for(int num=0;num!=i;++num){
        temp++;
    }
    return *temp;
}

template<class T>
MyList<T>::MyList():list<T>(){

}


template<class T>
MyList<T>::MyList(initializer_list<T> li):list <T>(li) {
}

#endif // MYLIST_H

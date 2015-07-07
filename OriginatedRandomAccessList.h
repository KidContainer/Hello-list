#ifndef ORIGINATEDRANDOMACCESSLIST
#define ORIGINATEDRANDOMACCESSLIST
#include<iostream>
#include<initializer_list>
#include<vector>
using namespace std;
template<typename T>
class OriginatedRandomAccessList{
private:
    struct node{
        T data;
        node* next;
        node* previous;
    };
    node* leftHand=nullptr;
    node* rightHand=nullptr;
    node* head=nullptr;
    node* back=nullptr;

public:
    OriginatedRandomAccessList()=default;
    OriginatedRandomAccessList(std::initializer_list<T> li);
    void append(T elem);//append a node behind the list immediately
    void appendFront(T elem);//append a node in the front of the list
    void insert(T elem,int i);//insert a node at the index of i
    T remove(T elem);//remove the given element
    void removeAll();//remove all the elements
    void printAll();//print all the elements
    T operator[] (int i);//Random-Access function

    inline T getBack(){
        return back->data;
    }

    inline T getHead(){
        return head->data;
    }
};

template<typename T>
OriginatedRandomAccessList<T>::OriginatedRandomAccessList(std::initializer_list<T> li)
{
    vector<T> vec(li.begin(),li.end());
    head = new node();
    leftHand = head;
    rightHand = head;
    head->previous=nullptr;

    for(unsigned int i=0;i!=vec.size();++i){
        leftHand->data=vec[i];
        rightHand = new node();
        leftHand->next=rightHand;
        rightHand->previous=leftHand;
        leftHand=rightHand;
    }

    back = leftHand->previous;
    back->next=nullptr;
    delete leftHand;
    leftHand=rightHand=nullptr;
}

template<typename T>
void OriginatedRandomAccessList<T>::append(T elem){
    if (head==nullptr){
        head = new node();
        back = head;
        head->data = elem;
        head->previous = nullptr;
        head->next = nullptr;
    }
    else{
    rightHand = new node();
    rightHand->previous=back;
    rightHand->data=elem;
    rightHand->next=nullptr;
    back->next=rightHand;
    back=rightHand;
    rightHand=nullptr;
    }
}

template<typename T>
void OriginatedRandomAccessList<T>::appendFront(T elem){
    if(head==nullptr){
        head = new node();
        back = head;
        head->data = elem;
        head->previous = nullptr;
        head->next = nullptr;
    }
    else{
    leftHand = new node();
    leftHand->data=elem;
    leftHand->next=head;
    leftHand->previous=nullptr;
    head->previous=leftHand;
    head=leftHand;
    leftHand=nullptr;
    }
}

template<typename T>
void OriginatedRandomAccessList<T>::insert(T elem, int num){
    if(head==nullptr){
        head = new node();
        back = head;
        head->data = elem;
        head->previous = nullptr;
        head->next = nullptr;
    }
    else{
    leftHand=head;
    for(int i=0;i!=num-1;++i) leftHand=leftHand->next;
    rightHand = new node();
    rightHand->data=elem;
    rightHand->next=leftHand->next;
    rightHand->previous=leftHand;
    leftHand->next->previous=rightHand;
    leftHand->next=rightHand;
    leftHand=rightHand=nullptr;
    }
}

template<typename T>
T OriginatedRandomAccessList<T>::remove(T elem){

        for(auto finder=head;finder!=nullptr;finder=finder->next)
        {
            //if the list is empty
            if(finder==nullptr){
                throw("There is no such element");
            }
            else{
                if(finder->data==elem){
                    if(finder->previous!=nullptr&&finder->next!=nullptr){
                        finder->previous->next=finder->next;
                        finder->next->previous=finder->previous;
                        delete finder;
                        finder=nullptr;
                        break;
                    }
                    //if the elem is the first element
                    if(finder->previous==nullptr&&finder->next!=nullptr){
                        head=finder->next;
                        head->previous=nullptr;
                        delete finder;
                        finder=nullptr;
                        break;
                    }
                    //if the elem is the last element
                    if(finder->next==nullptr&&finder->previous!=nullptr){
                        back=finder->previous;
                        back->next=nullptr;
                        delete finder;
                        finder=nullptr;
                        break;
                    }
                    else{
                        delete finder;
                        break;
                    }
            }
            }
        }
    return elem;
}

template<typename T>
void OriginatedRandomAccessList<T>::removeAll(){
    rightHand=head;
    leftHand=rightHand->next;
    for(;leftHand!=nullptr;leftHand=leftHand->next){
        delete rightHand;
        rightHand=leftHand;
    }
    rightHand=head=leftHand=nullptr;

}

template<typename T>
void OriginatedRandomAccessList<T>::printAll(){
    if(head!=nullptr){
        for(auto printer=head;printer!=nullptr;printer=printer->next){
             cout<<printer->data<<"   ";
        }
        cout<<endl;
    }
    else{
        cout<<"The list has been already empty"<<endl;
    }
}

template<typename T>
T OriginatedRandomAccessList<T>::operator [](int num){
    node* temp_ptr=head;
    for(int i=0;i!=num;++i){
        temp_ptr=temp_ptr->next;
    }
    return temp_ptr->data;
}

#endif // ORIGINATEDRANDOMACCESSLIST


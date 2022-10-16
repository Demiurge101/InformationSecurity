#ifndef CUSTOMFORWARDLIST_H
#define CUSTOMFORWARDLIST_H

template <typename T>
class Node{
public:
    Node(T val) : Value(val), next(nullptr){ }
    ~Node(){ }
    T Value;
    Node* next;
};

template <typename T>
class CustomForwardList{
public:
    CustomForwardList() : first(nullptr), last(nullptr){ }
    ~CustomForwardList(){ }
    Node<T>* first;
    Node<T>* temp;
    Node<T>* last;

    bool is_empty(){ return first == nullptr;}
    int  size();
    void resize(int size, T Value);
    void push_back(T Value);
    void clear_all();
    Node<T>* find(T Value);

    CustomForwardList<T>& operator++ (){
        Node<T>* p = temp;
        temp = p->next;
        return *this;
    }

    Node<T>* operator[] (int index){
        if(index >= this->size() || index < 0)
            return nullptr;
        Node<T>* p = first;
        for(int i = 0; i < index; i++)
            p = p->next;
        return p;
    }

    bool operator== (CustomForwardList<T> right){
        int size = this->size();
        if(size != right.size())
            return false;
        Node<T>* t1 = this->first;
        Node<T>* t2 = right.first;
        if(t1 == nullptr && t2 == nullptr)
            return true;
        else if(t1 == nullptr || t2 == nullptr)
            return false;
        if(t1->Value != t2->Value)
            return false;
        t1 = t1->next; t2 = t2->next;
        for(int i = 1;t1->Value == t2->Value, i < size; t1 = t1->next, t2 = t2->next, i++)
          if(t1->Value != t2->Value)
               return false;
        return true;
    }

    bool operator!= (CustomForwardList<T> right){
        int size = this->size();
        if(size != right.size())
            return true;
        Node<T>* t1 = this->first;
        Node<T>* t2 = right.first;
        if(t1 == nullptr && t2 == nullptr)
            return false;
        else if(t1 == nullptr || t2 == nullptr)
            return true;
        if(t1->Value != t2->Value)
            return true;
        t1 = t1->next; t2 = t2->next;
        for(int i = 1;t1->Value == t2->Value, i < size; t1 = t1->next, t2 = t2->next, i++)
           if(t1->Value != t2->Value)
               return true;
        return false;
    }
};

#endif // CUSTOMFORWARDLIST_H

template<typename T>
int CustomForwardList<T>::size()
{
    Node<T>* t = first;
    int res = 0;
    while(t != last){
        res++;
        t = t->next;
    }
    if(t == last && t != nullptr)
      return ++res;
    return res;
}

template<typename T>
void CustomForwardList<T>::resize(int size, T Value)
{
    size = size - this->size();
    for(int i = 0; i < size; i++)
       push_back(Value);
}

template<typename T>
void CustomForwardList<T>::push_back(T Value)
{
   Node<T>* p = new Node<T>(Value);
     if (is_empty()) {
      first = p;
      last = p;
      p->next = first;
   }
   else {
    last->next = p;
    last = p;
    p->next = first;
    }
    temp = last;
}

template<typename T>
void CustomForwardList<T>::clear_all()
{
    first = nullptr;
    last = nullptr;
    temp = nullptr;
}

template<typename T>
Node<T> *CustomForwardList<T>::find(T Value)
{
    Node<T>* t = first;
    while(t != last){
        if(t->Value == Value)
            return t;
        t = t->next;
    }
    if(t == last)
        return t;
    return nullptr;
}



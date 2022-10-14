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
    ~CustomForwardList(){ clear_all();}
    Node<T>* first;
    Node<T>* temp = first;
    Node<T>* last;

    bool is_empty(){ return first == nullptr;}
    void push_back(T Value);
    void clear_all();
    Node<T>* find(T Value);

    CustomForwardList<T>& operator++ (){
        Node<T>* p = temp;
        temp = p->next;
        return *this;
    }

};

#endif // CUSTOMFORWARDLIST_H

template<typename T>
void CustomForwardList<T>::push_back(T Value)
{
   Node<T>* p = new Node<T>(Value);
     if (is_empty()) {
      first = p;
      last = p;
   }
   else {
    last->next = p;
    last = p;
    p->next = first;
    }
    temp = first;
}

template<typename T>
void CustomForwardList<T>::clear_all()
{
    while (temp) {
        temp = first;
        first = temp->next;
        delete temp;
    }
}

template<typename T>
Node<T> *CustomForwardList<T>::find(T Value)
{
    Node<T>* temp = first;
    while(temp != last){
        if(temp->Value == Value)
            return temp;
        temp = temp->next;
    }
    return nullptr;
}


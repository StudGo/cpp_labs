#ifndef CPP_LABS_LIST_H
#define CPP_LABS_LIST_H


#include <istream>
#include <cassert>


template<typename T>
class list {
public:
    list();
    void append(const T& value);
    void remove(const T& value);
    T* get(size_t index) const;
    T* find(const T& value) const;
    T* first();
    T* last();
    T* curr() const;
    T* next();
    bool is_last() const;

private:
    struct node {
        T value;
        node* next;
    } *curr_, *first_;
};

template<typename T>
bool list<T>::is_last() const {
    return curr_ == nullptr;
}

template<typename T>
T *list<T>::get(size_t index) const {
    auto it = first_;
    for(size_t i = 0; i < index; i++) {
        if(!it) {
            return nullptr;
        }
        it = it->next;
    }
    return &it->value;
}

template<typename T>
list<T>::list()
    : first_(nullptr)
    , curr_(nullptr)
{}

template<typename T>
T* list<T>::first()
{
    curr_ = first_;
    return &first_->value;
}

template<typename T>
T* list<T>::curr() const
{
    return &curr_->value;
}

template<typename T>
T* list<T>::last()
{
    if(!curr_) {
        return nullptr;
    }
    for(; curr_->next; curr_ = curr_->next);
    return curr_;
}

template<typename T>
T* list<T>::next()
{
    assert(curr_);
    curr_ = curr_->next;
    return &curr_->value;
}

template<typename T>
void list<T>::append(const T& value) {
    auto it = first_;
    for(; it && it->next; it = it->next);
    if(it) {
        it->next = new node{value, nullptr};
    } else {
        first_ = new node{value, nullptr};
    }
}


template<typename T>
T* list<T>::find(const T& value) const {
    for(auto it = first_; it; it = it->next) {
        if(it->value == value) {
            return &it->value;
        }
    }
    return nullptr;
}


template<typename T>
void list<T>::remove(const T& value) {
    for(node* it = first_, *prev= nullptr; it; prev = it, it = it->next) {
        if(it->value == value) {
            if(prev) {
                prev->next = it->next;
            } else {
                first_ = it->next;
            }
            if(it == curr_) {
                curr_ = first_;
            }
            delete it;
            return;
        }
    }
}


template<typename T>
std::ostream& operator<<(std::ostream& os, list<T>& list) {
    for(list.first(); !list.is_last(); list.next()) {
        os << *list.curr();
    }
    return os;
}

#endif //CPP_LABS_LIST_H

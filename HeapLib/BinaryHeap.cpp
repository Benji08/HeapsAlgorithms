#include "BinaryHeap.h"

template <typename KeyType, typename ValueType>
Heap<KeyType, ValueType>::Heap(int ary) noexcept{
    this->ary=ary;
}

template <typename KeyType, typename ValueType>
int Heap<KeyType, ValueType>::parent(KeyType index)const noexcept{
    return index/ary;
}

template <typename KeyType, typename ValueType>
int Heap<KeyType, ValueType>::child(KeyType index,  int  number)const noexcept{
    return ary*index + number;
}

template <typename KeyType, typename ValueType>
bool Heap<KeyType, ValueType>::isEmpty() const noexcept {return getSize()==0;}

template <typename KeyType, typename ValueType>
int Heap<KeyType, ValueType>::getMax() const noexcept {return container[0];}

template <typename KeyType, typename ValueType>
size_t Heap<KeyType, ValueType>::getSize() const noexcept{ return container.size();}

template <typename KeyType, typename ValueType>
void  Heap<KeyType, ValueType>::shiftUp(int index) noexcept{
    bool changeable = true;
    while(index!=0 && container[index].key > container[parent(index)].key){
        std::swap(container[index],container[parent(index)]);
        index = parent(index);
    }
}

template <typename KeyType, typename ValueType>
void  Heap<KeyType, ValueType>::shiftDown(int index) noexcept{
    bool ifEnd = false;
    while (!ifEnd) {
        if(ary*index+1 < container.size()) {
            int biggest_child_index = ary * index + 1;
            for (int i = ary * index + 2; i <= ary * index + ary && i < container.size(); i++) {
                if (container[i].key > container[biggest_child_index].key)
                    biggest_child_index = i;
            }
            if (container[biggest_child_index].key > container[index].key) {
                std::swap(container[index], container[biggest_child_index]);
                index = biggest_child_index;
            }
            else
                ifEnd = true;
        }
        else
            ifEnd = true;
    }
}

template <typename KeyType, typename ValueType>
void Heap<KeyType, ValueType>::insertItem(KeyType key, ValueType value) noexcept {
    object tmpObject(key, value);
    container.push_back(tmpObject);
    shiftUp(getSize()-1);
}

template <typename KeyType, typename ValueType>
void Heap<KeyType, ValueType>::extractMax() noexcept {
    std::swap(container[0], container[container.size()-1]);
    container.pop_back();
    shiftDown(0);

}

template <typename KeyType, typename ValueType>
std::string Heap<KeyType, ValueType>::print() const noexcept{
    std::stringstream localString;
    localString<<"[";
    for( auto object: container){
        localString<<"("<<object.key<<","<<object.value<<")";
    }
    localString<<"]"<<std::endl;
    return localString.str();
}



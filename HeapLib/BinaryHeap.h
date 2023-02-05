#ifndef INC_22L_AISD_HEAPS_PAWLAK_ZIAREK_BINARYHEAP_H
#define INC_22L_AISD_HEAPS_PAWLAK_ZIAREK_BINARYHEAP_H
#include <vector>
#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>

template <typename KeyType, typename ValueType>
class Heap{
private:
    class object{
    public:
        KeyType key;
        ValueType value;
        object(KeyType key, ValueType value) {
            this->key = key;
            this->value = value;
        }
    };

private:
    int ary=2;
    std::vector<object> container = {};

    int parent(KeyType index)const noexcept;
    int child(KeyType index, int  number)const noexcept;


public:
    Heap() = default;
    Heap(int ary) noexcept;

    bool isEmpty()const noexcept;
    int getMax() const noexcept;
    void shiftUp(int index) noexcept;
    void shiftDown(int index) noexcept;
    void insertItem(KeyType key, ValueType value) noexcept;
    void extractMax() noexcept;
    size_t getSize() const noexcept;
    std::string print() const noexcept;

    template<typename StreamType>
    void print(StreamType& stream) noexcept{
        stream<<print();
    }


};

template<typename KeyType, typename ValueType>
std::ostream& operator <<(std::ostream& stream, Heap<KeyType, ValueType> &heap)
{
    heap.template print<std::ostream>(stream);
    return stream;
}





#endif //INC_22L_AISD_HEAPS_PAWLAK_ZIAREK_BINARYHEAP_H

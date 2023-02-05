#include <random>
#include <chrono>
#include <thread>
#include <cstdlib>
#include "..\HeapLib\BinaryHeap.h"
#include "..\HeapLib\BinaryHeap.cpp"
#include "..\benchmark\benchmark.h"

class Key
{
private:
    unsigned long value = 0UL;
    static bool performDelay;
    void delay() const
    {
        if (performDelay)
            std::this_thread::sleep_for(std::chrono::milliseconds (1));
    }
public:
    Key() = default;

    Key(Key const&) = default;

    Key(unsigned long v) : value(v){}

    unsigned long getKey() const
    {
        return value;
    }

    static void delayOn()
    {
        performDelay = true;
    }

    static void delayOff()
    {
        performDelay = false;
    }

    bool operator==(Key const& v) const
    {
        delay();
        return value == v.value;
    }

    bool operator!=(Key const& v) const
    {
        delay();
        return value != v.value;
    }

    bool operator<(Key const& v) const
    {
        delay();
        return value < v.value;
    }
    bool operator<=(Key const& v) const
    {
        delay();
        return value <= v.value;
    }
    bool operator>(Key const& v) const
    {
        delay();
        return value > v.value;
    }
    bool operator>=(Key const& v) const
    {
        delay();
        return value >= v.value;
    }

    unsigned long operator*(int const& Value){
        delay();
        auto newValue = this->value* Value;
        return newValue;
    }
    unsigned long operator/(int const& Value){
        delay();
        auto newValue = this->value/Value;
        return newValue;
    }

};

bool Key::performDelay = false;

std::ostream& operator << (std::ostream& stream, Key const& key)
{
    stream << key.getKey();
    return stream;
}

int main()
{
    auto seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::mt19937 generator((unsigned long)seed);

    size_t c_size;

//    Heap<int, int> heap(3);
//   for(int i = 1; i<20; i++)
//       heap.insertItem(i, 0);
//
//    std::cout<<heap<<std::endl;
//    heap.extractMax();
//    std::cout<<heap;
//    std::cout << "Enter size:";
//    std::cin>>c_size;

        std::vector<size_t> sizes = {10, 30, 60, 100, 150, 250, 400, 500, 800, 1000, 2000, 3000, 4000, 5000, 7000, 8000, 10000,
         13000, 16000, 20000};
        unsigned long long sum = 0;
        Key::delayOff();
        for(auto c_size: sizes)
        {
            Key::delayOff();
            Heap<Key, unsigned long>  heap(2);
            while (heap.getSize() <= c_size)
            {
                unsigned long n = generator();
                Key key(n);

                heap.insertItem(key, n);
            }


            Key::delayOn();
            for (int i=0; i<5; i++)
            {
                Benchmark<std::chrono::nanoseconds> b;
                heap.extractMax();
                sum += b.elapsed();
            }


            std::cout <<sum/5<<std::endl;
            sum = 0;
        } ;

}

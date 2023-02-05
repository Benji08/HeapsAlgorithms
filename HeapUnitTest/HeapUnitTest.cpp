#include <../HeapLib/BinaryHeap.h>
#include <../HeapLib/BinaryHeap.cpp>
#include <gtest/gtest.h>


namespace HeapUnitTest
{
    TEST(HeapUnitTest, insert1) {
        std::stringstream stream;
        Heap<unsigned long, unsigned long> heap(2);
        heap.insertItem(5, 0);
        heap.insertItem(7, 0);
        heap.insertItem(9, 0);
        stream << heap;
        ASSERT_EQ(stream.str(), "[(9,0)(7,0)(5,0)]\n");
    }

    TEST(HeapUnitTest, insert2) {
        std::stringstream stream;
        Heap<unsigned long, unsigned long> heap(4);
        heap.insertItem(5, 0);
        heap.insertItem(7, 0);
        heap.insertItem(9, 0);
        stream << heap;
        ASSERT_EQ(stream.str(), "[(9,0)(5,0)(7,0)]\n");
    }

    TEST(HeapUnitTest, insert3) {
        std::stringstream stream;
        Heap<unsigned long, unsigned long> heap(6);
        heap.insertItem(7, 0);
        heap.insertItem(9, 0);
        heap.insertItem(5, 0);
        stream << heap;
        ASSERT_EQ(stream.str(), "[(9,0)(7,0)(5,0)]\n");
    }

    TEST(HeapUnitTest, insert4) {
        std::stringstream stream;
        Heap<unsigned long, unsigned long> heap(4);
        heap.insertItem(9, 0);
        heap.insertItem(7, 0);
        heap.insertItem(5, 0);
        stream << heap;
        ASSERT_EQ(stream.str(), "[(9,0)(7,0)(5,0)]\n");
    }

    TEST(HeapUnitTest, isEmpty1) {
        Heap<unsigned long, unsigned long> heap(2);
        ASSERT_EQ(heap.isEmpty(), true);
    }

    TEST(HeapUnitTest, isEmpty2) {
        Heap<unsigned long, unsigned long> heap(2);
        heap.insertItem(5, 0);
        ASSERT_EQ(heap.isEmpty(), false);
    }
}

TEST(HeapUnitTest, extract1) {
    std::stringstream stream;
    Heap<unsigned long, unsigned long> heap(2);
    heap.insertItem(5, 0);
    heap.insertItem(7, 0);
    heap.insertItem(9, 0);
    heap.insertItem(11, 0);
    heap.extractMax();
    stream << heap;
    ASSERT_EQ(stream.str(), "[(9,0)(7,0)(5,0)]\n");
}

TEST(HeapUnitTest, extract2) {
    std::stringstream stream;
    Heap<unsigned long, unsigned long> heap(4);
    heap.insertItem(5, 0);
    heap.insertItem(7, 0);
    heap.insertItem(9, 0);
    heap.insertItem(11, 0);
    heap.extractMax();
    stream << heap;
    ASSERT_EQ(stream.str(), "[(9,0)(5,0)(7,0)]\n");
}

TEST(HeapUnitTest, extract3) {
    std::stringstream stream;
    Heap<unsigned long, unsigned long> heap(2);
    heap.insertItem(5, 0);
    heap.insertItem(7, 0);
    heap.insertItem(9, 0);
    heap.insertItem(11, 0);
    heap.insertItem(1, 0);
    heap.insertItem(2, 0);
    heap.insertItem(3, 0);
    heap.insertItem(4, 0);
    heap.extractMax();
    stream << heap;
    ASSERT_EQ(stream.str(), "[(9,0)(7,0)(5,0)(4,0)(1,0)(2,0)(3,0)]\n");
}

TEST(HeapUnitTest, getSize) {
    std::stringstream stream;
    Heap<unsigned long, unsigned long> heap(2);
    heap.insertItem(5, 0);
    heap.insertItem(7, 0);
    heap.insertItem(9, 0);
    heap.insertItem(11, 0);
    stream << heap;
    ASSERT_EQ(heap.getSize(), 4);
}
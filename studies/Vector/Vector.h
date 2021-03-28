#pragma once

template <typename T>
class Vector {
public:
    Vector() {
        ReAlloc(2);
    }
    void PushBack(const T& value) {
        if (m_Size >= m_Capacity) 
            ReAlloc(m_Capacity * 2);
        m_Data[m_Size++] = value;
    }

    size_t Size() const { return m_Size; }
    size_t Capacity() const { return m_Capacity; }
    bool IsEmpty() const { return m_Size == 0; }
    const T& operator[](size_t index) const { return m_Data[index]; }
    T& operator[](size_t index) { return m_Data[index]; }
    void Insert(int index, int x) {
        if (m_Size >= m_Capacity) 
            ReAlloc(m_Capacity * 2);
        for (int i = m_Size; i != index; i--) {
            m_Data[i] = m_Data[i - 1];
        }
        m_Size++;
        m_Data[index] = x;
    }
    void Prepend(int x) { Insert(0, x); }
    void Delete(int index) {
        for (int i = index; i <= m_Size; i++) 
            m_Data[i] = m_Data[i+1];
        m_Size--;
    }

private:
    void ReAlloc(size_t newCapacity) {
        // 1. allocate a new block of memory
        // 2. copy/move old elements into new block
        // 3. delete
        
        T* newBlock = new T[newCapacity];

        if (newCapacity < m_Size)
            m_Size = newCapacity;

        for (size_t i = 0; i < m_Size; i++) 
            newBlock[i] = m_Data[i];

        delete[] m_Data;
        m_Data = newBlock;
        m_Capacity = newCapacity;
    }
private:
    T* m_Data = nullptr;
    size_t m_Size = 0;
    size_t m_Capacity = 0;
};


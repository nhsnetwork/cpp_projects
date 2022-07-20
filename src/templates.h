#pragma once

template<typename T>
void Print(T value) {
    std::cout << value << std::endl;
}

/* Class example with Template
   Custom array class where type of the elements
    of array are decided when class object is declared/instantiated
*/

template<typename T, int N> 
class Temparature_Record {
private:
    T m_Array[N];
public:
    Temparature_Record() {
        // Initialize with invalid temparature
        for (int i = 0; i < N; i++) {
            m_Array[i] = -200;
        }
    }
    int getSize() {
        return N;
    }
};
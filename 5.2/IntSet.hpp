#ifndef INTSET_HPP
#define INTSET_HPP

#include <array>
#include <iostream>
#include <algorithm>

template <typename T,unsigned int N>

class IntSet{
protected:
std::array<T, N> Set;
size_t size = 0;

public:
void add(T n){
    if((size < N) && (!contains(n))){
        Set[size] = n;
        size++;
    }
}

void remove(T n){
        if(contains(n)){
            std::remove(Set.begin(), Set.end(), n);
            size--;
    }
}

bool contains(T n){
    for(size_t i = 0; i < size; i++){
        if(Set[i] == n){
            return true;
        }
    }
    return false;
}


template <typename S,unsigned int M>
friend std::ostream& operator<<(std::ostream & os, const IntSet<S, M> & set);


};
template <typename S,unsigned int M>
std::ostream& operator<<(std::ostream & os, const IntSet<S, M> & set){
    for(S i = 0; i < set.size; i++){
        os << set.Set[i] << '\n';
    }
    return os;
}

#endif 
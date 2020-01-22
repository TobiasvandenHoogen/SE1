#ifndef INTSET_HPP
#define INTSET_HPP

#include <array>
#include <iostream>
#include <algorithm>

class IntSet{
protected:

    std::array<int, 10> Set;
    size_t size = 0;

public:

    //inserts integer if it doesn't already contain in the set
    void add(int n){
        if((size < 10) && (!contains(n))){
            Set[size] = n;
            size++;
        }
    }

    //removes given integer if it contains in the set 
    void remove(int n){
            if(contains(n)){
                std::remove(Set.begin(), Set.end(), n);
                size--;
        }
    }

    //checks if given integer is already in set 
    bool contains(int n){
        for(size_t i = 0; i < size; i++){
            if(Set[i] == n){
                return true;
            }
        }
        return false;
    }

    
    friend std::ostream& operator<<(std::ostream & os, const IntSet & set);


};
    //operator overloading to print the set 
    std::ostream& operator<<(std::ostream & os, const IntSet & set){
        for(size_t i = 0; i < set.size; i++){
            os << set.Set[i] << '\n';
        }
        return os;
    }

#endif 
#include "catch.hpp"
#include "IntSet.hpp"

    //test for add function
    TEST_CASE("IntSet, add function"){
        IntSet i;
        i.add(1);
        REQUIRE(i.contains(1) == true);
    }

    //test for remove function
    TEST_CASE("IntSet, remove function"){
        IntSet i;
        i.add(5);
        i.add(10);
        i.remove(10);
        REQUIRE(i.contains(10) == false);
    }
    
    //test for cout function
    TEST_CASE("IntSet, cout function"){
        IntSet i;
        i.add(7);
        std::cout << "the array contains:\n" << i;
    }
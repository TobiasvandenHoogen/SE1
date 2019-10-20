#include "catch.hpp"
#include "IntSet.hpp"

    //test for type and size in int array with size 5
    TEST_CASE("IntSet int, test type and size"){
        IntSet<char, 3> i;
        i.add('a');
        i.add('B');
        i.add('C');
        REQUIRE(i.MaxElement() == 'a');
    }

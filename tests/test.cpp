// #define CATCH_CONFIG_MAIN  
// #include <catch2/catch_test_macros.hpp>
// #include "../include/GapBuffer.h"
// #include <string>



// TEST_CASE("Simple Insert Case") {
//     GapBuffer gb(5); 
//     gb.insert("Hello", 0); 
//     std::vector<char> vec2 = gb.buffer;
//     REQUIRE(vec1 == vec2);
// }

// TEST_CASE("Two Inserts") {
//     GapBuffer gb(20); 
//     gb.insert("World", 0);
//     gb.insert("Hello", 0);
//     std::vector<char> vec1 = gb.bufferText();
//     std::vector<char> vec2 = {'H', 'e', 'l', 'l', 'o', 'W', 'o', 'r', 'l', 'd'};
//     REQUIRE(vec1 == vec2);
// }

// TEST_CASE("Insert after") {
//     GapBuffer gb(20); 
//     gb.insert("Hello", 0);
//     gb.insert("World", 5);
//     std::vector<char> vec1 = gb.bufferText();
//     std::vector<char> vec2 = {'H', 'e', 'l', 'l', 'o', 'W', 'o', 'r', 'l', 'd'};
//     REQUIRE(vec1 == vec2);
// }



#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <cstdio>
#include <cstring>
#include <iostream>
#include <sstream>

int run_main() {
    char line[35];
    const char* test_input = "Test input\n";
    std::istringstream input_stream(test_input);
    std::cin.rdbuf(input_stream.rdbuf());
    fgets(line, 30, stdin);
    return strlen(line);
}

TEST_CASE("Main function test", "[main]") {
}
TEST_CASE("Read 29 characters", "[main]") {
    const char* test_input = "This is a 29-character string.\n";
    std::istringstream input_stream(test_input);
    std::cin.rdbuf(input_stream.rdbuf());

    char line[35];
    fgets(line, 30, stdin);

    REQUIRE(strlen(line) == 29);
    REQUIRE(strcmp(line, "This is a 29-character string.") == 0);
}
#include <iostream>
#include <map>
#include <string>
#include <chrono>

void benchmark_inside_loop(int iterations) {
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < iterations; ++i) {
        std::map<std::string, std::string> myMap;
        myMap["key"] = "value"; // Simulate some operations
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    std::cout << "Inside Loop: " << duration.count() << " seconds\n";
}

void benchmark_outside_loop(int iterations) {
    std::map<std::string, std::string> myMap;
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < iterations; ++i) {
        myMap.clear();
        myMap["key"] = "value"; // Simulate some operations
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    std::cout << "Outside Loop: " << duration.count() << " seconds\n";
}

int main() {
    int iterations = 1000000; // Number of iterations for the benchmark
    benchmark_inside_loop(iterations);
    benchmark_outside_loop(iterations);
    return 0;
}

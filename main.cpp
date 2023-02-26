#include "cube.hpp"
#include <ios>
#include <iostream>

// Main function to test the RubiksCube class
int main() {
RubiksCube cube;
cube.print_cube();
cube.scramble();
while (!cube.is_solved()) {
std::cout << "Enter the side you want to rotate and the number of rotations in the format(U, 1): \n";
char face;
int num_turns;
std::cin >> face >> num_turns;
cube.rotate(face, num_turns);
cube.print_cube();
}
std::cout << "Congratulations! You solved the cube!***\n";
return 0;
}
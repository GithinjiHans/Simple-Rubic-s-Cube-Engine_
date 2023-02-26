#include "cube.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

RubiksCube::RubiksCube() {
  // Initialize the cube to a solved state
  for (int i = 0; i < 6; i++) {
    for (int j = 0; j < 3; j++) {
      for (int k = 0; k < 3; k++) {
        cube_[i][j][k] = "wgrboy"[i];
      }
    }
  }
}

void RubiksCube::rotate(char face, int num_turns) {
  // Rotate the specified face by the specified number of turns
  rotate_face(face, num_turns);
}

void RubiksCube::scramble() {
  // Generate a random sequence of moves to scramble the cube
  char moves[] = {'U', 'D', 'F', 'B', 'L', 'R'};
  int num_moves = sizeof(moves) / sizeof(moves[0]);
  std::string algorithm = "";
  srand(time(NULL));
  for (int i = 0; i < 20; i++) {
    char move = moves[rand() % num_moves];
    int num_turns = rand() % 3 + 1;
    algorithm += move;
    algorithm += num_turns == 1 ? "" : num_turns == 2 ? "2" : "'";
    algorithm += " ";
    rotate_face(move, num_turns);
  }
  std::cout << "Scramble algorithm: " << algorithm << std::endl;
  print_cube();
}

bool RubiksCube::is_solved() {
  // Check if the cube is solved
  for (int i = 0; i < 6; i++) {
    char color = cube_[i][0][0];
    for (int j = 0; j < 3; j++) {
      for (int k = 0; k < 3; k++) {
        if (cube_[i][j][k] != color) {
          return false;
        }
      }
    }
  }
  return true;
}

 void RubiksCube::rotate_face(char face, int num_turns) {
  // Rotate the specified face by the specified number of turns
  switch (face) {
  case 'U':
    for (int turn = 0; turn < num_turns; turn++) {
      char temp = cube_[0][0][0];
      cube_[0][0][0] = cube_[0][2][0];
      cube_[0][2][0] = cube_[0][2][2];
      cube_[0][2][2] = cube_[0][0][2];
      cube_[0][0][2] = temp;
      temp = cube_[0][0][1];
      cube_[0][0][1] = cube_[0][1][0];
      cube_[0][1][0] = cube_[0][2][1];
      cube_[0][2][1] = cube_[0][1][2];
      cube_[0][1][2] = temp;
      rotate_edges(0);
    }
    break;
  case 'D':
    for (int turn = 0; turn < num_turns; turn++) {
      char temp = cube_[1][0][0];
      cube_[1][0][0] = cube_[1][0][2];
      cube_[1][0][2] = cube_[1][2][2];
      cube_[1][2][2] = cube_[1][2][0];
      cube_[1][2][0] = temp;
      temp = cube_[1][0][1];
      cube_[1][0][1] = cube_[1][1][2];
      cube_[1][1][2] = cube_[1][2][1];
      cube_[1][2][1] = cube_[1][1][0];
      cube_[1][1][0] = temp;
      rotate_edges(1);
    }
    break;
  case 'F':
    for (int turn = 0; turn < num_turns; turn++) {
      char temp = cube_[2][0][0];
      cube_[2][0][0] = cube_[5][0][0];
      cube_[5][0][0] = cube_[3][2][2];
      cube_[3][2][2] = cube_[0][2][0];
      cube_[0][2][0] = temp;
      temp = cube_[2][0][1];
      cube_[2][0][1] = cube_[5][0][1];
      cube_[5][0][1] = cube_[3][1][2];
      cube_[3][1][2] = cube_[0][2][1];
      cube_[0][2][1] = temp;
      temp = cube_[2][0][2];
      cube_[2][0][2] = cube_[5][0][2];
      cube_[5][0][2] = cube_[3][0][2];
      cube_[3][0][2] = cube_[0][2][2];
      cube_[0][2][2] = temp;
      rotate_edges(2);
    }
    break;
  case 'B':
    for (int turn = 0; turn < num_turns; turn++) {
      char temp = cube_[4][0][0];
      cube_[4][0][0] = cube_[0][0][2];
      cube_[0][0][2] = cube_[3][2][0];
      cube_[3][2][0] = cube_[5][2][2];
      cube_[5][2][2] = temp;
      temp = cube_[4][0][1] = cube_[4][0][1];
      cube_[0][1][2] = cube_[5][2][1];
      cube_[5][2][1] = cube_[3][1][0];
      cube_[3][1][0] = cube_[0][1][2];
      cube_[0][1][2] = temp;
      temp = cube_[4][2][2];
      cube_[4][2][2] = cube_[0][0][0];
      cube_[0][0][0] = cube_[3][0][2];
      cube_[3][0][2] = cube_[5][2][0];
      cube_[5][2][0] = temp;
      temp = cube_[4][2][1];
      cube_[4][2][1] = cube_[0][0][1];
      cube_[0][0][1] = cube_[3][1][2];
      cube_[3][1][2] = cube_[5][1][0];
      cube_[5][1][0] = temp;
      temp = cube_[4][2][0];
      cube_[4][2][0] = cube_[0][0][2];
      cube_[0][0][2] = cube_[3][2][2];
      cube_[3][2][2] = cube_[5][0][0];
      cube_[5][0][0] = temp;
      rotate_edges(3);
    }
    break;
  case 'L':
    for (int turn = 0; turn < num_turns; turn++) {
      char temp = cube_[0][0][0];
      cube_[0][0][0] = cube_[5][2][0];
      cube_[5][2][0] = cube_[1][2][2];
      cube_[1][2][2] = cube_[2][0][0];
      cube_[2][0][0] = temp;
      temp = cube_[0][1][0];
      cube_[0][1][0] = cube_[5][1][0];
      cube_[5][1][0] = cube_[1][1][2];
      cube_[1][1][2] = cube_[2][1][0];
      cube_[2][1][0] = temp;
      temp = cube_[0][2][0];
      cube_[0][2][0] = cube_[5][0][0];
      cube_[5][0][0] = cube_[1][0][2];
      cube_[1][0][2] = cube_[2][2][0];
      cube_[2][2][0] = temp;
      rotate_edges(4);
    }
    break;
  case 'R':
    for (int turn = 0; turn < num_turns; turn++) {
      char temp = cube_[0][0][2];
      cube_[0][0][2] = cube_[2][0][2];
      cube_[2][0][2] = cube_[1][2][0];
      cube_[1][2][0] = cube_[5][2][2];
      cube_[5][2][2] = temp;
      temp = cube_[0][1][2];
      cube_[0][1][2] = cube_[2][1][2];
      cube_[2][1][2] = cube_[1][1][0];
      cube_[1][1][0] = cube_[5][1][2];
      cube_[5][1][2] = temp;
      temp = cube_[0][2][2];
      cube_[0][2][2] = cube_[2][2][0];
      cube_[2][2][0] = temp;
      rotate_edges(5);
    }
    break;
  default:
    std::cout << "Invalid input\n";
    break;
  }
}

void RubiksCube::rotate_edges(int face) {
  char temp = cube_[face][0][0];
  cube_[face][0][0] = cube_[face][0][2];
  cube_[face][0][2] = cube_[face][2][2];
  cube_[face][2][2] = cube_[face][2][0];
  cube_[face][2][0] = temp;
  temp = cube_[face][0][1];
  cube_[face][0][1] = cube_[face][1][2];
  cube_[face][1][2] = cube_[face][2][1];
  cube_[face][2][1] = cube_[face][1][0];
  cube_[face][1][0] = temp;
}

// Function to print the current state of the Rubik's Cube
void RubiksCube::print_cube() {
std::cout << " " << cube_[0][0][0] << cube_[0][0][1] << cube_[0][0][2] << std::endl;
std::cout << " " << cube_[0][1][0] << cube_[0][1][1] << cube_[0][1][2] << std::endl;
std::cout << " " << cube_[0][2][0] << cube_[0][2][1] << cube_[0][2][2] << std::endl;
std::cout << cube_[4][0][0] << cube_[4][0][1] << cube_[4][0][2] << " "
<< cube_[1][0][0] << cube_[1][0][1] << cube_[1][0][2] << " "
<< cube_[2][0][0] << cube_[2][0][1] << cube_[2][0][2] << " "
<< cube_[3][0][0] << cube_[3][0][1] << cube_[3][0][2] << std::endl;
std::cout << cube_[4][1][0] << cube_[4][1][1] << cube_[4][1][2] << " "
<< cube_[1][1][0] << cube_[1][1][1] << cube_[1][1][2] << " "
<< cube_[2][1][0] << cube_[2][1][1] << cube_[2][1][2] << " "
<< cube_[3][1][0] << cube_[3][1][1] << cube_[3][1][2] << std::endl;
std::cout << cube_[4][2][0] << cube_[4][2][1] << cube_[4][2][2] << " "
<< cube_[1][2][0] << cube_[1][2][1] << cube_[1][2][2] << " "
<< cube_[2][2][0] << cube_[2][2][1] << cube_[2][2][2] << " "
<< cube_[3][2][0] << cube_[3][2][1] << cube_[3][2][2] << std::endl;
std::cout << " " << cube_[5][0][0] << cube_[5][0][1] << cube_[5][0][2] << std::endl;
std::cout << " " << cube_[5][1][0] << cube_[5][1][1] << cube_[5][1][2] << std::endl;
std::cout << " " << cube_[5][2][0] << cube_[5][2][1] << cube_[5][2][2] << std::endl;
}
#ifndef RUBIKSCUBE_H
#define RUBIKSCUBE_H

class RubiksCube {
public:
    // Constructor
    RubiksCube();
    
    // Methods
    void rotate(char face, int num_turns);
    void scramble();
    bool is_solved();
    void print_cube();
    
private:
    // Private variables
    char cube_[6][3][3];
    
    // Private methods
    void rotate_face(char face, int num_turns);
    void rotate_row(int row, int num_turns);
    void rotate_col(int col, int num_turns);
    void rotate_cube(char axis, int index, int num_turns);
    void rotate_edges(int face);
    void apply_algorithm(char* algorithm);
};

#endif

//implemnt ln

#include <unistd.h> // For link()
#include <iostream> // For std::cout and std::cerr

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " source_file target_file" << std::endl;
        return 1;
    }

    const char* source_file = argv[1];
    const char* target_file = argv[2];

    if (link(source_file, target_file) == 0) {
        std::cout << "Hard link created: " << target_file << " -> " << source_file << std::endl;
        return 0;
    } else {
        perror("Error creating hard link");
        return 2;
    }
}

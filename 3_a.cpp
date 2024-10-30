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

/**
 This program takes two arguments: the source file and the target file, and creates a hard link from target_file to source_file.
g++ your_program.cpp -o create_link

If source.txt exists, this will create a hard link named target.txt that points to source.txt.

./create_link source.txt target.txt

Here’s what each element in argv represents:

argv[0]: The name of the program (e.g., ./create_link if you run ./create_link source.txt target.txt).
argv[1]: The first argument after the program name, which in this case should be the name of the source file (e.g., source.txt).
argv[2]: The second argument after the program name, which here is the name of the target file (e.g., target.txt). 


A hard link is essentially an additional name or alias for an existing file on a filesystem. When you create a hard link to a file,
you’re creating another entry in the filesystem that points directly to the same underlying data (i.e., inode) as the original file
In summary, hard links are useful for saving space, enhancing data resilience, and enabling multiple references to the same file data within a filesystem.


#simplest

#include <unistd.h> // For link()
int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " source_file target_file" << std::endl;
        return 1;
    }

    if (link(argv[1], argv[2]) == 0) {
        std::cout << "Hard link created: " << argv[2] << " -> " << argv[1] << std::endl;
        return 0;
    } else {
        perror("Error creating hard link");
        return 2;
    }
}
**/

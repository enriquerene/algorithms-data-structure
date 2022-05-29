#include "./ordered_vector.cpp"

int main(int argc, char **argv) {
    int list[argc - 1];
    for (int i = 0; i < argc - 1; ++i) {
        list[i] = atoi(argv[i+1]);
    }
    OrderedVector v (argc - 1, list);

    v.print();

    return 0;
};

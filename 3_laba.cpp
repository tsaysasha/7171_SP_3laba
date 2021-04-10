#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main() {
    srand(time(NULL));
    int array_size;
    cin >> array_size;

    int* array = new int[array_size];
    
    for (size_t i = 0; i < array_size; i++) {
        array[i] = rand() % 5 + 1;
        cout << array[i] << " ";
    }
    cout << endl;

    int sum = 0;
    asm(
	".intel_syntax noprefix\n\t"
        "xor rax, rax\n\t"
        "xor rdx, rdx\n\t"
        "iteration:\n\t"
            "mov eax, [rbx]\n\t"
            "imul eax, eax\n\t"
            "add edx, eax\n\t"
            "add rbx, 4\n\t"
            "loop iteration\n\t"
        "mov rax, rdx\n\t"
	: "=a" (sum)
	:"c" (array_size), "b" (array)
	:
    );
    cout << "sum:" << sum << endl;

    return 0;
}

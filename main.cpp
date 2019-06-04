#include <iostream>
#include <cassert>
#include<cstdint>

using namespace std;

char nibble_to_hex(uint8_t i){
    assert(0x0 <= i && i <= 0xf);
    char digits[] = "0123456789abcdef";
    return digits[i];
}

const uint8_t*
as_bytes(const void* data) {
    return reinterpret_cast<const uint8_t*>(data);
}

void
print_in_hex(uint8_t byte) {
    cout << nibble_to_hex(byte >> 4)
         << nibble_to_hex(byte & 0xf);
}

void
print_in_hex(const void* data, size_t size) {
    const uint8_t* bytes = as_bytes(data);
    for (size_t i = 0; i < size; i++) {
        print_in_hex(bytes[i]);

        // Äëÿ óäîáñòâà ÷òåíèÿ: ïðîáåëû ìåæäó áàéòàì, ïî 16 áàéò íà ñòðîêó.
        if ((i + 1) % 16) {
            cout << ' ';
        }
        else {
            cout << '\n';
        }
    }
}

char
bit_digit(uint8_t byte, uint8_t bit) {
    if (byte & (0x1 << bit)) {
        return '1';
    }
    return '0';
}

void
print_in_binary(uint8_t byte) {
    for (uint8_t bit = 8; bit > 0; bit--) {

        cout << bit_digit(byte, bit-1);

    }
}
void
print_in_binary(const void* data, size_t size) {
    const uint8_t* bytes = as_bytes(data);
    for (size_t i = 0; i < size; i++) {
        print_in_binary(bytes[i]);

        // Äëÿ óäîáñòâà ÷òåíèÿ: ïðîáåëû ìåæäó áàéòàìè, ïî 4 áàéòà íà ñòðîêó.
        if ((i + 1) % 4 ) {
            cout << ' ';
        }
        else {
            cout << '\n';
        }
    }
}


int main()
{

        uint32_t u32 = 42;
        cout << "u32 bytes: ";
        print_in_binary(&u32, sizeof(u32));
        cout << '\n';

       return 0;
}

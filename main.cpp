#include <iostream>
#include <cassert>
#include<cstdint>
#include<cstdio>

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


        if ((i + 1) % 4 ) {
            cout << ' ';
        }
        else {
            cout << '\n';
        }
    }
}

void bitcalc()
{
    uint16_t operand1,operand2,result;
    char op; // îïðåàòîð

    cin>> operand1>>op>>operand2;

    switch (op)
    {
    case '&':
        result = operand1 & operand2;
        break;
    case '|':
        result = operand1 | operand2;
        break;
    case '^':
        result = operand1 ^ operand2;
        break;
    }
    print_in_hex(&operand1, sizeof(operand1));
    cout<<op<<" ";
    print_in_hex(&operand2, sizeof(operand2));
    cout<<"= ";
    print_in_hex(&result, sizeof(result));
    cout<<'\n';

    print_in_binary(&operand1, sizeof(operand1));
    cout<<op<<" ";
    print_in_binary(&operand2, sizeof(operand2));
    cout<<"= ";
    print_in_binary(&result, sizeof(result));

}



int main()
{
        bitcalc();

       return 0;
}

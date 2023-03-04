#include <iostream>

using namespace std;

bool isEven(int num) {
    return ((num & 1) == 0);
}


// EX: want to delete bit 2 in number 5
// 00101
//  &
// 11011
//-------
// 00001
int getBitAtIth(int &num, int &position) {
    int mask = (1 << position);
    int res = (num & mask);
    if (res > 0)
        return 1;
    else
        return 0;
}

// EX: Want to delete bit 2 in number 5
// 00101
//  &
// 11011 --> in original -> 00100( after left shift)
//-------
// 00001
void clearBitAtIth(int &num, int &position) {
    int mask = ~(1 << position);
    num = (num & mask);
}

// EX: Set bit 1 to 1
// 00101  -> 5
//   |
// 00010
// 00111 -> -> 7
void setBitAtIth(int &num, int &position) {
    int mask = (1 << position);
    num = (num | mask);
}

// EX: clear last range n in number
// 15 -> 1111 (binary)
// 1111
// 1100 ->(original -1 in binary (11111) after left shift)

void clearLastRange(int &num, int &range) {
    int mask = (-1 << range);
    num = (num & mask);
}

/*
 *      Explain
 * ----------------
 * if we have number 15 as binary representation -> (001111)
 * so,we want to clear bit from 1 to 3 (0 0 1 1 1 1)
 *                                          3 2 1,
 * so we want to make mask like that     1 1 0 0 0 1   to clear this range
 * to make this mask ,will integrate to mask
 *        (1 1 0 0 0 1)
 *             e   s
 *         1 1 0 0 0 0
 *         0 0 0 0 0 1  -> ((2^n) - 1)
 *         make or with them
 *         res = 110001
 *
 * to get first mask,we can do that
 *  ~(0) ---> (1111111) and left shift by end Position + 1
 *  to get second mask,we can do that 2^startPosition this will get like that 0010
 *  if we minus 1 from this number will have 00001
 */
void clearBitsFromRange(int &num, int &start, int &end) {
    int mask1 = ~(0) << (end + 1);
    int mask2 = (1 << start) - 1; // 2^n - 1
    int finalMask = (mask1 | mask2);

    num = (num & finalMask);
}

/*
 * Ex: I want to replace range(i,j) in some number with another binary
 * like that: 1000000
 * change from 1 -> 3 with m => 1001
 * so we want to make a mask ,first clear bits in range i to j
 * and left shift m by i ,finally make or operator
 */
void replaceRange(int &num, int &i, int &j, int &m) {
    clearBitsFromRange(num, i, j);
    m = (m << i);
    num = (num | m);
}

/*
 * we want to check if number is power of two or not
 * so , if ww have this number 16 in binary (10000)
 * if 16 - 1 = 15 in binary (10000)
 * if we do and operator between num ,num-1 and result is 0 ,so the number is power of two
 *     10000
 *     01111
 *     -----
 *     000000
 */
bool isPowerOfTwo(int &num) {
    return ((num & (num - 1)) == 0);
}

/*
 * we want count number of set bits
 * consider we have this number 1001101
 * each operation will dp and operator with one to check last bit
 * then right shift by one to get next bit
 * 1st  1001101
 *      0000001
 *      -------
 *      0000001
 *
 * 2st  0100110
 *      0000001
 *      -------
 *      0000000
 *
 * 3st  0010011
 *      0000001
 *      -------
 *      0000001
 */
int countNumberOfBits(int num) {
    int sum = 0;
    while (num != 0) {
        sum += (num & 1);
        num = (num >> 1);
    }
    return sum;
}

int main() {

    int num;
    cout << "Enter number to check odd or even: ";
    cin >> num;
    cout << (isEven(num) ? "even\n" : "odd\n");

    /*
     *  check function get bit at ith position
     */

    cout << "Enter number: ";
    cin >> num;

    int pos;
    cout << "Enter position to get bit at it:";
    cin >> pos;

    cout << "bit at position " << pos << " = " << getBitAtIth(num, pos) << endl;

    /*
     * check function clear bit ar ith position
     */

    cout << "Enter number: ";
    cin >> num;

    cout << "Enter position to clear bit :";
    cin >> pos;

    clearBitAtIth(num, pos);

    cout << "number after delete bit at position " << pos << " is " << num << endl;

    /*
     * check function set bit to 1 at ith position
     */

    cout << "Enter number: ";
    cin >> num;

    cout << "Enter position to set bit to 1:";
    cin >> pos;

    setBitAtIth(num, pos);

    cout << "Number after set bit at position " << pos << " = " << num << endl;

    /*
     * clear last numbers of bits in number
     */
    cout << "Enter number: ";
    cin >> num;

    cout << "Enter number of bits to delete:";
    cin >> pos;

    clearLastRange(num, pos);

    cout << "Number after clear last " << pos << " bits = " << num << endl;

    /*
     * check clear range in number 31 11111 (1->3) res= 17
     */
    cout << "Enter number: ";
    cin >> num;

    int start, end;
    cout << "Enter number start then end ";
    cin >> start >> end;

    clearBitsFromRange(num, start, end);

    cout << "Number after clear range " << num << endl;


    /*
     * check about function replace
     */

    cout << "Enter number: ";
    cin >> num;


    cout << "Enter number start then end ";
    cin >> start >> end;

    int m;
    cout << "Enter number will be replace it:  ";
    cin >> m;

    replaceRange(num, start, end, m);

    cout << "Number after replace range " << num << endl;

    /*
     * check function is power of two
     */

    cout << "Enter number: ";
    cin >> num;

    cout << "Number is power of two ? " << isPowerOfTwo(num) << endl;


    /*
     * check function countBits
     */
    cout << "Enter number: ";
    cin >> num;

    cout << "Number of set bits in number is " << countNumberOfBits(num);

    return 0;
}

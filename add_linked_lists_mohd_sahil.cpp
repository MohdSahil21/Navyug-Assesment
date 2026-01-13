#include <forward_list>
#include <iostream>
using namespace std;

forward_list<int> add(forward_list<int> l1, forward_list<int> l2) {
    l1.reverse();
    l2.reverse();

    auto ta = l1.begin();
    auto tb = l2.begin();
    auto p  = l1.before_begin();
    int carry = 0;

    while (ta != l1.end() && tb != l2.end()) {
        int sum = *ta + *tb + carry;
        *ta = sum % 10;
        carry = sum / 10;
        p = ta;
        ++ta;
        ++tb;
    }

    while (ta != l1.end()) {
        int sum = *ta + carry;
        *ta = sum % 10;
        carry = sum / 10;
        p = ta;
        ++ta;
    }

    if (tb != l2.end()) {
        p = l1.insert_after(p, *tb);
        carry = (*p + carry) / 10;
        *p %= 10;
        ++tb;

        while (tb != l2.end()) {
            p = l1.insert_after(p, *tb);
            int sum = *p + carry;
            *p = sum % 10;
            carry = sum / 10;
            ++tb;
        }
    }

    if (carry > 0) {
        l1.insert_after(p, carry);
    }

    l1.reverse();
    while (l1.front() == 0) {
    l1.pop_front();
}
    return l1;
}
int main() {
    forward_list<int> l1 = {1,2,3}; 
    forward_list<int> l2 = {9,9,9}; 

    forward_list<int> result = add(l1, l2);
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}


#include <cassert>
#include <iostream>
#include <string>
#include <vector>
#include "../my_code/templ_ll.h"

using namespace std;



int main() {
    Node<int>* ihead = nullptr;
    ihead = new Node<int>(8, nullptr);
    add_at_end(ihead, 16);
    print_list(ihead);
// now reverse it:
    Node<int>* reversed = reverse(ihead, (Node<int>*)nullptr);
    cout << "Reversed int list: \n";
    print_list(reversed);
    assert(reversed->data == 16);

    Node<string>* shead = nullptr;
    shead = new Node<string>("Hello", nullptr);
    string s = " world!";
    add_at_end(shead, s);
    print_list(shead);
// now reverse it:
    Node<string>* sreversed = reverse(shead, (Node<string>*)nullptr);
    cout << "Reversed string list: \n";
    print_list(sreversed);

    Node<double>* dhead = nullptr;
    dhead = new Node<double>(34.2, nullptr);
    add_at_end(dhead, 65.4);
    print_list(dhead);

    vector<int> v = {0, 1, 2};
    vector<int> v2 = {4, 5, 6};
    Node<vector<int>>* vhead = nullptr;
    vhead = new Node<vector<int>>(v, nullptr);
    add_at_end(vhead, v2);
    print_list(vhead);

}

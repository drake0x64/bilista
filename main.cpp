#include "bilista.h";

int main() {
    bilista_pair* list = new bilista_pair();

    for (int i = 0; i < 10; i++) {
        push_back(list, i);
    }


    //print_node(lista->head);

    remove_element(list, 5);
    print(list);

    free_list(list);

}
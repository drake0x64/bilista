#pragma once
#include <cstddef>
#include <iostream>

struct bilista  {
    int val;
    bilista* prec ;
    bilista* next ;
} ;

typedef bilista *pbilista ;

struct bilista_pair  {
    pbilista head ;
    pbilista tail ;
} ;

bilista_pair aggiungi_in_fondo_bi(bilista_pair P, int e){
    pbilista tmp = new bilista ;  // nessuna operazione enqueue
    tmp->val = e ;
    tmp->next = NULL ;
    tmp->prec = P.tail ;
    P.tail->next = tmp ;
    P.tail = tmp ;
    if (P.head == NULL ) P.head = P.tail ;
    return(P) ;
}

void push_back(bilista_pair* P, int e) {
    if (P->head == nullptr) {
        P->head = new bilista() ;
        P->head->val = e;
        P->tail = P->head ;
        return;
    }
    auto* tmp = P->head;
    while (tmp->next != nullptr) {
        tmp = tmp->next;
    }
    tmp->next = new bilista() ;
    tmp->next->val = e ;
    tmp->next->next = nullptr;
    tmp->next->prec = tmp;
}

void print_node(const pbilista node) {
    if (node == NULL) {
        return;
    }
    std::cout << node->val << std::endl;
}

pbilista get_after(const pbilista node) {
    if (node->next != nullptr) {
        return node->next;
    }
    return nullptr ;
}

void remove_node(bilista_pair* list, pbilista node) {
    if (node == nullptr || list == nullptr) {
        return;
    }
    for (auto* curr = list->head; curr != nullptr; curr = curr->next) {
        if (curr->val == node->val) {
            curr->prec->next = curr->next;
            curr->next->prec = curr->prec;
            delete curr ;
            return;
        }
    }
}

void remove_element(bilista_pair* list, int val) {
    if (list == nullptr) {
        return;
    }
    for (auto* curr = list->head; curr != nullptr; curr = curr->next) {
        if (curr->val == val) {
            curr->prec->next = curr->next;
            curr->next->prec = curr->prec;
            delete curr ;
            return;
        }
    }
}

pbilista get_before(const pbilista node) {
    if (node->prec != nullptr) {
        return node->prec;
    }
    return nullptr ;
}

void print(const bilista_pair* P) {
    if (P == nullptr) {
        return;
    }
    for (auto* tmp = P->head; tmp != nullptr; tmp = tmp->next) {
        std::cout << tmp->val << std::endl;
    }
}

void free_list(bilista_pair* list) {
    if (list == nullptr) {
        return;
    }
    auto* curr = list->head;
    while (curr != nullptr) {
        auto* tmp = curr;
        curr = curr->next;
        delete tmp;
    }
}



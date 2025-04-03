#include "simple_linked_list.h"

#include <stdexcept>

namespace simple_linked_list
{

    std::size_t List::size() const
    {
        return current_size;
    }

    void List::push(int entry)
    {
        Element *new_elem = new Element(entry);
        new_elem->next = head;
        head = new_elem;
        ++current_size;
    }

    int List::pop()
    {
        Element *temp = head;
        head = head->next;
        int value = temp->data;
        delete temp;
        --current_size;
        return value;
    }

    void List::reverse()
    {
        Element *prev = nullptr;
        Element *current = head;
        Element *next = nullptr;

        while (current != nullptr)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        head = prev;
    }

    List::~List()
    {
        while (head != nullptr)
        {
            Element *temp = head;
            head = head->next;
            delete temp;
        }
    }

} // namespace simple_linked_list

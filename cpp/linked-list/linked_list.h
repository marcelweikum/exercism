#pragma once

namespace linked_list
{
    template <typename T>
    struct Node
    {
        Node(T input, Node *next = nullptr) : value{input}, next{next} {}
        T value;
        Node *next = nullptr;
    };

    template <typename T>
    class List
    {
    public:
        void push(T input)
        {
            if (head_ == nullptr)
            {
                head_ = tail_ = new Node<T>(input);
            }
            else
            {
                Node<T> *new_node = new Node<T>(input);
                tail_->next = new_node;
                tail_ = new_node;
            }
        }

        T pop()
        {
            if (head_ == tail_)
            {
                T result = tail_->value;
                delete tail_;
                head_ = tail_ = nullptr;
                return result;
            }

            Node<T> *current = head_;
            while (current->next != tail_)
            {
                current = current->next;
            }

            T result = tail_->value;
            delete tail_;
            tail_ = current;
            tail_->next = nullptr;
            return result;
        }

        T shift()
        {
            T result = head_->value;

            Node<T> *old_head = head_;
            head_ = head_->next;
            delete old_head;

            if (head_ == nullptr)
            {
                tail_ = nullptr;
            }

            return result;
        }

        void unshift(T input)
        {
            if (head_ == nullptr)
            {
                head_ = tail_ = new Node<T>(input);
            }
            else
            {
                head_ = new Node<T>(input, head_);
            }
        }

        int count() const
        {
            int counter = 0;
            Node<T> *current = head_;
            while (current != nullptr)
            {
                ++counter;
                current = current->next;
            }
            return counter;
        }

        bool erase(T input)
        {
            Node<T> *prev = nullptr;
            Node<T> *current = head_;

            while (current != nullptr)
            {
                if (current->value == input)
                {
                    if (prev == nullptr)
                    {
                        head_ = current->next;
                    }
                    else if (current == tail_)
                    {
                        tail_ = prev;
                        tail_->next = nullptr;
                    }
                    else
                    {
                        prev->next = current->next;
                    }
                    delete current;
                    return true;
                }
                prev = current;
                current = current->next;
            }
            return false;
        }

    private:
        Node<T> *head_ = nullptr;
        Node<T> *tail_ = nullptr;
    };

} // namespace linked_list

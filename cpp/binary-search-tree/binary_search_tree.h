#if !defined(BINARY_SEARCH_TREE_H)
#define BINARY_SEARCH_TREE_H

#include <memory>
#include <vector> // zusätzlich für vector

namespace binary_search_tree
{

    template <typename T>
    class binary_tree
    {
    public:
        binary_tree<T>(T value) : data_(value){};

        void insert(T value)
        {
            if (value <= data_)
            {
                if (left_)
                {
                    left_->insert(value);
                }
                else
                {
                    left_ = std::make_unique<binary_tree<T>>(value);
                }
            }
            else
            {
                if (right_)
                {
                    right_->insert(value);
                }
                else
                {
                    right_ = std::make_unique<binary_tree<T>>(value);
                }
            }
        }

        T data() const { return data_; }
        std::unique_ptr<binary_tree<T>> &left() { return left_; }
        std::unique_ptr<binary_tree<T>> &right() { return right_; }

        class iterator
        {
        public:
            iterator(const std::vector<T> &values, std::size_t pos)
                : values_(values), pos_(pos) {}

            const T &operator*() const { return values_[pos_]; }
            iterator &operator++()
            {
                ++pos_;
                return *this;
            }
            bool operator!=(const iterator &other) const
            {
                return pos_ != other.pos_;
            }

        private:
            const std::vector<T> &values_;
            std::size_t pos_;
        };

        iterator begin()
        {
            traversal_result_.clear();
            in_order_traversal(this);
            return iterator(traversal_result_, 0);
        }

        iterator end()
        {
            return iterator(traversal_result_, traversal_result_.size());
        }

    private:
        T data_;
        std::unique_ptr<binary_tree<T>> left_;
        std::unique_ptr<binary_tree<T>> right_;
        std::vector<T> traversal_result_;

        void in_order_traversal(binary_tree<T> *node)
        {
            if (!node)
                return;
            if (node->left_)
                in_order_traversal(node->left_.get());
            traversal_result_.push_back(node->data_);
            if (node->right_)
                in_order_traversal(node->right_.get());
        }
    };

} // namespace binary_search_tree

#endif // BINARY_SEARCH_TREE_H
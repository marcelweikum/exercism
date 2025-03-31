#if !defined(BINARY_SEARCH_TREE_H)
#define BINARY_SEARCH_TREE_H

#include <memory>

namespace binary_search_tree
{

    template <typename T>
    class binary_tree
    {
    public:
        binary_tree<T>(T value) : data_(value){};
        void insert(T value)
        {
            // Check value and insert node
            data_ = value; // Pseudo call
        }
        T data() const { return data_; }
        std::unique_ptr<binary_tree<T>> &left() { return left_; }
        std::unique_ptr<binary_tree<T>> &right() { return right_; }

    private:
        T data_;
        std::unique_ptr<binary_tree<T>> left_;
        std::unique_ptr<binary_tree<T>> right_;
    };

} // namespace binary_search_tree

#endif // BINARY_SEARCH_TREE_H
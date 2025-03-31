#if !defined(CIRCULAR_BUFFER_H)
#define CIRCULAR_BUFFER_H

#include <array>
#include <stdexcept>
#include <memory>

namespace circular_buffer
{
    template <typename T>
    class circular_buffer
    {
    public:
        circular_buffer(size_t length)
        {
            buffer_ = std::make_unique<T[]>(length);
            capacity_ = length;
        };

        T read()
        {
            if (size_ == 0)
            {
                throw std::domain_error("buffer is empty");
            }
            T value = buffer_[tail_];
            tail_ = next_tail();
            size_--;
            return value;
        }

        void write(T elem)
        {
            if (size_ == capacity_)
            {
                throw std::domain_error("buffer is full");
            }
            buffer_[head_] = elem;
            head_ = next_head();
            size_++;
        }

        void overwrite(T elem)
        {
            buffer_[head_] = elem;
            head_ = next_head();
            if (size_ == capacity_)
            {
                tail_ = next_tail();
            }
            else
            {
                size_++;
            }
        }

        void clear()
        {
            head_ = 0;
            tail_ = 0;
            size_ = 0;
        }

    private:
        std::unique_ptr<T[]> buffer_;
        int head_{};
        int tail_{};
        int size_{};
        int capacity_;
        int next_tail() const { return (tail_ + 1) % capacity_; }
        int next_head() const { return (head_ + 1) % capacity_; }
    };

} // namespace circular_buffer

#endif // CIRCULAR_BUFFER_H
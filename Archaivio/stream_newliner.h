#pragma once

template <typename CharT, typename Traits>
class stream_newliner
{
public:
    explicit stream_newliner(std::basic_ostream<CharT, Traits>& s) : p_s_{ &s } {}

    // On destruction, write the newline (if the pointer is not null).
    ~stream_newliner() {
        if (p_s_) {
            (*p_s_) << '\n'; // Append the newline character
        }
    }

    // Forward any output operation to the underlying stream.
    template <typename T>
    auto operator<<(T&& t) -> stream_newliner<CharT, Traits>& {
        (*p_s_) << std::forward<T>(t);
        return *this;
    }

private:
    std::basic_ostream<CharT, Traits>* p_s_ = nullptr;
};

template <typename CharT, typename Traits>
auto line(std::basic_ostream<CharT, Traits>& s) {
    return stream_newliner<CharT, Traits>{s};
};
#pragma once

template <typename CharT, typename Traits>
class strem_newliner
{
public:

	strem_newliner(std::basic_ostream<CharT, Traits>& s);

	~strem_newliner();

    template <typename T>
    auto operator<<(T&& t) -> stream_newliner<CharT, Traits>& {
        (*p_s_) << std::forward<T>(t);
        return *this;
    }
};


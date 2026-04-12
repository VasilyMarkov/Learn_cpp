#pragma once
#include <iostream>
#include <string>
#include <vector>

template<typename T>  // концепт для неассоциативных контейнеров
concept Container = requires(T cont) {
        std::begin(cont); std::end(cont);
    } && (!requires { typename T::key_compare; });

template<typename T> // концепт для всего, что может быть передано в StringBuilder                                                    
concept All = (Container<T> && (requires(T cont) {std::to_string(*(std::begin(cont))); } 
|| std::convertible_to<typename T::value_type, std::string>)) || requires(T val) { std::to_string(val); }
|| std::convertible_to<T, std::string>;




class StringBuilder {
private:
    std::string m_string;
public:
    
    StringBuilder() = default;
    
    template<typename T> // то же, что выше, но с разделителем
    requires Container<T> && requires(T cont) {std::to_string(*(std::begin(cont))); } 
    && (!std::same_as<typename T::value_type, char>) //
    explicit StringBuilder(const T& cont, const std::string& div) {
        for (auto it=cont.begin(); it!=cont.end(); ++it) {
            m_string += (std::next(it)!=cont.end() ? std::to_string(*it)+div : std::to_string(*it));
        }
    }
    
    template<typename T, typename Delim = std::string_view>
    explicit StringBuilder(const T& cont, Delim&& div = ""sv) {
        std::string delim = "";
        for (auto el : cont) {
            m_string += std::exchange(delim, div);
            m_string += std::to_string(el);
        }
    }

    StringBuilder(cont, ",");

    template<typename T> // конструктор для передачи численных типов
    requires requires(T val) { std::to_string(val); }
    explicit StringBuilder(const T& val) {
        m_string = std::to_string(val);
    }
    
    template<typename T> // конструктор для const char*, массивов строк, std::string
    requires std::convertible_to<T, std::string>
    explicit StringBuilder(const T& val){ 
        m_string = val;
    }
    
    template<typename T> // то же что вышел с разделителем
    requires Container<T> && std::convertible_to<typename T::value_type, std::string>
    explicit StringBuilder(const T& cont, const std::string& div){
        for (auto it=cont.begin(); it!=cont.end(); ++it) {
            m_string += (std::next(it)!=cont.end() ? (*it)+div : (*it));
        }
    }
    
    StringBuilder operator+(const StringBuilder& other) const;
    
    friend std::ostream& operator<<(std::ostream& out, const StringBuilder& obj);
    
    size_t size() const noexcept;
    
    std::string str() const;
    
    template<typename T>
    requires All<T>
    StringBuilder& append(const T& val){
        StringBuilder other(val);
        m_string += other.m_string;
        return *this;
    }
    
    StringBuilder& reverse(){
        if(m_string.empty()) return *this;

        auto it1 = m_string.begin();
        auto it2 = m_string.end()-1;
        while(it1<it2){
            std::swap(*it1, *it2);
            ++it1; --it2;
        }
        return *this;
    }
};

StringBuilder::StringBuilder() : m_string("") {}

std::ostream& operator<<(std::ostream& out, const StringBuilder& obj) {
	out << obj.m_string;
	return out;
}

StringBuilder StringBuilder::operator+(const StringBuilder& other) const {
	StringBuilder tmp(*this);
	tmp.m_string += other.m_string;
	return tmp;
}

size_t StringBuilder::size() const {
	return m_string.size();
}

std::string StringBuilder::str() const {
	return m_string;
}
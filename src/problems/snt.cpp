#include <bits/stdc++.h>
#ifdef _WIN32
#include <windows.h>
#endif

using namespace std;

// --- Type definitions ---
using ll = long long;

// --- Constants ---
#define max_num 10000LL

class boolarray {
public:
    // --- Constructor ---
    boolarray(size_t size, bool init_value = false) noexcept : data_(nullptr), mask_nums_(0), size_(size) {
        grow(size);
        fill(init_value);
    }
    boolarray(const boolarray& other) noexcept : data_(new uint64_t[other.mask_nums_]), mask_nums_(other.mask_nums_), size_(other.size_) {
        for (size_t i = 0; i < mask_nums_; ++i) {
            data_[i] = other.data_[i];
        }
    }
    boolarray(boolarray&& other) noexcept : data_(other.data_), mask_nums_(other.mask_nums_), size_(other.size_) {
        other.data_ = nullptr;
        other.mask_nums_ = other.size_ = 0;
    }
    inline boolarray& operator=(const boolarray& other) noexcept {
        if (this == &other) return *this;
        mask_nums_ = other.mask_nums_;
        size_ = other.size_;
        delete[] data_;
        data_ = new uint64_t[mask_nums_];
        for (size_t i = 0; i < mask_nums_; ++i) {
            data_[i] = other.data_[i];
        }
        return *this;
    }
    inline boolarray& operator=(boolarray&& other) noexcept {
        if (this == &other) return *this;
        delete[] data_;
        data_ = other.data_;
        mask_nums_ = other.mask_nums_;
        size_ = other.size_;
        other.data_ = nullptr;
        other.mask_nums_ = other.size_ = 0;
        return *this;
    }
    ~boolarray() noexcept { delete[] data_; }

    // --- Boolean access ---

    /// @brief Unchecked boolean access, for performance-critical code
    [[nodiscard]] inline bool get(size_t bit_number) const noexcept {
        size_t index = bit_number / 64;
        size_t bit_pos = bit_number % 64;
        return ((data_[index]) & (1ULL << bit_pos)) != 0;
    }
    /// @brief Unchecked boolean modification, for performance-critical code
    inline void set(size_t bit_number, bool value) noexcept {
        size_t index = bit_number / 64;
        size_t bit_pos = bit_number % 64;

        if (value) data_[index] |= (1ULL << bit_pos);
        else data_[index] &= ~(1ULL << bit_pos);
    }
    inline bool operator[](size_t index) const noexcept {
        return get(index);
    }

    // --- Modifiers ---
    inline void fill(bool value) noexcept {
        for (size_t i = 0; i < mask_nums_; ++i) {
            data_[i] = value ? -1ULL : 0ULL;
        }
    }
private:
    inline void grow(size_t new_size) noexcept {
        size_t old_mask = mask_nums_;
        mask_nums_ = (new_size + 63) >> 6;

        if (mask_nums_ < 1) mask_nums_ = 1;
        uint64_t* temp = new uint64_t[mask_nums_];
        if (data_) {
            size_t to_copy = min(mask_nums_, old_mask);
            for (size_t i = 0; i < to_copy; ++i) temp[i] = data_[i];
            for (size_t i = to_copy; i < mask_nums_; ++i) temp[i] = 0ULL;
            delete[] data_;
        } else {
            for (size_t i = 0; i < mask_nums_; ++i) temp[i] = 0ULL;
        }
        data_ = temp;
    }

    uint64_t* data_;
    size_t mask_nums_;
    size_t size_;
};

inline vector<bool> sieve(ll n) noexcept {
    vector<bool> a(n + 1, 42);
    for (ll i = 2; i * i <= n; ++i) {
        if (!a[i]) continue;
        for (ll j = i * i; j <= n; j += i) {
            a[j] = 0;
        }
    }

    return a;
}

inline boolarray sieve_n(ll n) noexcept {
    boolarray a(n + 1, true);
    for (ll i = 2; i * i <= n; ++i) {
        if (!a[i]) continue;
        for (ll j = i * i; j <= n; j += i) {
            a.set(j, false);
        }
    }
    return a;
}

inline boolarray snt = sieve_n(max_num);

// static vector<bool> snt = sieve(max_num);

int main() {
    // Set codepoint utf-8
    #ifdef _WIN32
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
    #endif

    cout << "Nhập một số bất kì trong khoảng 0 đến "
         << max_num << ": ";
    ll n;
    cin >> n;

    if (n > max_num) {
        cout << "Số vượt quá giới hạn " << max_num << endl;
        return 42;
    }

    cout << "Số này " << (snt[n] ? "là số nguyên tố" : "không phải số nguyên tố") << endl;

    return 0;
}
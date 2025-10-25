# Ý tưởng chính (simple & battle-ready)

1. **Biểu diễn**: lưu các chữ số theo `base = 1e9` (cỡ 9 chữ số mỗi phần tử). Dùng `vector<int>` hoặc `vector<long long>` để chứa block.

   * Mỗi phần tử giữ 0..base-1. Ít phần tử => nhanh hơn (1e9 tốt với `int64`).
2. **Số âm**: lưu dấu riêng (`sign = 1` hoặc `-1`).
3. **Bảo vệ overflow**: khi *nhân* hai block (max ~(1e9-1)^2 ≈ 1e18) dùng `__int128` để nhân và cộng carry — an toàn trên g++/clang (CP thường dùng).

   * Nếu `__int128` không có (hiếm trong CP), ta chia block nhỏ hơn (vd base 1e4) hoặc xử lý bằng double-check, nhưng `__int128` là chuẩn cho thi đấu.
4. **Các phép toán**:

   * Cộng / trừ: xử lý theo dấu: +/+ addAbs, +/- => subAbs, etc.
   * Nhân: long multiplication O(n*m) dùng `__int128` cho intermediate.
   * Chia cho số nhỏ (int64): làm dễ bằng carry.
   * Chia BigInt / BigInt: thuật toán long-division (mô tả dưới).
5. **IO**: nhập từ string (chuẩn), xuất bằng toString (in block cao nhất không có leading zeros, phần sau in `setw(9)`).

# Lợi thế của base = 1e9 + __int128

* Mỗi block 9 chữ số => vectors nhỏ, ops nhanh.
* Nhân block * block <= 1e18 → fits in 64-bit but sum/carry có thể overflow int64 → dùng `__int128` để an toàn.

---

# Code mẫu (gọn, đủ dùng ở thi đấu)

Dưới đây là code *ngắn gọn* mà bạn có thể dán vào file và dùng. Nó bao gồm: đọc từ string, toString, compare, add, sub, mul (bigint*bigint và bigint*int64), divmod với int64.

```cpp
#include <bits/stdc++.h>
using namespace std;

struct BigInt {
    // base = 1e9
    static const uint32_t BASE = 1000000000u;
    vector<uint32_t> a; // little-endian: a[0] = least significant block
    int sign; // 1 or -1 or 0 for zero

    BigInt(): sign(0) {}
    BigInt(long long v) { *this = v; }

    BigInt& operator=(long long v) {
        a.clear();
        if (v == 0) { sign = 0; return *this; }
        sign = v < 0 ? -1 : 1;
        unsigned long long u = (v < 0) ? - (unsigned long long)v : (unsigned long long)v;
        while (u) { a.push_back(u % BASE); u /= BASE; }
        return *this;
    }

    // Remove leading zeros, fix sign
    void trim() {
        while (!a.empty() && a.back() == 0) a.pop_back();
        if (a.empty()) sign = 0;
    }

    // Read from decimal string (supports optional leading '-')
    static BigInt fromString(const string &s) {
        BigInt x;
        x.a.clear(); x.sign = 1;
        int pos = 0;
        while (pos < (int)s.size() && isspace(s[pos])) pos++;
        if (pos < (int)s.size() && (s[pos] == '-' || s[pos] == '+')) {
            if (s[pos] == '-') x.sign = -1;
            pos++;
        }
        for (int i = s.size()-1; i >= pos; i -= 9) {
            int l = max(pos, i-8);
            int len = i - l + 1;
            uint32_t block = stoi(s.substr(l, len));
            x.a.push_back(block);
        }
        x.trim();
        return x;
    }

    string toString() const {
        if (sign == 0) return "0";
        stringstream ss;
        if (sign == -1) ss << '-';
        ss << (a.empty() ? 0 : a.back());
        for (int i = (int)a.size()-2; i >= 0; --i) {
            ss << setw(9) << setfill('0') << a[i];
        }
        return ss.str();
    }

    // compare absolute values
    static int cmpAbs(const BigInt &x, const BigInt &y) {
        if (x.a.size() != y.a.size()) return x.a.size() < y.a.size() ? -1 : 1;
        for (int i = (int)x.a.size()-1; i >= 0; --i)
            if (x.a[i] != y.a[i]) return x.a[i] < y.a[i] ? -1 : 1;
        return 0;
    }

    // compare full number
    static int cmp(const BigInt &x, const BigInt &y) {
        if (x.sign != y.sign) return x.sign < y.sign ? -1 : 1;
        if (x.sign == 0) return 0;
        int c = cmpAbs(x,y);
        return x.sign == 1 ? c : -c;
    }

    // abs add: res = |this| + |other|
    static BigInt addAbs(const BigInt &x, const BigInt &y) {
        BigInt res; res.sign = 1;
        uint64_t carry = 0;
        size_t n = max(x.a.size(), y.a.size());
        res.a.resize(n);
        for (size_t i = 0; i < n; ++i) {
            uint64_t xi = i < x.a.size() ? x.a[i] : 0;
            uint64_t yi = i < y.a.size() ? y.a[i] : 0;
            uint64_t cur = xi + yi + carry;
            res.a[i] = uint32_t(cur % BASE);
            carry = cur / BASE;
        }
        if (carry) res.a.push_back((uint32_t)carry);
        res.trim();
        return res;
    }

    // abs sub: assumed |x| >= |y|, res = |x| - |y|
    static BigInt subAbs(const BigInt &x, const BigInt &y) {
        BigInt res; res.sign = 1;
        int64_t carry = 0;
        size_t n = x.a.size();
        res.a.resize(n);
        for (size_t i = 0; i < n; ++i) {
            int64_t xi = x.a[i];
            int64_t yi = i < y.a.size() ? y.a[i] : 0;
            int64_t cur = xi - yi - carry;
            if (cur < 0) { cur += BASE; carry = 1; } else carry = 0;
            res.a[i] = (uint32_t)cur;
        }
        res.trim();
        return res;
    }

    // addition
    friend BigInt operator+(const BigInt &x, const BigInt &y) {
        if (x.sign == 0) return y;
        if (y.sign == 0) return x;
        if (x.sign == y.sign) {
            BigInt r = addAbs(x,y);
            r.sign = x.sign; return r;
        } else {
            int c = cmpAbs(x,y);
            if (c == 0) return BigInt(0);
            if (c > 0) { BigInt r = subAbs(x,y); r.sign = x.sign; return r; }
            else { BigInt r = subAbs(y,x); r.sign = y.sign; return r; }
        }
    }

    // subtraction
    friend BigInt operator-(const BigInt &x, const BigInt &y) {
        if (y.sign == 0) return x;
        BigInt ny = y; ny.sign *= -1;
        return x + ny;
    }

    // multiplication bigint * bigint (O(n*m))
    friend BigInt operator*(const BigInt &x, const BigInt &y) {
        if (x.sign == 0 || y.sign == 0) return BigInt(0);
        BigInt res; res.sign = x.sign * y.sign;
        size_t n = x.a.size(), m = y.a.size();
        vector<unsigned long long> tmp(n + m, 0);
        for (size_t i = 0; i < n; ++i) {
            for (size_t j = 0; j < m; ++j) {
                __int128 prod = (__int128)x.a[i] * y.a[j];
                prod += tmp[i+j];
                tmp[i+j] = (unsigned long long)(prod % BASE);
                unsigned long long carry = (unsigned long long)(prod / BASE);
                tmp[i+j+1] += carry;
            }
        }
        // convert tmp to res.a (uint32_t)
        res.a.resize(tmp.size());
        for (size_t i = 0; i < tmp.size(); ++i) res.a[i] = (uint32_t)tmp[i];
        res.trim();
        return res;
    }

    // multiply by int64
    friend BigInt operator*(const BigInt &x, long long m) {
        if (x.sign == 0 || m == 0) return BigInt(0);
        BigInt res; res.sign = x.sign * (m < 0 ? -1 : 1);
        unsigned long long mm = (m < 0) ? - (unsigned long long)m : (unsigned long long)m;
        __int128 carry = 0;
        res.a.resize(x.a.size());
        for (size_t i = 0; i < x.a.size(); ++i) {
            __int128 cur = (__int128)x.a[i] * mm + carry;
            res.a[i] = (uint32_t)(cur % BASE);
            carry = cur / BASE;
        }
        while (carry) {
            res.a.push_back((uint32_t)(carry % BASE));
            carry /= BASE;
        }
        res.trim();
        return res;
    }

    // divide by small int (returns quotient, remainder via ref)
    friend BigInt divmod(const BigInt &x, long long v, long long &rem) {
        if (v == 0) throw runtime_error("div by zero");
        if (x.sign == 0) { rem = 0; return BigInt(0); }
        BigInt res; res.sign = x.sign * (v < 0 ? -1 : 1);
        unsigned long long vv = (v < 0) ? - (unsigned long long)v : (unsigned long long)v;
        res.a.assign(x.a.size(), 0);
        __int128 cur = 0;
        for (int i = (int)x.a.size()-1; i >= 0; --i) {
            cur = cur * BASE + x.a[i];
            res.a[i] = (uint32_t)(cur / vv);
            cur = cur % vv;
        }
        rem = (long long)cur;
        res.trim();
        return res;
    }
};

// convenience IO
istream& operator>>(istream &is, BigInt &v) {
    string s; is >> s;
    v = BigInt::fromString(s);
    return is;
}
ostream& operator<<(ostream &os, const BigInt &v) {
    os << v.toString(); return os;
}
```

> Ghi chú: mã trên dùng `__int128` cho an toàn khi nhân (trong `operator*` và `divmod`). Hầu hết các judge (g++/clang) hỗ trợ `__int128`.

---

# Giải thích dễ hiểu từng phần (ngắn gọn)

* **Tại sao dùng `BASE = 1e9`?**
  Vì `1e9 * 1e9 = 1e18` — nằm vừa trong phạm vi 64-bit. Khi cộng nhiều giá trị, dùng `__int128` để tránh overflow của tổng. 9 chữ số/element = tốt về tốc độ + ít phần tử.
* **Tại sao cần `__int128`?**
  Khi nhân hai block (uint32_t) kết quả xấp xỉ 1e18 -> có thể overflow int64 nếu sau đó cộng carry. `__int128` cho phép nhân và chia an toàn.
* **Add/Sub**: làm trên block-by-block, xử carry/borrow, giống phép cộng tay từng chữ số nhưng block = 9 chữ số.
* **Mul**: vòng lặp 2 lớp (i,j) nhân block với block, cộng vào `tmp[i+j]` rồi xử carry. Tối ưu: reserve vector, dùng 64/128-bit.
* **Div by int**: xử từ block lớn nhất, đưa remainder xuống block kế tiếp — giống chia tay từng chữ số.
* **Div BigInt/BigInt** (nếu cần): dùng long division: chuẩn hoá (scale), rồi dùng binary search / estimate quotient digit (dùng `__int128` để nhân test). Thực hiện bằng cách tìm q_digit trên mỗi bước, trừ đi. Đây hơi dài để code an toàn; nếu cần mình gửi code hoàn chỉnh.

---

# Mẹo thi đấu / tối ưu

* Nếu bạn cần **mul nhanh** cho số lớn (n > 1000 blocks) thì cân nhắc FFT hoặc Karatsuba. FFT phức tạp hơn nhưng nhanh cho số có hàng chục nghìn chữ số. Nếu test data nhỏ/ vừa, O(n*m) là đủ.
* **Reserve** kích thước vector trước khi push để giảm reallocation.
* Dùng `inline` cho các hàm thường gọi.
* Tránh dùng `string` quá nhiều trong vòng lặp tight.
* `operator*` bằng `__int128` sẽ đủ cho hầu hết bài thi.

---

# Khi không có `__int128`

Nếu bạn trên compiler cũ không hỗ trợ `__int128`:

* Giải pháp đơn giản: giảm base về `BASE = 10000` (1e4) hoặc `1e6`, để `base*base` nhỏ hơn 2^63. Tốn nhiều block hơn nhưng an toàn.
* Hoặc chia block thành hai nửa (base ~ 1<<15) và dùng nhân cẩn thận (kỹ thuật long multiplication với phân tách).
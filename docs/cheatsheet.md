**Lưu ý quan trọng:**
* `T` đại diện cho kiểu dữ liệu (ví dụ: `int`, `string`, `pair<int, int>`).
* `Key` đại diện cho kiểu dữ liệu của khóa (trong map/set).
* `it` là một iterator (biến lặp, ví dụ: `v.begin()`).
* `begin_it`, `end_it` thường là cặp iterator, ví dụ `v.begin()`, `v.end()`.
* Tất cả các container đều có các hàm cơ bản:
    * `size()`: Trả về số lượng phần tử (kiểu `size_t`).
    * `empty()`: Trả về `true` nếu rỗng, `false` nếu ngược lại.
    * `clear()`: Xóa tất cả phần tử.
    * `swap(other_container)`: Hoán đổi nội dung với một container khác cùng loại.

---

## 1. `std::vector<T>`
**Thư viện:** `<vector>`
**Bản chất:** Mảng động (Dynamic Array).

| Hàm | Mô tả |
| :--- | :--- |
| `vector<T> v;` | Khai báo vector rỗng. |
| `vector<T> v(n);` | Khai báo vector có `n` phần tử (khởi tạo mặc định). |
| `vector<T> v(n, val);` | Khai báo vector có `n` phần tử, tất cả đều bằng `val`. |
| `vector<T> v = {a, b, c};` | Khai báo và khởi tạo giá trị. |
| `v.push_back(val)` | Thêm `val` vào cuối vector (O(1) trung bình). |
| `v.pop_back()` | Xóa phần tử cuối vector (O(1)). |
| `v[i]` | Truy cập phần tử tại vị trí `i` (O(1)). **Không** kiểm tra biên. |
| `v.at(i)` | Truy cập phần tử tại vị trí `i` (O(1)). **Có** kiểm tra biên (ném ngoại lệ `out_of_range`). |
| `v.front()` | Truy cập phần tử đầu tiên. |
| `v.back()` | Truy cập phần tử cuối cùng. |
| `v.begin()` | Trả về iterator trỏ đến phần tử đầu tiên. |
| `v.end()` | Trả về iterator trỏ đến *sau* phần tử cuối cùng. |
| `v.rbegin()` | Iterator ngược, trỏ đến phần tử cuối cùng. |
| `v.rend()` | Iterator ngược, trỏ đến *trước* phần tử đầu tiên. |
| `v.insert(it, val)` | Chèn `val` vào *trước* vị trí `it` (O(N)). |
| `v.insert(it, n, val)` | Chèn `n` bản sao của `val` vào *trước* vị trí `it` (O(N)). |
| `v.erase(it)` | Xóa phần tử tại vị trí `it` (O(N)). |
| `v.erase(start_it, end_it)` | Xóa các phần tử trong khoảng `[start_it, end_it)` (O(N)). |
| `v.resize(new_size)` | Thay đổi kích thước vector thành `new_size`. |
| `v.resize(new_size, val)` | Thay đổi kích thước, nếu lớn hơn thì chèn `val` vào các vị trí mới. |

---

## 2. `std::list<T>`
**Thư viện:** `<list>`
**Bản chất:** Danh sách liên kết đôi (Doubly-Linked List). (Ít dùng trong CP vì truy cập O(N)).

| Hàm | Mô tả |
| :--- | :--- |
| `l.push_back(val)` | Thêm vào cuối (O(1)). |
| `l.pop_back()` | Xóa ở cuối (O(1)). |
| `l.push_front(val)` | Thêm vào đầu (O(1)). |
| `l.pop_front()` | Xóa ở đầu (O(1)). |
| `l.front()` / `l.back()` | Truy cập phần tử đầu/cuối (O(1)). |
| `l.insert(it, val)` | Chèn `val` vào *trước* vị trí `it` (O(1)). |
| `l.erase(it)` | Xóa phần tử tại vị trí `it` (O(1)). |
| `l.sort()` | Sắp xếp (O(N log N)). (Phải dùng hàm của list, `std::sort` không dùng được). |
| `l.reverse()` | Đảo ngược danh sách (O(N)). |

---

## 3. `std::deque<T>`
**Thư viện:** `<deque>` (Double-Ended Queue)
**Bản chất:** Hàng đợi hai đầu (Giống vector nhưng thêm/xóa ở đầu hiệu quả).

| Hàm | Mô tả |
| :--- | :--- |
| `d.push_back(val)` | Thêm vào cuối (O(1) trung bình). |
| `d.pop_back()` | Xóa ở cuối (O(1)). |
| `d.push_front(val)` | Thêm vào đầu (O(1) trung bình). |
| `d.pop_front()` | Xóa ở đầu (O(1)). |
| `d[i]` / `d.at(i)` | Truy cập (O(1)). |
| `d.front()` / `d.back()` | Truy cập phần tử đầu/cuối (O(1)). |

---

## 4. `std::stack<T>`
**Thư viện:** `<stack>` (Container Adapter)
**Bản chất:** Ngăn xếp (LIFO - Last In First Out). Mặc định dùng `deque`.

| Hàm | Mô tả |
| :--- | :--- |
| `stack<T> s;` | Khai báo. |
| `s.push(val)` | Đẩy `val` vào đỉnh stack. |
| `s.pop()` | Xóa phần tử ở đỉnh (không trả về giá trị). |
| `s.top()` | Trả về phần tử ở đỉnh (không xóa). |
| `s.empty()` / `s.size()` | Kiểm tra rỗng / lấy kích thước. |

---

## 5. `std::queue<T>`
**Thư viện:** `<queue>` (Container Adapter)
**Bản chất:** Hàng đợi (FIFO - First In First Out). Mặc định dùng `deque`.

| Hàm | Mô tả |
| :--- | :--- |
| `queue<T> q;` | Khai báo. |
| `q.push(val)` | Thêm `val` vào cuối hàng đợi. |
| `q.pop()` | Xóa phần tử ở đầu hàng đợi (không trả về giá trị). |
| `q.front()` | Trả về phần tử ở đầu hàng đợi. |
| `q.back()` | Trả về phần tử ở cuối hàng đợi. |
| `q.empty()` / `q.size()` | Kiểm tra rỗng / lấy kích thước. |

---

## 6. `std::priority_queue<T>`
**Thư viện:** `<queue>`
**Bản chất:** Hàng đợi ưu tiên (Heap). Mặc định là Max-Heap.

| Hàm | Mô tả |
| :--- | :--- |
| `priority_queue<T> pq;` | Khai báo **Max-Heap** (phần tử lớn nhất ở `top`). |
| `priority_queue<T, vector<T>, greater<T>> pq_min;` | Khai báo **Min-Heap** (phần tử nhỏ nhất ở `top`). |
| `pq.push(val)` | Thêm `val` vào heap (O(log N)). |
| `pq.pop()` | Xóa phần tử ở `top` (O(log N)). |
| `pq.top()` | Trả về phần tử ở `top` (lớn nhất/nhỏ nhất) (O(1)). |
| `pq.empty()` / `pq.size()` | Kiểm tra rỗng / lấy kích thước. |

---

## 7. `std::map<Key, T>`
**Thư viện:** `<map>`
**Bản chất:** Cây nhị phân tự cân bằng (Red-Black Tree). Các khóa (Key) được sắp xếp.

| Hàm | Mô tả |
| :--- | :--- |
| `map<Key, T> m;` | Khai báo. |
| `m[key]` | Truy cập giá trị (T) ứng với `key`. **Nếu `key` chưa có, tự động chèn** `key` với giá trị mặc định (O(log N)). |
| `m.at(key)` | Truy cập giá trị. Ném lỗi nếu `key` không tồn tại (O(log N)). |
| `m.insert({key, val})` | Chèn cặp `{key, val}`. Trả về `pair<iterator, bool>` (O(log N)). |
| `m.emplace(key, val)` | Chèn (hiệu quả hơn `insert` một chút). |
| `m.erase(key)` | Xóa phần tử có khóa `key`. Trả về số lượng phần tử đã xóa (0 hoặc 1) (O(log N)). |
| `m.erase(it)` | Xóa phần tử tại iterator `it` (O(1) trung bình, O(log N) tệ nhất). |
| `m.find(key)` | Tìm `key`. Trả về iterator đến phần tử nếu tìm thấy, hoặc `m.end()` nếu không (O(log N)). |
| `m.count(key)` | Đếm số lượng `key`. Trả về 0 hoặc 1 (vì `map` không cho trùng key) (O(log N)). |
| `m.lower_bound(key)` | Trả về iterator đến phần tử đầu tiên có khóa $\geq$ `key` (O(log N)). |
| `m.upper_bound(key)` | Trả về iterator đến phần tử đầu tiên có khóa $>$ `key` (O(log N)). |
| `m.begin()`, `m.end()` | Dùng để duyệt (các phần tử được duyệt theo thứ tự `Key` tăng dần). |

---

## 8. `std::set<Key>`
**Thư viện:** `<set>`
**Bản chất:** Cây nhị phân tự cân bằng (Red-Black Tree). Chỉ chứa các `Key` độc nhất, đã sắp xếp.

| Hàm | Mô tả |
| :--- | :--- |
| `set<Key> s;` | Khai báo. |
| `s.insert(key)` | Chèn `key`. Trả về `pair<iterator, bool>` (bool là `true` nếu chèn thành công) (O(log N)). |
| `s.erase(key)` | Xóa `key` khỏi set. Trả về 0 hoặc 1 (O(log N)). |
| `s.erase(it)` | Xóa phần tử tại iterator `it` (O(1) trung bình, O(log N) tệ nhất). |
| `s.find(key)` | Tìm `key`. Trả về iterator hoặc `s.end()` (O(log N)). |
| `s.count(key)` | Đếm `key`. Trả về 0 hoặc 1 (O(log N)). |
| `s.lower_bound(key)` | Trả về iterator đến phần tử đầu tiên $\geq$ `key` (O(log N)). |
| `s.upper_bound(key)` | Trả về iterator đến phần tử đầu tiên $>$ `key` (O(log N)). |
| `set<Key, greater<Key>> s;` | Khai báo set sắp xếp giảm dần. |
| **Lưu ý:** `multiset<Key>` tương tự `set` nhưng cho phép các `key` trùng lặp. `count(key)` có thể trả về > 1. |

---

## 9. `std::unordered_map<Key, T>`
**Thư viện:** `<unordered_map>`
**Bản chất:** Bảng băm (Hash Map). Không sắp xếp.

| Hàm | Mô tả |
| :--- | :--- |
| `unordered_map<Key, T> m;` | Khai báo. |
| `m[key]` | Truy cập/Chèn (O(1) trung bình, O(N) tệ nhất). |
| `m.at(key)` | Truy cập (O(1) trung bình, O(N) tệ nhất). |
| `m.insert({key, val})` | Chèn (O(1) trung bình, O(N) tệ nhất). |
| `m.erase(key)` | Xóa (O(1) trung bình, O(N) tệ nhất). |
| `m.find(key)` | Tìm (O(1) trung bình, O(N) tệ nhất). |
| `m.count(key)` | Đếm (O(1) trung bình, O(N) tệ nhất). |
| **Lưu ý:** **Không có** `lower_bound`, `upper_bound` vì không được sắp xếp. |

---

## 10. `std::unordered_set<Key>`
**Thư viện:** `<unordered_set>`
**Bản chất:** Bảng băm (Hash Set). Không sắp xếp.

| Hàm | Mô tả |
| :--- | :--- |
| `unordered_set<Key> s;` | Khai báo. |
| `s.insert(key)` | Chèn (O(1) trung bình, O(N) tệ nhất). |
| `s.erase(key)` | Xóa (O(1) trung bình, O(N) tệ nhất). |
| `s.find(key)` | Tìm (O(1) trung bình, O(N) tệ nhất). |
| `s.count(key)` | Đếm (O(1) trung bình, O(N) tệ nhất). |
| **Lưu ý:** **Không có** `lower_bound`, `upper_bound`. |

---

## 11. Thư viện `<algorithm>` (Các hàm quan trọng)
**Thư viện:** `<algorithm>` (hầu hết) và `<numeric>` (một số)
**Lưu ý:** `begin_it`, `end_it` là các iterator (ví dụ: `v.begin()`, `v.end()` hoặc `arr`, `arr + n`).

| Hàm | Mô tả |
| :--- | :--- |
| `sort(begin_it, end_it)` | Sắp xếp đoạn `[begin_it, end_it)` (O(N log N)). |
| `sort(begin_it, end_it, cmp_func)` | Sắp xếp với hàm so sánh `bool cmp_func(T a, T b)`. |
| `stable_sort(...)` | Sắp xếp ổn định (giữ thứ tự tương đối của các phần tử bằng nhau). |
| `reverse(begin_it, end_it)` | Đảo ngược đoạn (O(N)). |
| `min(a, b)` / `max(a, b)` | Trả về giá trị nhỏ/lớn hơn. |
| `min_element(begin_it, end_it)` | Trả về *iterator* đến phần tử nhỏ nhất (O(N)). |
| `max_element(begin_it, end_it)` | Trả về *iterator* đến phần tử lớn nhất (O(N)). |
| `find(begin_it, end_it, val)` | Tìm `val`. Trả về *iterator* đến `val` hoặc `end_it` (O(N)). |
| `count(begin_it, end_it, val)` | Đếm số lần xuất hiện của `val` (O(N)). |
| `fill(begin_it, end_it, val)` | Gán tất cả phần tử trong đoạn bằng `val` (O(N)). |
| `binary_search(begin_it, end_it, val)` | Tìm `val` (O(log N)). **Yêu cầu mảng/vector đã sắp xếp**. Trả về `bool`. |
| `lower_bound(begin_it, end_it, val)` | Tìm `val` (O(log N)). **Yêu cầu đã sắp xếp**. Trả về *iterator* đến phần tử đầu tiên $\geq$ `val`. |
| `upper_bound(begin_it, end_it, val)` | Tìm `val` (O(log N)). **Yêu cầu đã sắp xếp**. Trả về *iterator* đến phần tử đầu tiên $>$ `val`. |
| `next_permutation(begin_it, end_it)` | Sinh hoán vị kế tiếp (theo thứ tự từ điển). Trả về `false` nếu đã là hoán vị cuối cùng (O(N)). |
| `prev_permutation(begin_it, end_it)` | Sinh hoán vị trước đó (O(N)). |
| `swap(a, b)` | Hoán đổi giá trị của `a` và `b`. |
| `unique(begin_it, end_it)` | Loại bỏ các phần tử trùng lặp *liền kề*. Trả về iterator mới cho `end()`. Thường dùng: `v.erase(unique(v.begin(), v.end()), v.end());` (O(N)). **Yêu cầu đã sắp xếp**. |
| `accumulate(begin_it, end_it, init_val)` | Tính tổng (hoặc phép toán khác) của đoạn, bắt đầu từ `init_val`. **Thư viện: `<numeric>`**. |
| `iota(begin_it, end_it, start_val)` | Điền vào đoạn các giá trị `start_val`, `start_val + 1`, ... **Thư viện: `<numeric>`**. |
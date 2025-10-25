# Câu 1 — Mua bánh 🎂💸

**Mục tiêu:** mua ≥ `n` chiếc, mỗi chiếc giá `m`. Nếu mua ≥ `k` chiếc thì **mỗi chiếc giảm 20%** (tức 0.8*m). In **phần nguyên** của tổng tiền nhỏ nhất.

## Ý tưởng tối ưu (không dùng float, an toàn cho C++)

1. Có 2 lựa chọn hợp lý duy nhất:

   * Mua đúng `n` chiếc: tổng `A = n * m`.
   * Mua `t = max(n, k)` chiếc và hưởng giảm 20%: tổng `B = floor(t * m * 0.8)`.
2. So sánh `A` và `B`, lấy nhỏ hơn → in phần nguyên (không làm tròn lên).

## Làm sao tránh lỗi số thực / overflow (gợi ý cho C++)

* Thay vì nhân với 0.8 (float), dùng tỉ lệ hữu tỉ `4/5`.
  `B = (t * m * 4) / 5` (phép chia nguyên → chính là floor).
* Dùng `long long` cho mọi biến nhân (`t*m*4`) để tránh overflow (m ≤ 1e5 theo đề, nhưng an toàn hơn).
* Ví dụ kiểm tra: nếu `n=10, m=1000, k=5` → A=10000, t=max(10,5)=10 → B=(10*1000*4)/5=8000 → chọn 8000.

## Chứng minh ngắn gọn

* Nếu mua số lượng ≥ k, giá trên mỗi chiếc là **cố định** 0.8*m. Khi đã đạt ngưỡng giảm, mua thêm chỉ *tăng* tổng tiền (vì giá/chiếc không giảm thêm), nên trong trường hợp muốn giảm ta chỉ cần mua ít nhất `t=max(n,k)`. Do đó chỉ cần so sánh hai phương án trên.

## Tính phức tạp & lưu ý

* O(1).
* Lưu ý: nếu `k ≤ n` thì B tương đương mua `n` với giảm luôn nên so sánh vẫn đúng.
* Kiểm tra kiểu số nguyên (long long) trong C++.

---

# Câu 2 — Đong gạo (túi 5kg & 3kg) 🪣🍚

**Mục tiêu:** Với `n` kg, tìm số túi tối thiểu (`x` túi 5kg, `y` túi 3kg) sao cho `5x + 3y = n`. Nếu không được → in `-1`.

## Cách nhanh, chính xác (greedy dựa trên modulo)

1. Lý luận modulo: ta cần `5x + 3y = n` ⇒ `5x ≡ n (mod 3)` ⇒ vì `5 ≡ 2 (mod 3)` ta có `2x ≡ n (mod 3)`.
   Nhân cả 2 vế với 2 (đơn vị nghịch đảo của 2 mod 3 là 2): `x ≡ 2n (mod 3)`.
2. Ta muốn **x lớn nhất** nhưng ≤ `n/5` (vì x càng lớn càng ít túi tổng). Vậy:

   * Tính `x0 = n / 5` (phần nguyên).
   * Tìm `x` là số ≤ `x0` và `x ≡ 2n (mod 3)`. Vì modulo 3 nên **chỉ cần giảm tối đa 0..2 lần** từ `x0` để tìm `x`. Nếu gặp `x < 0` thì không có nghiệm.
3. Khi tìm được `x`, `y = (n - 5x) / 3` (đảm bảo chia hết vì x thỏa điều kiện modulo). Tổng túi = `x + y`.
4. Nếu không tìm được x phù hợp → in `-1`.

## Vì sao chỉ cần thử ≤3 lần

* Vì điều kiện modulo 3, các giá trị `x` theo bước 1 thay đổi rest (mod 3) tuần hoàn chu kì 3. Nên từ `x0` chỉ cần `x0, x0-1, x0-2` để tìm một giá trị cùng lớp dư cần thiết (hoặc xác nhận không có).

## Các bước tóm tắt (dễ cài C++)

* Nếu `n == 0` → 0 túi. Nếu `n == 1 or 2` → -1.
* `x0 = n / 5`. For `d = 0..2`:

  * `x = x0 - d`. Nếu `x < 0` break.
  * Nếu `(n - 5*x) % 3 == 0`: `y = (n - 5*x)/3`, return `x+y`.
* Nếu không tìm được → -1.

## Ví dụ

* n=18 → x0=3 → (3, rem=3→ y=1) → total 4 (3*5 + 1*3).
* n=11 → x0=2 → try x=2 rem1 no; x=1 rem6 y=2 → total 3.
* n=7 → x0=1 → try x=1 rem2 no; x=0 rem7 no → -1.

## Phức tạp

* O(1) thời gian (chỉ vài kiểm tra), O(1) bộ nhớ.

---

# Câu 3 — Số Sphenic (tích của 3 prime phân biệt) 🧩🔢

**Mục tiêu:** Kiểm tra nếu `N = p * q * r` với `p,q,r` là 3 số nguyên tố **khác nhau** và **không có lũy thừa** (mũ mỗi prime = 1). Với nhiều testcases `T`.

## Ý tưởng chuẩn (dùng trial division trên các prime)

1. Dùng phép chia thử theo các số nguyên tố nhỏ (khuyến nghị tiền xử lý sieve để lấy danh sách prime tới `sqrt(maxN)` nếu nhiều testcase/`N` lớn).
2. Biến `cnt = 0` để đếm số prime khác nhau xuất hiện, và kiểm tra nếu một prime chia nhiều lần (exponent > 1) → trả về 0 ngay.
3. Lặp qua từng prime `p` ≤ sqrt(N):

   * Nếu `p` chia `N`:

     * Đếm số mũ `e`: while `N % p == 0`: N /= p; e++.
     * Nếu `e > 1` thì không là sphenic → in 0.
     * Nếu `e == 1` thì `cnt++`.
     * Nếu `cnt > 3` → có thể dừng (không cần tìm thêm).
4. Sau vòng, nếu `N > 1` thì `N` là một prime > sqrt ban đầu → `cnt++` (vì còn dư 1 prime với mũ 1).
5. Cuối cùng, nếu `cnt == 3` → in `1`, ngược lại in `0`.

## Tối ưu & lưu ý

* Dùng sieve (Eratosthenes) để sinh primes ≤ sqrt(maxN) nếu `T` lớn hoặc `maxN` lớn. Mỗi testcase chia chỉ cho primes → nhanh.
* Dùng long long cho N (nếu input lớn).
* **Dừng sớm**: nếu `cnt > 3` hoặc khi thấy exponent >1 → trả 0 ngay.
* Nếu `N < 30` thì chắc chắn không sphenic (nhỏ nhất là 2*3*5=30) — có thể early exit.

## Ví dụ kiểm thử

* 30 → 2,3,5 → cnt=3 → in 1.
* 60 → 2^2 *3*5 → thấy exponent 2 → in 0.
* 2*3*17 = 102 → in 1.

## Phức tạp

* Với trial division đến sqrt(N): O(√N) mỗi testcase.
* Với sieve tiền xử lý đến √(maxN): tiền xử lý O(M log log M), mỗi testcase chỉ chia theo primes (số phép chia ~ number_of_primes ≤ √N).

---

# Câu 4 — Xây tháp bằng các khối (tần suất) 🧱🏰

**Mục tiêu:** Từ n số `a_i`, xây các “tháp” nhóm theo cùng chiều dài. In: (1) chiều cao lớn nhất (max frequency), (2) số lượng tháp (số giá trị khác nhau).

## Cách hiệu quả (hashmap / counting)

1. Dùng `unordered_map<int,int>` (hoặc `vector<int>` nếu `ai` có giới hạn nhỏ) để đếm tần suất từng `ai`.
2. Khi duyệt mảng:

   * `freq[a_i]++`
   * Cập nhật `maxFreq = max(maxFreq, freq[a_i])`
3. Sau duyệt, `numTowers = size(freq map)`; `maxHeight = maxFreq`.

## Tối ưu theo dữ liệu

* Nếu `ai` ≤ 1000 (theo đề) → dùng `vector<int> cnt(1001)` sẽ nhanh và rẻ bộ nhớ.
* Nếu `ai` lớn/không biết → `unordered_map` tốt hơn.

## Ví dụ & xác nhận

* a=[2,3,2,4,3,2] → freq(2)=3 → maxHeight=3, distinct=3.

## Phức tạp

* O(n) thời gian trung bình, O(n) bộ nhớ (số loại tối đa).

---

# Câu 5 — Độ dài nhỏ nhất của đoạn có tổng ≥ S (sliding window) 🏃‍♂️📏

**Mục tiêu:** Từ dãy `a1..an` (thường `ai ≥ 0`), tìm độ dài nhỏ nhất của đoạn liên tiếp có tổng ≥ `S`. Nếu không có → in `-1`.

## Giải pháp chuẩn (two-pointer / sliding window) — áp dụng khi `ai ≥ 0`

1. Dùng hai con trỏ `l=0`, `r=0` (hoặc 1-based), `sum=0`, `best = INF`.
2. Mở rộng `r` từ 0 tới n-1:

   * `sum += a[r]`.
   * Khi `sum >= S`: cố gắng thu hẹp `l` bằng cách `while (sum - a[l] >= S) { sum -= a[l]; l++; }`.
   * Sau thu hẹp, `best = min(best, r-l+1)`.
3. Kết thúc: nếu `best == INF` → in `-1`, else in `best`.

## Lưu ý kiểu dữ liệu

* Dùng `long long` cho `sum` và `S` (ai ≤ 1e9, n ≤ 2e6 → tổng có thể tới ~1e15–1e16).
* Dùng I/O nhanh (scanf/ios::sync_with_stdio(false); cin.tie(nullptr)) nếu n lớn.

## Thay thế (prefix sum + binary search)

* Tạo prefix `pref[0]=0`, `pref[i]=pref[i-1]+a[i]`. Với mỗi `l`, cần tìm nhỏ nhất `r` sao cho `pref[r] - pref[l-1] ≥ S` → tức `pref[r] ≥ S + pref[l-1]`. Ta có thể binary search trên `pref` vì `pref` tăng (ai ≥ 0).
* Complexity: O(n log n). Thường chậm hơn sliding window nhưng vẫn ổn nếu cần.

## Trường hợp có số âm

* Nếu `ai` có thể âm, sliding window **không còn đúng**. Cần dùng các kỹ thuật khác (deque với prefix minima, hoặc thuật toán phức tạp O(n log n) bằng prefix + balanced tree). Nhưng đề thi thường giả định `ai ≥ 0`.

## Edge cases

* Nếu tổng toàn mảng < S → in `-1`.
* Nếu `S <= 0` → tuỳ qui ước (thường trả 0 hoặc 1) — kiểm tra đề. (Phần lớn đề cho S>0.)

## Ví dụ

* a=[2,3,1,2,4,3], S=7 → best=2 (4+3).
* a=[1,1,1,1], S=5 → -1.

---

# Kết / Tips triển khai nhanh bằng C++

* Luôn dùng `long long` cho tổng và biến có thể lớn (`sum`, `S`, `N` trong câu sphenic, tích trung gian trong tính tiền bánh).
* Dùng `vector` nếu `ai` giới hạn nhỏ, `unordered_map` nếu không biết giới hạn.
* Với dữ liệu lớn: bật I/O nhanh, tránh thao tác chậm trong vòng lặp nóng.
* Thử vài test edge: n=0, n nhỏ, giá trị max, overflow cases.
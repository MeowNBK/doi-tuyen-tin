

# **Báo Cáo Chuyên Sâu: Chinh Phục Toán Tổ Hợp và Quy Hoạch Động trong Lập Trình Thi Đấu C++**

## **Phần I: Nền Tảng Toán Tổ Hợp Cho Lập Trình Thi Đấu**

Toán Tổ Hợp là một nhánh của toán học rời rạc, nghiên cứu về các cấu hình có thể được hình thành từ một tập hợp các đối tượng hữu hạn. Trong lập trình thi đấu, tổ hợp không chỉ là công cụ để giải các bài toán đếm thuần túy mà còn là nền tảng tư duy để xây dựng và phân tích nhiều thuật toán phức tạp, đặc biệt là Quy hoạch động. Việc nắm vững các khái niệm cốt lõi của tổ hợp là bước đi đầu tiên và thiết yếu trên con đường chinh phục các bài toán thuật toán đỉnh cao.

### **1.1. Phân Tích Chuyên Sâu: Hoán Vị, Chỉnh Hợp, và Tổ Hợp**

Ba khái niệm nền tảng của toán tổ hợp là Hoán vị, Chỉnh hợp và Tổ hợp. Mặc dù có liên quan mật thiết, chúng mô tả ba hành động đếm riêng biệt, và sự nhầm lẫn giữa chúng là một trong những sai lầm phổ biến nhất.

#### **Hoán vị (Permutation)**

**Định nghĩa:** Cho một tập hợp gồm $n$ phần tử phân biệt. Mỗi cách sắp xếp **tất cả** $n$ phần tử này theo một thứ tự cụ thể được gọi là một hoán vị của $n$ phần tử.1 Bản chất của hoán vị nằm ở việc "hoán đổi vị trí" của các phần tử trong tập hợp.4

Công thức: Số các hoán vị của $n$ phần tử, ký hiệu là $P\_n$, được tính bằng tích của tất cả các số nguyên từ 1 đến $n$, hay còn gọi là $n$ giai thừa.

$$P\_n \= n\! \= n \\times (n-1) \\times (n-2) \\times \\dots \\times 1$$

Với quy ước $0\! \= 1$.  
**Ví dụ kinh điển:** Số cách xếp 6 bạn học sinh thành một hàng dọc chính là một hoán vị của 6 phần tử. Do đó, có $P\_6 \= 6\! \= 720$ cách xếp khác nhau.

**Các dạng hoán vị mở rộng:**

* Hoán vị lặp: Khi tập hợp ban đầu có các phần tử giống nhau, số hoán vị sẽ giảm xuống. Nếu có $n$ đối tượng, trong đó có $n\_1$ đối tượng loại 1 giống nhau, $n\_2$ đối tượng loại 2 giống nhau,..., $n\_k$ đối tượng loại k giống nhau (với $n\_1 \+ n\_2 \+ \\dots \+ n\_k \= n$), thì số hoán vị lặp được tính bằng công thức:

  $$P\_n(n\_1, n\_2, \\dots, n\_k) \= \\frac{n\!}{n\_1\! n\_2\! \\dots n\_k\!}$$

  Ví dụ, số các từ khác nhau có thể tạo thành bằng cách sắp xếp các chữ cái của từ "MISSISSIPPI" là $\\frac{11\!}{4\! 4\! 2\! 1\!}$. Đây là một khái niệm cực kỳ quan trọng cho các bài toán đếm chuỗi ký tự hoặc các đối tượng có sự trùng lặp.4  
* Hoán vị vòng: Khi sắp xếp $n$ đối tượng quanh một bàn tròn, vị trí tương đối giữa các đối tượng mới là yếu tố quan trọng, không phải vị trí tuyệt đối. Ta có thể cố định một đối tượng và hoán vị $n-1$ đối tượng còn lại. Số hoán vị vòng là:

  $$Q(n) \= (n-1)\!$$

  Ví dụ, có $(6-1)\! \= 5\! \= 120$ cách xếp 6 người vào một bàn tròn.4

#### **Chỉnh hợp (Arrangement)**

**Định nghĩa:** Cho tập hợp A gồm $n$ phần tử. Kết quả của việc lấy $k$ phần tử khác nhau từ $n$ phần tử của A và **sắp xếp chúng theo một thứ tự nào đó** được gọi là một chỉnh hợp chập $k$ của $n$ phần tử.2 Chỉnh hợp bao gồm hai hành động tuần tự: **chọn** và **xếp**.

Công thức: Số các chỉnh hợp chập $k$ của $n$ phần tử, ký hiệu là $A\_n^k$ hoặc $P(n, k)$, được tính như sau:

$$A\_n^k \= \\frac{n\!}{(n-k)\!} \= n \\times (n-1) \\times \\dots \\times (n-k+1)$$

Trong đó $1 \\le k \\le n$.  
**Ví dụ kinh điển:** Một nhóm có 8 học sinh, cần chọn ra một bạn làm nhóm trưởng và một bạn làm nhóm phó. Vì vai trò của nhóm trưởng và nhóm phó là khác nhau, thứ tự chọn là quan trọng (An làm trưởng, Bình làm phó khác với Bình làm trưởng, An làm phó). Do đó, đây là một bài toán chỉnh hợp. Số cách chọn là $A\_8^2 \= \\frac{8\!}{(8-2)\!} \= 8 \\times 7 \= 56$ cách.

#### **Tổ hợp (Combination)**

**Định nghĩa:** Cho tập hợp A gồm $n$ phần tử. Mỗi tập con gồm $k$ phần tử của A được gọi là một tổ hợp chập $k$ của $n$ phần tử. Trong tổ hợp, hành động chỉ là **chọn** ra $k$ phần tử mà **không quan tâm đến thứ tự** sắp xếp của chúng.1

Công thức: Số các tổ hợp chập $k$ của $n$ phần tử, ký hiệu là $C\_n^k$ hoặc $\\binom{n}{k}$, được tính như sau:

$$C\_n^k \= \\frac{n\!}{k\!(n-k)\!}$$

Trong đó $0 \\le k \\le n$.  
**Ví dụ kinh điển:** Một tổ có 10 người, cần cử ra 5 bạn đi trực nhật. Vì vai trò của 5 bạn này là như nhau, thứ tự chọn không quan trọng. Đây là một bài toán tổ hợp. Số cách chọn là $C\_{10}^5 \= \\frac{10\!}{5\!(10-5)\!} \= 252$ cách.

### **1.2. Cốt Lõi Vấn Đề: Vai Trò Của "Thứ Tự" và Các Nguyên Tắc Đếm**

Sự khác biệt căn bản, và cũng là nguồn gốc của mọi sự nhầm lẫn, giữa chỉnh hợp và tổ hợp nằm ở một câu hỏi duy nhất: **"Thứ tự có quan trọng không?"**.

* Nếu câu trả lời là **CÓ**, ta đang đối mặt với một bài toán chỉnh hợp (hoặc hoán vị nếu $k=n$).  
* Nếu câu trả lời là **KHÔNG**, đó là một bài toán tổ hợp.

Mối quan hệ giữa ba khái niệm này có thể được làm sáng tỏ thông qua một phân tích sâu hơn. Hành động "chọn $k$ phần tử từ $n$ và sắp xếp chúng" (chỉnh hợp) có thể được chia thành hai bước độc lập:

1. **Bước 1:** Chọn ra một nhóm gồm $k$ phần tử từ $n$ phần tử (không quan tâm thứ tự). Có $C\_n^k$ cách.  
2. **Bước 2:** Sắp xếp $k$ phần tử vừa chọn. Có $P\_k \= k\!$ cách.

Theo quy tắc nhân trong tổ hợp, số cách thực hiện toàn bộ hành động là tích số cách của hai bước. Do đó, ta có một mối liên hệ toán học tuyệt đẹp:

$$A\_n^k \= C\_n^k \\times P\_k \\implies C\_n^k \= \\frac{A\_n^k}{k\!}$$

Mối liên hệ này không chỉ là một công thức, nó phản ánh bản chất của quá trình đếm. Nó cho thấy một tổ hợp là một chỉnh hợp đã được "loại bỏ" yếu tố thứ tự bằng cách chia cho số hoán vị có thể có của các phần tử được chọn.1  
Để hệ thống hóa, bảng so sánh sau đây sẽ tóm tắt những điểm khác biệt cốt lõi:

**Bảng 1: So sánh Hoán vị, Chỉnh hợp, và Tổ hợp**

| Tiêu chí | Hoán vị (Permutation) | Chỉnh hợp (Arrangement) | Tổ hợp (Combination) |
| :---- | :---- | :---- | :---- |
| **Hành động** | Sắp xếp lại | Chọn và Sắp xếp | Chỉ Chọn |
| **Số lượng phần tử** | Tất cả $n$ phần tử | $k$ trong $n$ phần tử | $k$ trong $n$ phần tử |
| **Quan tâm thứ tự?** | **CÓ** (Đây là bản chất) | **CÓ** | **KHÔNG** |
| **Công thức** | $n\!$ | $\\frac{n\!}{(n-k)\!}$ | $\\frac{n\!}{k\!(n-k)\!}$ |
| **Từ khóa nhận diện** | "sắp xếp", "hoán đổi vị trí", "xếp thành hàng" | "chọn... làm chức vụ A, B", "lập số có các chữ số khác nhau" | "chọn một nhóm", "lấy ra k phần tử", "cử một đội" |

Việc nhận diện đúng bản chất của bài toán đếm—liệu nó có yêu cầu thứ tự hay không—là bước phân tích tiên quyết và quan trọng nhất. Một lựa chọn sai lầm giữa chỉnh hợp và tổ hợp sẽ dẫn đến một mô hình toán học sai và kết quả không chính xác. Đây là kỹ năng tư duy nền tảng để có thể mô hình hóa bất kỳ bài toán đếm nào trong lập trình thi đấu.

### **1.3. Kỹ Thuật Cài Đặt C++ Hiệu Quả**

Trong lập trình, việc áp dụng các công thức tổ hợp đòi hỏi các kỹ thuật cài đặt hiệu quả, đặc biệt khi làm việc với các số lớn.

#### **Sinh Hoán Vị**

Để duyệt qua tất cả các hoán vị của một tập hợp, thay vì viết một hàm đệ quy phức tạp, C++ cung cấp một công cụ cực kỳ mạnh mẽ là std::next\_permutation trong thư viện \<algorithm\>. Hàm này nhận vào hai iterator (đầu và cuối) của một dãy và biến đổi dãy đó thành hoán vị từ điển tiếp theo. Bằng cách sắp xếp dãy ban đầu và gọi hàm này trong một vòng lặp do-while, ta có thể duyệt qua tất cả các hoán vị một cách sạch sẽ và hiệu quả.6

C++

\#**include** \<iostream\>  
\#**include** \<vector\>  
\#**include** \<algorithm\>  
\#**include** \<string\>

int main() {  
    std::string s \= "ABC";  
    std::sort(s.begin(), s.end()); // Bắt đầu từ hoán vị nhỏ nhất  
    do {  
        std::cout \<\< s \<\< std::endl;  
    } while (std::next\_permutation(s.begin(), s.end()));  
    return 0;  
}

#### **Tính Tổ Hợp $C\_n^k$ với Số Lớn**

Trong các cuộc thi, bài toán thường yêu cầu tính $C\_n^k$ với $n$ và $k$ có thể rất lớn (ví dụ, lên tới $10^6$), và kết quả phải được lấy phần dư cho một số nguyên tố $M$ (thường là $10^9 \+ 7$). Việc tính trực tiếp $n\!$ sẽ gây tràn số ngay cả với kiểu unsigned long long. Do đó, ta phải thực hiện mọi phép tính trong trường số học modulo.

Công thức $C\_n^k \= \\frac{n\!}{k\!(n-k)\!}$ được biến đổi thành phép nhân modulo:

$$C\_n^k \\equiv n\! \\times (k\!)^{-1} \\times ((n-k)\! )^{-1} \\pmod{M}$$

Trong đó $(a)^{-1}$ là nghịch đảo modulo của $a$. Khi $M$ là một số nguyên tố, ta có thể tìm nghịch đảo modulo bằng Định lý Fermat nhỏ:

$$a^{M-2} \\equiv a^{-1} \\pmod{M}$$

Để tính $a^{M-2} \\pmod{M}$ một cách hiệu quả, ta sử dụng thuật toán Lũy thừa bằng cách bình phương (Binary Exponentiation), giúp giảm độ phức tạp từ $O(M)$ xuống $O(\\log M)$.  
Để tối ưu hơn nữa, ta có thể **tiền tính toán (precompute)** tất cả các giá trị giai thừa và nghịch đảo giai thừa modulo $M$ và lưu vào mảng. Điều này cho phép mỗi truy vấn $C\_n^k$ được trả lời trong thời gian $O(1)$.7

Dưới đây là một bộ code hoàn chỉnh trong C++:

C++

\#**include** \<iostream\>  
\#**include** \<vector\>

const int MOD \= 1e9 \+ 7;  
const int MAXN \= 1e6;

long long fact\[MAXN \+ 1\];  
long long invFact\[MAXN \+ 1\];

// Tính a^b % MOD trong O(log b)  
long long power(long long base, long long exp) {  
    long long res \= 1;  
    base %= MOD;  
    while (exp \> 0) {  
        if (exp % 2 \== 1) res \= (res \* base) % MOD;  
        base \= (base \* base) % MOD;  
        exp /= 2;  
    }  
    return res;  
}

// Tính nghịch đảo modulo của n  
long long modInverse(long long n) {  
    return power(n, MOD \- 2);  
}

// Tiền tính toán giai thừa và nghịch đảo giai thừa  
void precompute() {  
    fact \= 1;  
    invFact \= 1;  
    for (int i \= 1; i \<= MAXN; i++) {  
        fact\[i\] \= (fact\[i \- 1\] \* i) % MOD;  
        invFact\[i\] \= modInverse(fact\[i\]); // Có thể tối ưu hơn bằng cách tính invFact\[MAXN\] rồi tính ngược lại  
    }  
}

// Tính C(n, k) % MOD trong O(1) sau khi tiền tính toán  
long long nCr\_mod\_p(int n, int r) {  
    if (r \< 0 |

| r \> n) return 0;  
    return (((fact\[n\] \* invFact\[r\]) % MOD) \* invFact\[n \- r\]) % MOD;  
}

int main() {  
    precompute();  
    int n \= 10, k \= 5;  
    std::cout \<\< "C(" \<\< n \<\< ", " \<\< k \<\< ") mod " \<\< MOD \<\< " \= " \<\< nCr\_mod\_p(n, k) \<\< std::endl;  
    return 0;  
}

## **Phần II: Giải Mã Quy Hoạch Động \- Từ Nguyên Lý Tới Thực Thi**

Quy hoạch động (Dynamic Programming \- DP) là một trong những kỹ thuật thuật toán mạnh mẽ và phổ biến nhất. Nó không phải là một thuật toán cụ thể, mà là một phương pháp tư duy để giải quyết các bài toán tối ưu hóa và bài toán đếm phức tạp. Hiểu được bản chất của QHĐ là một cột mốc quan trọng trong sự nghiệp của mỗi lập trình viên thi đấu.

### **2.1. Bản Chất Của Quy Hoạch Động: Cấu Trúc Con Tối Ưu và Bài Toán Con Gối Nhau**

Richard Bellman, người đã phát minh ra quy hoạch động vào những năm 1950, đã xác định hai thuộc tính cốt lõi mà một bài toán phải có để có thể giải được bằng phương pháp này.8 Hai thuộc tính này là kim chỉ nam giúp ta nhận diện các bài toán QHĐ.

#### **Cấu trúc con tối ưu (Optimal Substructure)**

Một bài toán được cho là có cấu trúc con tối ưu nếu lời giải tối ưu của bài toán lớn có thể được xây dựng từ (hoặc chứa đựng) lời giải tối ưu của các bài toán con của nó.10

Hãy xem xét một ví dụ trực quan: tìm đường đi ngắn nhất từ thành phố A đến thành phố C. Nếu con đường ngắn nhất đi qua thành phố B, thì đoạn đường từ A đến B trên con đường đó cũng phải là con đường ngắn nhất từ A đến B. Nếu có một con đường khác từ A đến B ngắn hơn, ta có thể thay thế nó vào lộ trình ban đầu để tạo ra một con đường từ A đến C còn ngắn hơn nữa, điều này mâu thuẫn với giả định ban đầu.

Tính chất này cực kỳ quan trọng vì nó cho phép chúng ta xây dựng lời giải một cách đệ quy. Ta có thể giải các bài toán con nhỏ hơn trước, sau đó kết hợp các lời giải tối ưu của chúng để tìm ra lời giải tối ưu cho bài toán lớn hơn.10 Nếu một bài toán không có tính chất này, quy hoạch động không thể được áp dụng.

#### **Bài toán con gối nhau (Overlapping Subproblems)**

Đây là thuộc tính phân biệt quy hoạch động với các phương pháp chia để trị đơn thuần như Merge Sort. Trong khi Merge Sort chia mảng thành các phần hoàn toàn độc lập, quy hoạch động giải quyết các bài toán mà trong đó cùng một bài toán con được gọi đi gọi lại nhiều lần.9

Ví dụ kinh điển nhất là bài toán tính số Fibonacci thứ $n$:  
fib(n) \= fib(n-1) \+ fib(n-2)  
Để tính fib(5), ta cần tính fib(4) và fib(3). Để tính fib(4), ta lại cần fib(3) và fib(2). Có thể thấy, bài toán con fib(3) được gọi hai lần. Với $n$ lớn hơn, số lần gọi lặp lại tăng theo cấp số mũ, khiến cho giải thuật đệ quy đơn thuần trở nên cực kỳ chậm chạp.8  
Quy hoạch động giải quyết vấn đề này một cách triệt để: nó tính mỗi bài toán con đúng một lần và lưu kết quả vào một cấu trúc dữ liệu (thường là mảng hoặc hash map). Những lần sau, khi cần đến kết quả của bài toán con đó, thay vì tính lại, thuật toán chỉ cần tra cứu giá trị đã lưu.10 Kỹ thuật này được gọi là **ghi nhớ (memoization)**.

Tóm lại, quy hoạch động là một kỹ thuật tối ưu hóa cho các bài toán đệ quy có hai đặc điểm: lời giải tối ưu được xây dựng từ lời giải tối ưu của các bài toán con, và các bài toán con đó được sử dụng lặp đi lặp lại.

### **2.2. Hai Chiến Lược Tiếp Cận: Top-Down (Memoization) vs. Bottom-Up (Tabulation)**

Có hai cách chính để triển khai một thuật toán quy hoạch động. Cả hai đều đạt được cùng một mục tiêu là tránh tính toán lại các bài toán con, nhưng chúng khác nhau về cách tiếp cận và có những ưu nhược điểm riêng.13

#### **Top-Down (Đệ quy có nhớ \- Memoization)**

Cách tiếp cận này bắt đầu từ bài toán lớn (top) và đi xuống (down) các bài toán con nhỏ hơn thông qua các lời gọi đệ quy. Nó là một sự cải tiến trực tiếp từ giải thuật đệ quy ban đầu.14

* **Cơ chế hoạt động:** Ta viết một hàm đệ quy như bình thường. Ở đầu hàm, ta thêm một bước kiểm tra: "Bài toán con này đã được giải trước đây chưa?". Nếu câu trả lời là có (kết quả đã được lưu trong bộ nhớ đệm), ta trả về ngay kết quả đó. Nếu chưa, ta tiếp tục tính toán như bình thường, và trước khi trả về, ta lưu kết quả vừa tính được vào bộ nhớ đệm để sử dụng cho các lần gọi sau.10  
* **Ưu điểm:**  
  * **Trực quan và dễ cài đặt:** Code rất gần với công thức truy hồi toán học, giúp việc chuyển từ ý tưởng sang mã nguồn trở nên tự nhiên hơn.13  
  * **Hiệu quả khi không gian bài toán con thưa thớt:** Nó chỉ tính toán các bài toán con thực sự cần thiết để giải bài toán gốc. Nếu có nhiều trạng thái không bao giờ được truy cập, memoization sẽ bỏ qua chúng.15  
* **Nhược điểm:**  
  * **Chi phí đệ quy:** Mỗi lời gọi hàm đều có một chi phí (overhead) nhất định, làm cho nó có thể chậm hơn một chút về hằng số so với phương pháp lặp.13  
  * **Nguy cơ tràn bộ nhớ stack (Stack Overflow):** Nếu cây đệ quy quá sâu (ví dụ, $n$ rất lớn trong bài toán Fibonacci), bộ nhớ dành cho call stack có thể bị cạn kiệt, dẫn đến lỗi chương trình.17

#### **Bottom-Up (Lập bảng \- Tabulation)**

Cách tiếp cận này hoạt động theo hướng ngược lại: từ dưới (bottom) lên (up). Nó bắt đầu bằng cách giải các bài toán con nhỏ nhất (các trường hợp cơ sở), sau đó sử dụng các kết quả này để xây dựng tuần tự lời giải cho các bài toán con lớn dần cho đến khi đạt được bài toán gốc.14

* **Cơ chế hoạt động:** Ta thường sử dụng các vòng lặp lồng nhau để điền vào một bảng (thường là mảng 1D hoặc 2D, gọi là bảng DP). Thứ tự của các vòng lặp phải được thiết kế cẩn thận để đảm bảo rằng khi ta tính giá trị cho ô dp\[i\], tất cả các giá trị dp\[j\] (với $j \< i$) mà dp\[i\] phụ thuộc vào đã được tính toán xong.13  
* **Ưu điểm:**  
  * **Hiệu suất cao:** Không có chi phí của lời gọi đệ quy, thường cho hiệu suất tốt hơn về hằng số.18  
  * **Không có nguy cơ tràn stack:** Vì sử dụng vòng lặp, nó an toàn với các đầu vào lớn.15  
  * **Dễ tối ưu hóa không gian:** Khi tính toán giá trị của hàng (hoặc cột) thứ $i$, ta thường chỉ cần thông tin từ hàng (hoặc cột) $i-1$ và $i-2$. Điều này cho phép ta tối ưu hóa không gian lưu trữ từ $O(N^2)$ xuống $O(N)$ hoặc thậm chí $O(1)$ trong một số trường hợp.18  
* **Nhược điểm:**  
  * **Kém trực quan hơn:** Đôi khi việc xác định đúng thứ tự điền bảng và xử lý các điều kiện biên có thể phức tạp và kém tự nhiên hơn so với việc viết một hàm đệ quy.17  
  * **Tính toán thừa:** Phương pháp này thường tính toán kết quả cho tất cả các bài toán con trong một phạm vi nhất định, ngay cả khi một số trong chúng không cần thiết cho lời giải cuối cùng.17

**Bảng 2: So sánh Top-Down (Memoization) và Bottom-Up (Tabulation)**

| Đặc điểm | Top-down (Memoization) | Bottom-up (Tabulation) |
| :---- | :---- | :---- |
| **Cách tiếp cận** | Đệ quy (Recursive) | Lặp (Iterative) |
| **Thứ tự giải** | Từ bài toán lớn \-\> bài toán con | Từ bài toán con \-\> bài toán lớn |
| **Triển khai** | Dễ, tự nhiên từ công thức truy hồi | Cần xác định thứ tự điền bảng, có thể phức tạp hơn |
| **Hiệu năng** | Chậm hơn một chút (do overhead đệ quy) | Nhanh hơn (không có overhead) |
| **Bộ nhớ** | Tốn bộ nhớ cho stack đệ quy, nguy cơ tràn stack | Không tốn stack, dễ tối ưu hóa không gian bảng DP |
| **Khi nào dùng?** | Cấu trúc đệ quy tự nhiên, không gian bài toán con thưa thớt (sparse), cần sự đơn giản trong code | Cần tối ưu hiệu năng/bộ nhớ, tất cả bài toán con đều cần tính, đầu vào lớn |

### **2.3. Xây Dựng Hàm Mục Tiêu và Công Thức Truy Hồi: Tư Duy Của Lập Trình Viên**

Bước khó khăn và mang tính nghệ thuật nhất trong quy hoạch động là việc xác định đúng trạng thái và công thức truy hồi. Đây là một quá trình tư duy có cấu trúc.

1. **Bước 1: Đặc trưng hóa cấu trúc của lời giải (Định nghĩa trạng thái).**  
   * Trạng thái (state) là một tập hợp các tham số mô tả đầy đủ và duy nhất một bài toán con.19 Việc định nghĩa trạng thái là việc quyết định "cần lưu trữ thông tin gì để có thể đưa ra quyết định cho bước tiếp theo?".  
   * Ví dụ, trong bài toán tìm dãy con tăng dài nhất, một trạng thái hợp lý có thể là dp\[i\]: độ dài của dãy con tăng dài nhất kết thúc tại phần tử thứ $i$.  
2. **Bước 2: Định nghĩa giá trị của lời giải một cách đệ quy (Tìm công thức truy hồi).**  
   * Đây là việc tìm ra mối quan hệ giữa lời giải của một bài toán con và lời giải của các bài toán con nhỏ hơn nó. Câu hỏi cần trả lời là: "Làm thế nào để tính được dp\[i\] dựa trên các giá trị dp\[j\] với $j \< i$?".10  
   * Tiếp tục ví dụ dãy con tăng dài nhất, để tính dp\[i\], ta xét tất cả các phần tử $a\_j$ đứng trước $a\_i$ (tức $j \< i$). Nếu $a\_j \< a\_i$, ta có thể nối dài dãy con tăng kết thúc tại $j$ bằng cách thêm $a\_i$ vào cuối. Do đó, công thức truy hồi là:

     $$dp\[i\] \= 1 \+ \\max(\\{dp\[j\] \\mid 0 \\le j \< i \\text{ và } a\_j \< a\_i\\})$$  
3. **Bước 3: Tính giá trị lời giải (Xác định trường hợp cơ sở và thứ tự tính toán).**  
   * Trường hợp cơ sở là những bài toán con nhỏ nhất mà lời giải của chúng là hiển nhiên, không cần đệ quy. Ví dụ, dp \= 1\.  
   * Dựa trên công thức truy hồi, ta xác định thứ tự tính toán (cho phương pháp Bottom-Up) hoặc các điều kiện dừng của đệ quy (cho phương pháp Top-Down).

Bốn bước tổng quát để giải một bài toán quy hoạch động là:

1. Đặc trưng hóa cấu trúc của lời giải tối ưu.  
2. Định nghĩa giá trị của lời giải tối ưu một cách đệ quy (công thức truy hồi).  
3. Tính toán giá trị của lời giải tối ưu theo kiểu từ dưới lên (Tabulation) hoặc từ trên xuống (Memoization).  
4. (Tùy chọn) Xây dựng lại lời giải tối ưu từ các thông tin đã tính toán (truy vết).10

## **Phần III: Giao Điểm Vàng: Vận Dụng Toán Tổ Hợp Trong Quy Hoạch Động**

Quy hoạch động và toán tổ hợp có một mối quan hệ cộng sinh sâu sắc. Nhiều bài toán đếm trong tổ hợp có thể được giải quyết một cách hiệu quả bằng quy hoạch động, và ngược lại, tư duy tổ hợp là chìa khóa để xây dựng các công thức truy hồi cho các bài toán đếm của QHĐ.

### **3.1. Từ Công Thức Tổ Hợp đến Quy Hoạch Động: Tính C(n, k) Bằng Tam Giác Pascal**

Một ví dụ điển hình và sáng tỏ nhất về mối liên hệ này là việc tính tổ hợp chập $k$ của $n$, $C\_n^k$, bằng quy hoạch động.

Trong toán học, ta có một công thức truy hồi nổi tiếng cho tổ hợp, được gọi là Đồng nhất thức Pascal:

$$C\_n^k \= C\_{n-1}^{k-1} \+ C\_{n-1}^k$$

với các trường hợp cơ sở là $C\_n^0 \= 1$ và $C\_n^n \= 1$.2  
Công thức này có thể được diễn giải một cách tổ hợp như sau: để chọn $k$ người từ một nhóm $n$ người, ta hãy xét một người đặc biệt, gọi là An. Có hai trường hợp xảy ra:

1. **An được chọn:** Ta cần chọn thêm $k-1$ người từ $n-1$ người còn lại. Có $C\_{n-1}^{k-1}$ cách.  
2. **An không được chọn:** Ta cần chọn đủ $k$ người từ $n-1$ người còn lại. Có $C\_{n-1}^k$ cách.

Vì hai trường hợp này rời nhau, theo quy tắc cộng, tổng số cách là $C\_{n-1}^{k-1} \+ C\_{n-1}^k$.

Công thức truy hồi này cho thấy bài toán tính $C\_n^k$ thỏa mãn cả hai điều kiện của quy hoạch động 22:

* **Cấu trúc con tối ưu:** Lời giải cho bài toán $C\_n^k$ được xây dựng trực tiếp từ lời giải của hai bài toán con nhỏ hơn là $C\_{n-1}^{k-1}$ và $C\_{n-1}^k$.  
* **Bài toán con gối nhau:** Khi tính toán bằng đệ quy đơn thuần, nhiều bài toán con (ví dụ $C\_{n-2}^{k-1}$) sẽ được tính lại nhiều lần, dẫn đến độ phức tạp thời gian mũ $O(2^n)$.22

Do đó, ta có thể áp dụng quy hoạch động để giải quyết bài toán này một cách hiệu quả. Ta sử dụng phương pháp Bottom-Up (Tabulation):

* **Trạng thái:** dp\[i\]\[j\] sẽ lưu giá trị của $C\_i^j$.  
* **Công thức chuyển trạng thái:** dp\[i\]\[j\] \= dp\[i-1\]\[j-1\] \+ dp\[i-1\]\[j\].  
* **Trường hợp cơ sở:** dp\[i\] \= 1 và dp\[i\]\[i\] \= 1 với mọi $i$.

Bảng dp được xây dựng theo công thức này chính là **Tam giác Pascal** nổi tiếng.

C++

\#**include** \<iostream\>  
\#**include** \<vector\>

long long combinations(int n, int k) {  
    if (k \< 0 |

| k \> n) {  
        return 0;  
    }  
    std::vector\<std::vector\<long long\>\> dp(n \+ 1, std::vector\<long long\>(k \+ 1, 0));

    for (int i \= 0; i \<= n; \++i) {  
        for (int j \= 0; j \<= std::min(i, k); \++j) {  
            if (j \== 0 |

| j \== i) {  
                dp\[i\]\[j\] \= 1;  
            } else {  
                dp\[i\]\[j\] \= dp\[i \- 1\]\[j \- 1\] \+ dp\[i \- 1\]\[j\];  
            }  
        }  
    }  
    return dp\[n\]\[k\];  
}

int main() {  
    int n \= 5, k \= 2;  
    std::cout \<\< "C(" \<\< n \<\< ", " \<\< k \<\< ") \= " \<\< combinations(n, k) \<\< std::endl; // Output: 10  
    return 0;  
}

Ví dụ này cho thấy một sự thật sâu sắc: quy hoạch động không phải là một khái niệm xa lạ, mà là một cách tiếp cận có hệ thống và thuật toán hóa để giải quyết các hệ thức truy hồi vốn đã tồn tại trong toán tổ hợp. Nhiều bài toán đếm phức tạp có thể được mô hình hóa thành việc tìm một giá trị trong một "tam giác Pascal" tổng quát, và QHĐ là công cụ để xây dựng và tính toán trên tam giác đó.

### **3.2. Tư Duy Tổ Hợp trong Bài Toán Đếm của QHĐ**

Phần lớn các bài toán quy hoạch động thuộc về một trong hai loại: bài toán tối ưu hóa (tìm min/max) hoặc bài toán đếm (đếm số cách).23 Đối với các bài toán đếm, tư duy tổ hợp đóng vai trò trung tâm trong việc xây dựng công thức chuyển trạng thái.

Công thức chuyển trạng thái trong bài toán đếm thường có dạng tổng, phản ánh **Quy tắc cộng** trong tổ hợp: "Nếu một công việc có thể được thực hiện theo $m$ cách hoặc $n$ cách, và hai cách này không trùng lặp, thì có $m+n$ cách để thực hiện công việc đó."

Trong QHĐ, "công việc" là đến được trạng thái hiện tại, và các "cách" là các trạng thái trước đó có thể chuyển đến trạng thái hiện tại.

Ví dụ: Bài toán đếm đường đi trên lưới  
Để đi đến ô $(i, j)$ trên lưới, ta chỉ có thể đến từ ô ngay bên trên là $(i-1, j)$ (bằng một bước đi xuống) hoặc ô ngay bên trái là $(i, j-1)$ (bằng một bước sang phải). Hai cách này là hoàn toàn riêng biệt. Do đó, áp dụng quy tắc cộng:  
Số cách đến $(i, j)$ \= (Số cách đến $(i-1, j)$) \+ (Số cách đến $(i, j-1)$).  
Điều này dẫn trực tiếp đến công thức QHĐ: dp\[i\]\[j\] \= dp\[i-1\]\[j\] \+ dp\[i\]\[j-1\].25  
Tương tự, trong bài toán đếm số cách đổi tiền, số cách để tạo ra tổng $S$ bằng tổng số cách tạo ra $S$ mà không dùng đồng xu $c\_i$ và số cách tạo ra tổng $S-c\_i$ có dùng đồng xu $c\_i$. Tư duy này, dựa trên việc phân chia các trường hợp một cách rời rạc và đầy đủ, là cốt lõi của cả toán tổ hợp và quy hoạch động đếm.

### **3.3. Phân Tích Các Lỗi Sai Kinh Điển: Đếm Thừa và Đếm Thiếu**

Một trong những thách thức lớn nhất khi giải các bài toán đếm bằng QHĐ là đảm bảo rằng mỗi trường hợp hợp lệ được đếm **đúng một lần**—không thừa, không thiếu. Đây là các lỗi rất dễ mắc phải nếu công thức truy hồi không được xây dựng cẩn thận.27

#### **Đếm thừa (Overcounting)**

Đếm thừa xảy ra khi các cách xây dựng khác nhau trong mô hình QHĐ lại dẫn đến cùng một kết quả cuối cùng, và thuật toán lại đếm chúng như những trường hợp riêng biệt.29

Ví dụ kinh điển: Đếm số cách đổi tiền.  
Giả sử ta có các đồng xu {1, 2, 5} và cần tạo tổng 3\.  
Một cách tiếp cận ngây thơ có thể là:  
dp\[i\] \= số cách tạo tổng i.  
dp\[i\] \= sum(dp\[i \- coin\]) cho mọi coin có mệnh giá $\\le i$.

* dp \= dp \= 1 (cách {1})  
* dp \= dp \+ dp \= 1+1=2 (cách {1,1} và {2})  
* dp \= dp \+ dp \+ dp \= 2+1+1=4?  
  Hãy phân tích dp:  
* Từ dp thêm đồng 1: {1,1,1}, {2,1}  
* Từ dp thêm đồng 2: {1,2}  
* Từ dp thêm đồng 3 (không có)  
  Vấn đề là {2,1} và {1,2} là cùng một tổ hợp tiền, nhưng lại được sinh ra từ hai nhánh khác nhau và bị đếm hai lần.

**Cách khắc phục:** Thiết lập một **thứ tự** cho các lựa chọn để phá vỡ tính đối xứng gây ra đếm lặp.

* **Cách 1 (Duyệt theo đồng xu):** Thay vì tính dp\[i\] một lần, ta xây dựng nó qua nhiều bước, mỗi bước tương ứng với việc cho phép sử dụng thêm một loại đồng xu mới.  
  C++  
  dp \= 1;  
  for (int coin : coins) {  
      for (int i \= coin; i \<= S; \++i) {  
          dp\[i\] \+= dp\[i \- coin\];  
      }  
  }

  Vòng lặp ngoài duyệt qua các đồng xu đảm bảo rằng khi ta xét đồng xu c, mọi tổ hợp được tạo ra đều có c là đồng xu có mệnh giá lớn nhất được thêm vào. Ví dụ, tổ hợp {1, 2} sẽ chỉ được tạo ra khi ta xét đồng xu 2 và cộng thêm dp (đã được tạo bởi đồng 1), chứ không bao giờ được tạo ra khi xét đồng 1 và cộng thêm dp.

#### **Đếm thiếu (Undercounting)**

Đếm thiếu xảy ra khi định nghĩa trạng thái hoặc công thức chuyển trạng thái bỏ sót một số trường hợp hợp lệ. Lỗi này thường xuất phát từ việc phân chia trường hợp không đầy đủ hoặc xử lý sai các điều kiện biên.

* **Ví dụ:** Trong bài toán đường đi trên lưới, nếu công thức chỉ là dp\[i\]\[j\] \= dp\[i-1\]\[j\], ta đã bỏ qua hoàn toàn các con đường đi đến từ bên trái.  
* **Cách khắc phục:** Luôn tự hỏi: "Tất cả các cách để đạt được trạng thái hiện tại là gì? Chúng có rời nhau hoàn toàn không?". Sử dụng sơ đồ hoặc vẽ cây đệ quy cho các trường hợp nhỏ có thể giúp phát hiện các trường hợp bị bỏ sót.

## **Phần IV: Các Dạng Bài Quy Hoạch Động Kinh Điển và Nâng Cao**

Phần này sẽ đi sâu vào việc áp dụng các nguyên lý đã thảo luận để giải quyết các lớp bài toán cụ thể, từ những bài toán nền tảng đến các kỹ thuật nâng cao đòi hỏi tư duy phức tạp hơn.

### **4.1. Bài Toán Đếm Tổ Hợp Căn Bản**

#### **Đếm đường đi trên lưới (Grid Path Counting)**

Đây là một trong những bài toán nhập môn QHĐ kinh điển nhất, thể hiện rõ mối liên hệ giữa QHĐ và tổ hợp.

**Bài toán:** Cho một lưới hình chữ nhật kích thước $M \\times N$. Tìm số cách đi từ ô trên cùng bên trái $(0, 0)$ đến ô dưới cùng bên phải $(M-1, N-1)$, biết rằng từ một ô bất kỳ, ta chỉ có thể di chuyển sang phải hoặc đi xuống.

Phân tích bằng Tổ hợp:  
Để đi từ $(0, 0)$ đến $(M-1, N-1)$, ta cần thực hiện tổng cộng $(M-1)$ bước đi xuống và $(N-1)$ bước sang phải. Tổng số bước là $(M-1) \+ (N-1)$. Bài toán trở thành: trong tổng số $(M+N-2)$ bước, ta cần chọn ra $(M-1)$ bước để đi xuống (hoặc $(N-1)$ bước sang phải). Số cách chính là một tổ hợp:

$$\\text{Số cách} \= C\_{M+N-2}^{M-1} \= C\_{M+N-2}^{N-1}$$  
Phân tích bằng Quy hoạch động:  
Phương pháp tổ hợp chỉ hiệu quả khi lưới trống. Khi có các ô cấm, QHĐ trở nên linh hoạt hơn nhiều.25

* **Trạng thái:** dp\[i\]\[j\] là số cách đi từ ô $(0, 0)$ đến ô $(i, j)$.26  
* Công thức chuyển trạng thái: Như đã phân tích, một ô $(i, j)$ chỉ có thể được đến từ ô $(i-1, j)$ hoặc $(i, j-1)$. Do đó:

  $$dp\[i\]\[j\] \= dp\[i-1\]\[j\] \+ dp\[i\]\[j-1\]$$  
* **Trường hợp cơ sở:**  
  * dp \= 1 (có một cách để ở tại điểm xuất phát).  
  * Các ô ở hàng đầu tiên (dp\[j\]) chỉ có thể đến từ bên trái, vậy dp\[j\] \= dp\[j-1\]. Do đó, dp\[j\] \= 1 với mọi $j$.  
  * Tương tự, các ô ở cột đầu tiên (dp\[i\]) chỉ có thể đến từ bên trên, vậy dp\[i\] \= 1 với mọi $i$.  
* **Xử lý vật cản:** Nếu ô $(i, j)$ là vật cản, ta chỉ cần đặt dp\[i\]\[j\] \= 0\.26

C++

\#**include** \<iostream\>  
\#**include** \<vector\>

int uniquePathsWithObstacles(std::vector\<std::vector\<int\>\>& obstacleGrid) {  
    int m \= obstacleGrid.size();  
    if (m \== 0) return 0;  
    int n \= obstacleGrid.size();  
    if (n \== 0) return 0;

    std::vector\<std::vector\<long long\>\> dp(m, std::vector\<long long\>(n, 0));

    if (obstacleGrid \== 1) return 0;  
    dp \= 1;

    for (int i \= 1; i \< m; \++i) {  
        if (obstacleGrid\[i\] \== 0) {  
            dp\[i\] \= dp\[i \- 1\];  
        }  
    }  
    for (int j \= 1; j \< n; \++j) {  
        if (obstacleGrid\[j\] \== 0) {  
            dp\[j\] \= dp\[j \- 1\];  
        }  
    }

    for (int i \= 1; i \< m; \++i) {  
        for (int j \= 1; j \< n; \++j) {  
            if (obstacleGrid\[i\]\[j\] \== 0) {  
                dp\[i\]\[j\] \= dp\[i \- 1\]\[j\] \+ dp\[i\]\[j \- 1\];  
            }  
        }  
    }

    return dp\[m \- 1\]\[n \- 1\];  
}

#### **Bài toán đổi tiền (Coin Change)**

Bài toán này có hai biến thể chính: tối ưu hóa và đếm.

Dạng 1: Tối ưu hóa \- Tìm số đồng xu ít nhất  
Bài toán: Cho một tập các mệnh giá tiền coins \= {c1, c2,..., ck} và một số tiền $S$. Tìm số lượng đồng xu ít nhất để tạo thành tổng $S$. Giả sử mỗi loại mệnh giá có số lượng vô hạn.

* **Trạng thái:** dp\[i\] là số đồng xu ít nhất cần thiết để tạo ra tổng $i$.31  
* Công thức chuyển trạng thái: Để tính dp\[i\], ta có thể tạo ra nó bằng cách lấy một tổng nhỏ hơn $i-c\_j$ và thêm vào một đồng xu có mệnh giá $c\_j$. Ta muốn chọn cách nào cho ra số đồng xu ít nhất.

  $$dp\[i\] \= \\min\_{j=1 \\dots k, c\_j \\le i} (dp\[i \- c\_j\]) \+ 1$$  
* **Trường hợp cơ sở:** dp \= 0 (không cần đồng xu nào để tạo tổng 0). Các giá trị dp khác được khởi tạo là vô cùng.

Dạng 2: Đếm \- Đếm số cách đổi tiền  
Bài toán: Tương tự như trên, nhưng yêu cầu là đếm số cách khác nhau để tạo thành tổng $S$.

* **Trạng thái:** dp\[i\] là số cách khác nhau để tạo ra tổng $i$.21  
* Công thức chuyển trạng thái (đã tối ưu để tránh đếm lặp):  
  $$ \\text{for } c \\in \\text{coins}: \\ \\quad \\text{for } i \\text{ from } c \\text{ to } S: \\ \\qquad dp\[i\] \= dp\[i\] \+ dp\[i-c\] $$  
* **Trường hợp cơ sở:** dp \= 1 (có một cách để tạo tổng 0: không dùng đồng xu nào).

#### **Bài toán chia kẹo Euler (Stars and Bars)**

**Bài toán:** Có bao nhiêu cách chia $n$ cái kẹo giống hệt nhau cho $k$ đứa trẻ?

**Phân tích bằng Tổ hợp:**

* Trường hợp 1: Mỗi đứa trẻ nhận ít nhất 1 cái kẹo.  
  Ta có thể hình dung $n$ cái kẹo xếp thành một hàng, tạo ra $n-1$ khoảng trống ở giữa. Để chia thành $k$ phần, ta cần đặt $k-1$ "vách ngăn" vào $n-1$ khoảng trống đó. Số cách là $C\_{n-1}^{k-1}$.33  
* Trường hợp 2: Có đứa trẻ có thể nhận 0 kẹo.  
  Đây là một mẹo tổ hợp phổ biến. Bài toán tương đương với việc tìm số nghiệm nguyên không âm của phương trình $x\_1 \+ x\_2 \+ \\dots \+ x\_k \= n$. Ta có thể biến đổi nó thành trường hợp 1 bằng cách cho mỗi đứa trẻ "vay" thêm 1 cái kẹo. Bài toán trở thành chia $n+k$ kẹo cho $k$ đứa trẻ sao cho mỗi đứa có ít nhất 1\. Số cách là $C\_{(n+k)-1}^{k-1} \= C\_{n+k-1}^{k-1}$.33

Phân tích bằng Quy hoạch động:  
QHĐ trở nên hữu ích khi có thêm các ràng buộc phức tạp (ví dụ: đứa trẻ thứ $i$ nhận không quá $a\_i$ cái kẹo, hoặc không ít hơn $b\_i$ cái).

* **Trạng thái:** dp\[i\]\[j\] là số cách chia $j$ cái kẹo cho $i$ đứa trẻ đầu tiên.  
* Công thức chuyển trạng thái: Để tính dp\[i\]\[j\], ta xét đứa trẻ thứ $i$. Nó có thể nhận $p$ cái kẹo (với $p$ thỏa mãn ràng buộc). Khi đó, $j-p$ cái kẹo còn lại phải được chia cho $i-1$ đứa trẻ trước đó.

  $$dp\[i\]\[j\] \= \\sum\_{p=0}^{j} dp\[i-1\]\[j-p\]$$

  Công thức này có thể được tối ưu hóa bằng cách nhận ra dp\[i\]\[j\] \= dp\[i\]\[j-1\] \+ dp\[i-1\]\[j\].

### **4.2. Các Dãy Số Tổ Hợp Đặc Biệt: Số Catalan**

Số Catalan là một dãy số nguyên xuất hiện trong lời giải của rất nhiều bài toán đếm trong tổ hợp và khoa học máy tính.

**Các bài toán tương đương:** Số Catalan thứ $n$, ký hiệu $C\_n$, là câu trả lời cho các bài toán sau 35:

* Số cách đặt $n$ cặp ngoặc hợp lệ. Ví dụ $n=3$: ((())), (()()), (())(), ()(()), ()()(). Có 5 cách, $C\_3=5$.  
* Số cây nhị phân đầy đủ có $n+1$ lá (hoặc $n$ nút trong).  
* Số cách chia một đa giác lồi $n+2$ đỉnh thành các tam giác bằng các đường chéo không cắt nhau.  
* Số đường đi trên lưới vuông $n \\times n$ từ $(0,0)$ đến $(n,n)$ chỉ dùng các bước sang phải và đi lên mà không bao giờ đi lên trên đường chéo chính.

**Công thức:**

* Công thức tổ hợp:

  $$C\_n \= \\frac{1}{n+1} C\_{2n}^n \= \\frac{(2n)\!}{(n+1)\!n\!}$$  
* Công thức truy hồi (QHĐ):

  $$C\_0 \= 1 \\quad \\text{và} \\quad C\_{n+1} \= \\sum\_{i=0}^{n} C\_i C\_{n-i} \\quad \\text{với } n \\ge 0$$

  Hoặc viết lại:

  $$C\_n \= \\sum\_{i=0}^{n-1} C\_i C\_{n-1-i} \\quad \\text{với } n \\ge 1$$

  .36

Bản chất của công thức truy hồi:  
Hãy xem xét bài toán đặt ngoặc. Một chuỗi ngoặc hợp lệ không rỗng bất kỳ phải bắt đầu bằng một dấu (. Dấu ( này phải có một dấu ) tương ứng để đóng nó lại. Cấu trúc của chuỗi sẽ có dạng (A)B, trong đó A và B cũng là các chuỗi ngoặc hợp lệ (có thể rỗng).  
Nếu chuỗi (A)B có tổng cộng $n$ cặp ngoặc, và chuỗi A bên trong có $i$ cặp ngoặc ($0 \\le i \\le n-1$), thì chuỗi B bên ngoài sẽ có $n-1-i$ cặp ngoặc.  
Số cách để tạo thành chuỗi A là $C\_i$.  
Số cách để tạo thành chuỗi B là $C\_{n-1-i}$.  
Bằng cách duyệt qua tất cả các khả năng của $i$ từ $0$ đến $n-1$ và áp dụng quy tắc cộng, ta thu được công thức truy hồi của số Catalan. Đây là một ví dụ tuyệt vời về tư duy QHĐ: "phân tách bài toán dựa trên cấu trúc của phần tử đầu tiên và đệ quy trên các phần còn lại."

### **4.3. Kỹ Thuật Nâng Cao 1: Quy Hoạch Động Trạng Thái (Bitmask DP)**

Khi trạng thái của một bài toán con không chỉ phụ thuộc vào các chỉ số như vị trí hay kích thước, mà phụ thuộc vào một **tập hợp** các phần tử đã được sử dụng, ghé thăm, hoặc lựa chọn, chúng ta cần một cách để mã hóa tập hợp đó vào trạng thái QHĐ. Nếu kích thước của tập hợp vũ trụ đủ nhỏ (thường $N \\le 20$), ta có thể sử dụng **Bitmask DP**.38

Ý tưởng cốt lõi:  
Một số nguyên $k$ có thể được xem như một chuỗi nhị phân. Ta có thể dùng chuỗi nhị phân này (gọi là bitmask) để biểu diễn một tập con của tập $\\{0, 1, \\dots, N-1\\}$. Bit thứ $i$ của $k$ bằng 1 có nghĩa là phần tử $i$ có mặt trong tập con, và ngược lại.38  
Ví dụ, với $N=5$, tập con $\\{0, 2, 3\\}$ được biểu diễn bởi chuỗi nhị phân 01101, tương ứng với số nguyên $13$.  
Bài toán kinh điển: Người du lịch (Traveling Salesperson Problem \- TSP)  
Bài toán: Cho $N$ thành phố và ma trận khoảng cách giữa chúng. Tìm chu trình ngắn nhất đi qua mỗi thành phố đúng một lần và quay về điểm xuất phát.

* **Trạng thái:** dp\[mask\]\[u\] là độ dài đường đi ngắn nhất đi qua tất cả các thành phố trong tập hợp được biểu diễn bởi mask, và kết thúc tại thành phố u.38 u phải là một thành phố trong mask.  
* Công thức chuyển trạng thái: Để tính dp\[mask\]\[u\], ta xét thành phố v ngay trước u trong hành trình. Thành phố v phải thuộc tập mask nhưng không phải là u. Đường đi đến v phải đi qua các thành phố trong mask trừ u.

  $$dp\[\\text{mask}\]\[u\] \= \\min\_{v \\in \\text{mask}, v \\ne u} (dp\[\\text{mask} \\setminus \\{u\\}\]\[v\] \+ \\text{dist}(v, u))$$

  Trong đó mask \\ {u} tương ứng với thao tác bit mask ^ (1 \<\< u).  
* **Trường hợp cơ sở:** dp\[1 \<\< i\]\[i\] \= 0 cho mọi $i$ (đường đi bắt đầu từ thành phố $i$, chỉ đi qua chính nó, có độ dài 0).  
* **Kết quả cuối cùng:** $\\min\_{i=0 \\dots N-1} (dp\[(1 \\ll N) \- 1\]\[i\] \+ \\text{dist}(i, \\text{start\_node}))$.

Độ phức tạp của Bitmask DP thường là $O(N^2 \\cdot 2^N)$, phù hợp với $N$ nhỏ. Các thao tác bit cơ bản như AND (&), OR (|), XOR (^), và dịch bit (\<\<, \>\>) là công cụ không thể thiếu để làm việc với kỹ thuật này.40

### **4.4. Kỹ Thuật Nâng Cao 2: Quy Hoạch Động Trên Cây (DP on Trees)**

Đây là kỹ thuật áp dụng QHĐ cho các bài toán trên cấu trúc dữ liệu cây.42 Ý tưởng chính là kết hợp QHĐ với một thuật toán duyệt cây, thường là **Duyệt theo chiều sâu (DFS)**.42

**Ý tưởng cốt lõi:**

1. **Chọn một gốc:** Tùy ý chọn một nút làm gốc của cây (ví dụ, nút 1).  
2. **Duyệt cây (DFS):** Bắt đầu DFS từ gốc.  
3. **Tính toán khi quay lui:** Lời gọi đệ quy DFS sẽ đi xuống các nút con trước. Khi một lời gọi DFS tại nút con v kết thúc và quay trở lại nút cha u, ta đã có đầy đủ thông tin về cây con gốc v. Ta sẽ sử dụng kết quả QHĐ của tất cả các nút con để tính toán kết quả QHĐ cho nút cha u.43

Bài toán kinh điển: Tìm tập hợp độc lập lớn nhất (Maximum Independent Set)  
Bài toán: Trên một cây, một tập hợp độc lập là một tập các đỉnh sao cho không có hai đỉnh nào trong tập kề nhau. Tìm tập hợp độc lập có kích thước lớn nhất.

* **Trạng thái:** Với mỗi nút u, ta cần tính hai giá trị:  
  * dp\[u\]: Kích thước tập độc lập lớn nhất trong cây con gốc u, **có bao gồm** nút u.  
  * dp\[u\]: Kích thước tập độc lập lớn nhất trong cây con gốc u, **không bao gồm** nút u.  
* **Công thức chuyển trạng thái:**  
  * Để tính dp\[u\]: Nếu ta chọn nút u, ta không được phép chọn bất kỳ nút con trực tiếp v nào của nó. Do đó, ta phải lấy tổng kích thước các tập độc lập lớn nhất trong các cây con gốc v mà không chọn v.

    $$dp\[u\] \= 1 \+ \\sum\_{v \\in \\text{children}(u)} dp\[v\]$$  
  * Để tính dp\[u\]: Nếu ta không chọn nút u, ta hoàn toàn tự do trong việc chọn hay không chọn các nút con v của nó. Để tối đa hóa kích thước, với mỗi cây con gốc v, ta sẽ chọn phương án tốt hơn giữa việc chọn v và không chọn v.

    $$dp\[u\] \= \\sum\_{v \\in \\text{children}(u)} \\max(dp\[v\], dp\[v\])$$  
* **Trường hợp cơ sở:** Đối với một nút lá, dp\[leaf\] \= 1 và dp\[leaf\] \= 0\.  
* **Kết quả cuối cùng:** $\\max(dp\[\\text{root}\], dp\[\\text{root}\])$.

### **4.5. Kỹ Thuật Nâng Cao 3: Quy Hoạch Động Chữ Số (Digit DP)**

Digit DP là một kỹ thuật chuyên dụng để giải các bài toán đếm số lượng số nguyên trong một khoảng $$ thỏa mãn một tính chất nhất định liên quan đến các chữ số của chúng.45

**Ý tưởng cốt lõi:**

1. **Quy về một đầu:** Thay vì đếm trong khoảng $$, ta tính count(R) \- count(L-1), trong đó count(X) là hàm đếm số lượng số từ $0$ đến $X$ thỏa mãn tính chất.  
2. **Xây dựng số từ trái sang phải:** Hàm count(X) sẽ được cài đặt bằng đệ quy có nhớ. Ta xây dựng các số hợp lệ có số chữ số không vượt quá $X$ bằng cách điền từng chữ số từ trái sang phải (từ hàng cao nhất đến hàng đơn vị).  
3. **Ràng buộc (Tight Constraint):** Đây là khái niệm trung tâm của Digit DP. Khi ta đang xây dựng một số, tại vị trí chữ số thứ idx, ta có bị giới hạn bởi chữ số tương ứng của $X$ hay không?  
   * **Trạng thái tight \= true:** Nghĩa là tiền tố ta đã xây dựng cho đến nay giống hệt tiền tố của $X$. Do đó, chữ số tiếp theo ta có thể điền chỉ được phép chạy từ $0$ đến X\[idx\]. Nếu ta điền một chữ số nhỏ hơn X\[idx\], trạng thái tight cho bước tiếp theo sẽ trở thành false.  
   * **Trạng thái tight \= false:** Nghĩa là tiền tố ta đã xây dựng đã nhỏ hơn tiền tố của $X$. Do đó, ta hoàn toàn tự do điền chữ số tiếp theo từ $0$ đến $9$ mà vẫn đảm bảo số cuối cùng nhỏ hơn $X$.  
* **Trạng thái QHĐ:** Một hàm Digit DP thường có dạng solve(idx, tight,...features).45  
  * idx: Vị trí chữ số đang xét.  
  * tight: Biến boolean cho biết có bị ràng buộc hay không.  
  * features...: Các tham số bổ sung cần thiết để kiểm tra điều kiện của bài toán, ví dụ: sum (tổng các chữ số đã điền), is\_started (để xử lý các số 0 ở đầu), v.v.  
* **Cài đặt:** Thường được cài đặt bằng phương pháp Top-Down (Memoization) vì tính tự nhiên của nó. Mảng dp sẽ lưu kết quả cho các trạng thái (idx,...features). Lưu ý rằng ta chỉ có thể tái sử dụng kết quả đã lưu khi tight \= false, vì khi tight \= true, giới hạn trên phụ thuộc vào các chữ số cụ thể của $X$, làm cho bài toán con không hoàn toàn giống nhau.

## **Phần V: Tổng Kết và Lộ Trình Luyện Tập Chuyên Sâu**

Báo cáo này đã trình bày một hành trình toàn diện từ các khái niệm cơ bản của Toán Tổ Hợp đến các kỹ thuật nâng cao của Quy hoạch động, với trọng tâm là mối liên hệ mật thiết giữa hai lĩnh vực này trong bối cảnh lập trình thi đấu.

**Những điểm cốt lõi cần ghi nhớ:**

1. **Tổ hợp là nền tảng:** Việc phân biệt rõ ràng giữa Hoán vị, Chỉnh hợp và Tổ hợp dựa trên vai trò của "thứ tự" là kỹ năng tư duy tiên quyết để mô hình hóa chính xác các bài toán đếm.  
2. **QHĐ là thuật toán hóa các hệ thức truy hồi:** Bản chất của QHĐ nằm ở việc nhận diện và giải quyết hiệu quả các bài toán có "cấu trúc con tối ưu" và "bài toán con gối nhau". Nhiều hệ thức truy hồi trong toán tổ hợp (như Đồng nhất thức Pascal, công thức số Catalan) chính là các công thức chuyển trạng thái của QHĐ.  
3. **Tư duy tổ hợp trong QHĐ đếm:** Quy tắc cộng và quy tắc nhân là nền tảng để xây dựng công thức chuyển trạng thái cho các bài toán đếm. Việc phân chia bài toán thành các trường hợp con rời rạc và đầy đủ là chìa khóa để tránh các lỗi đếm thừa và đếm thiếu.  
4. **Lựa chọn công cụ phù hợp:** Từ các bài toán cơ bản như đếm đường đi, đổi tiền, đến các kỹ thuật nâng cao như Bitmask DP, DP trên cây, và Digit DP, mỗi loại bài toán có một cấu trúc trạng thái và cách tiếp cận đặc thù. Việc nhận diện đúng dạng bài và áp dụng đúng kỹ thuật là yếu tố quyết định thành công.

Lộ trình luyện tập chuyên sâu:  
Để thực sự thành thạo, việc luyện tập có hệ thống là không thể thiếu. Dưới đây là một lộ trình gợi ý:

1. **Giai đoạn 1: Nắm vững cơ bản**  
   * **Chủ đề:** Các bài toán QHĐ cơ bản trên mảng 1D và 2D.  
   * **Bài tập:** Dãy con tăng dài nhất (LIS), Dãy con chung dài nhất (LCS), Bài toán cái túi (Knapsack 0/1, Unbounded Knapsack), Đếm đường đi trên lưới, Đổi tiền (cả hai dạng).  
   * **Nền tảng:** VNOJ, CSES Problem Set (phần Dynamic Programming), LeetCode.  
2. **Giai đoạn 2: Kết hợp Tổ hợp và QHĐ**  
   * **Chủ đề:** Các bài toán đếm sử dụng QHĐ, các dãy số đặc biệt.  
   * **Bài tập:** Tính $C\_n^k$ bằng QHĐ, Bài toán chia kẹo có ràng buộc, các bài toán liên quan đến số Catalan (dãy ngoặc, đường đi Dyck).  
   * **Nền tảng:** Codeforces (các bài Div. 2 C/D, Div. 3 D/E), AtCoder DP Contest.  
3. **Giai đoạn 3: Chinh phục các kỹ thuật nâng cao**  
   * **Chủ đề:** Lần lượt đi sâu vào từng kỹ thuật: Bitmask DP, DP trên cây, Digit DP.  
   * **Bài tập:**  
     * **Bitmask DP:** Bắt đầu với TSP, sau đó là các bài toán gán ghép, phủ tập hợp trên Codeforces, AtCoder.  
     * **DP trên cây:** Bắt đầu với các bài toán cơ bản như tìm đường đi dài nhất, tập độc lập lớn nhất trên VNOI, CSES.  
     * **Digit DP:** Luyện tập các bài toán đếm số trong khoảng trên SPOJ, Codeforces.  
   * **Nền tảng:** VNOI Wiki (có danh sách bài tập cho từng chuyên đề), các contest trên Codeforces và AtCoder.

Việc hiểu sâu bản chất toán học đằng sau mỗi thuật toán sẽ giúp bạn không chỉ giải được các bài toán đã biết mà còn có khả năng sáng tạo ra lời giải cho những vấn đề mới. Hãy kiên trì, thực hành thường xuyên, và luôn cố gắng phân tích bài toán từ những nguyên lý cơ bản nhất.

#### **Nguồn trích dẫn**

1. Hoán vị, chỉnh hợp và tổ hợp lớp 10 (Lý thuyết Toán 10 Kết nối tri ..., truy cập vào tháng 10 29, 2025, [https://vietjack.com/toan-10-kn/ly-thuyet-bai-24-hoan-vi-chinh-hop-va-to-hop.jsp](https://vietjack.com/toan-10-kn/ly-thuyet-bai-24-hoan-vi-chinh-hop-va-to-hop.jsp)  
2. Lý thuyết Hoán vị \- Chỉnh hợp \- Tổ hợp | SGK Toán lớp 11 \- Loigiaihay.com, truy cập vào tháng 10 29, 2025, [https://loigiaihay.com/ly-thuyet-hoan-vi-chinh-hop-to-hop-c46a4081.html](https://loigiaihay.com/ly-thuyet-hoan-vi-chinh-hop-to-hop-c46a4081.html)  
3. Hoán vị, chỉnh hợp và tổ hợp lớp 10 (Lý thuyết Toán 10 Chân trời sáng tạo) \- VietJack, truy cập vào tháng 10 29, 2025, [https://vietjack.com/toan-10-ct/ly-thuyet-bai-2-hoan-vi-chinh-hop-va-to-hop.jsp](https://vietjack.com/toan-10-ct/ly-thuyet-bai-2-hoan-vi-chinh-hop-va-to-hop.jsp)  
4. Hoán Vị \- Chỉnh Hợp \- Tổ Hợp: Công Thức Và Bài Tập \- Vuihoc.vn, truy cập vào tháng 10 29, 2025, [https://vuihoc.vn/tin/thpt-hoan-vi-chinh-hop-to-hop-505.html](https://vuihoc.vn/tin/thpt-hoan-vi-chinh-hop-to-hop-505.html)  
5. \[Kiến Thức Toán 11\] Phân Biệt Chỉnh Hợp Và Tổ Hợp Dễ Hiểu \- Timviec365, truy cập vào tháng 10 29, 2025, [https://timviec365.vn/blog/chinh-hop-va-to-hop-new14350.html](https://timviec365.vn/blog/chinh-hop-va-to-hop-new14350.html)  
6. QBHV \- Hoán vị chữ cái \- VietCodes, truy cập vào tháng 10 29, 2025, [https://vietcodes.github.io/code/59/](https://vietcodes.github.io/code/59/)  
7. Cách tính nCk | VNOI Wiki, truy cập vào tháng 10 29, 2025, [https://wiki.vnoi.info/algo/algebra/nCk](https://wiki.vnoi.info/algo/algebra/nCk)  
8. Nhập môn Quy hoạch động \- Viblo, truy cập vào tháng 10 29, 2025, [https://viblo.asia/p/nhap-mon-quy-hoach-dong-bWrZnoRQlxw](https://viblo.asia/p/nhap-mon-quy-hoach-dong-bWrZnoRQlxw)  
9. Bài 1.5. Quy hoạch động | PDF \- Scribd, truy cập vào tháng 10 29, 2025, [https://www.scribd.com/document/931103593/Bai-1-5-Quy-ho%E1%BA%A1ch-%C4%91%E1%BB%99ng](https://www.scribd.com/document/931103593/Bai-1-5-Quy-ho%E1%BA%A1ch-%C4%91%E1%BB%99ng)  
10. Quy hoạch động là gì? Tìm hiểu chi tiết về thuật toán ... \- FPT Aptech, truy cập vào tháng 10 29, 2025, [https://aptech.fpt.edu.vn/quy-hoach-dong.html](https://aptech.fpt.edu.vn/quy-hoach-dong.html)  
11. Quy Hoạch Động \- Một Thuật Toán Thần Thánh \- Viblo, truy cập vào tháng 10 29, 2025, [https://viblo.asia/p/quy-hoach-dong-mot-thuat-toan-than-thanh-E375zy01lGW](https://viblo.asia/p/quy-hoach-dong-mot-thuat-toan-than-thanh-E375zy01lGW)  
12. Quy hoạch động cho người mới bắt đầu (Phần 3\) \- Sử dụng vòng lặp for truy vết, truy cập vào tháng 10 29, 2025, [https://codedream.edu.vn/quy-hoach-dong-cho-nguoi-moi-bat-dau-phan-3/](https://codedream.edu.vn/quy-hoach-dong-cho-nguoi-moi-bat-dau-phan-3/)  
13. Top-down (Memoization) vs Bottom-up (Tabulation) approach in DP, truy cập vào tháng 10 29, 2025, [https://www.enjoyalgorithms.com/blog/top-down-memoization-vs-bottom-up-tabulation/](https://www.enjoyalgorithms.com/blog/top-down-memoization-vs-bottom-up-tabulation/)  
14. Basics of Memoization and Tabulation | by Rajat Sharma | The Pythoneers | Medium, truy cập vào tháng 10 29, 2025, [https://medium.com/pythoneers/basics-of-memoization-and-tabulation-fd987be7ecdd](https://medium.com/pythoneers/basics-of-memoization-and-tabulation-fd987be7ecdd)  
15. When to Use Memoization vs Tabulation: A Comprehensive Guide – AlgoCademy Blog, truy cập vào tháng 10 29, 2025, [https://algocademy.com/blog/when-to-use-memoization-vs-tabulation-a-comprehensive-guide/](https://algocademy.com/blog/when-to-use-memoization-vs-tabulation-a-comprehensive-guide/)  
16. dynamic programming \- What is the difference between bottom-up and top-down?, truy cập vào tháng 10 29, 2025, [https://stackoverflow.com/questions/6164629/what-is-the-difference-between-bottom-up-and-top-down](https://stackoverflow.com/questions/6164629/what-is-the-difference-between-bottom-up-and-top-down)  
17. Tabulation vs. Memoization | Baeldung on Computer Science, truy cập vào tháng 10 29, 2025, [https://www.baeldung.com/cs/tabulation-vs-memoization](https://www.baeldung.com/cs/tabulation-vs-memoization)  
18. When to use bottom up DP and top down DP? : r/leetcode \- Reddit, truy cập vào tháng 10 29, 2025, [https://www.reddit.com/r/leetcode/comments/164tz2c/when\_to\_use\_bottom\_up\_dp\_and\_top\_down\_dp/](https://www.reddit.com/r/leetcode/comments/164tz2c/when_to_use_bottom_up_dp_and_top_down_dp/)  
19. Quy hoạch động Bitmask \- Viblo, truy cập vào tháng 10 29, 2025, [https://viblo.asia/p/quy-hoach-dong-bitmask-Yym40r85L91](https://viblo.asia/p/quy-hoach-dong-bitmask-Yym40r85L91)  
20. Nhập môn quy hoạch động \- VNOJ: VNOI Online Judge, truy cập vào tháng 10 29, 2025, [https://csp.vnoi.info/post/22-nmdc](https://csp.vnoi.info/post/22-nmdc)  
21. Đề tài Bài toán đổi tiền (Quy hoạch động) \- Luận văn, đồ án, đề tài ..., truy cập vào tháng 10 29, 2025, [https://luanvan.net.vn/luan-van/de-tai-bai-toan-doi-tien-quy-hoach-dong-29357/](https://luanvan.net.vn/luan-van/de-tai-bai-toan-doi-tien-quy-hoach-dong-29357/)  
22. Tính toán tổ hợp – HỌC, HỌC NỮA, HỌC MÃI\!, truy cập vào tháng 10 29, 2025, [https://hayashikita.wordpress.com/2012/04/02/tinh-toan-t%E1%BB%95-h%E1%BB%A3p/](https://hayashikita.wordpress.com/2012/04/02/tinh-toan-t%E1%BB%95-h%E1%BB%A3p/)  
23. Quy hoạch động (Dynamic programming) \- Vallicon, truy cập vào tháng 10 29, 2025, [https://vallicon.com/post/quy-ho%E1%BA%A1ch-%C4%91%E1%BB%99ng-(dynamic-programming)-bAPoYM6ELm6](https://vallicon.com/post/quy-ho%E1%BA%A1ch-%C4%91%E1%BB%99ng-\(dynamic-programming\)-bAPoYM6ELm6)  
24. Types of Problems Solved Using Dynamic Programming \- EnjoyAlgorithms, truy cập vào tháng 10 29, 2025, [https://www.enjoyalgorithms.com/blog/what-common-problems-solved-using-dynamic-programming/](https://www.enjoyalgorithms.com/blog/what-common-problems-solved-using-dynamic-programming/)  
25. www.iarcs.org.in, truy cập vào tháng 10 29, 2025, [https://www.iarcs.org.in/inoi/online-study-material/topics/dp-grid-paths.php](https://www.iarcs.org.in/inoi/online-study-material/topics/dp-grid-paths.php)  
26. Paths on Grids \- USACO Guide, truy cập vào tháng 10 29, 2025, [https://usaco.guide/gold/paths-grids](https://usaco.guide/gold/paths-grids)  
27. Common Errors in Counting Problems \- ResearchGate, truy cập vào tháng 10 29, 2025, [https://www.researchgate.net/publication/348334635\_Common\_Errors\_in\_Counting\_Problems](https://www.researchgate.net/publication/348334635_Common_Errors_in_Counting_Problems)  
28. dynamic programming task / counting problem \- Stack Overflow, truy cập vào tháng 10 29, 2025, [https://stackoverflow.com/questions/18110870/dynamic-programming-task-counting-problem](https://stackoverflow.com/questions/18110870/dynamic-programming-task-counting-problem)  
29. Can counting problems have optimal substructure? \- Computer Science Stack Exchange, truy cập vào tháng 10 29, 2025, [https://cs.stackexchange.com/questions/79664/can-counting-problems-have-optimal-substructure](https://cs.stackexchange.com/questions/79664/can-counting-problems-have-optimal-substructure)  
30. Dynamic Programming (DP) on Grids \- GeeksforGeeks, truy cập vào tháng 10 29, 2025, [https://www.geeksforgeeks.org/competitive-programming/dp-on-grids/](https://www.geeksforgeeks.org/competitive-programming/dp-on-grids/)  
31. Một số bài toán quy hoạch động điển hình \- VNOI Wiki, truy cập vào tháng 10 29, 2025, [https://wiki.vnoi.info/algo/dp/basic-problems](https://wiki.vnoi.info/algo/dp/basic-problems)  
32. Coin Change \- Count Ways to Make Sum \- GeeksforGeeks, truy cập vào tháng 10 29, 2025, [https://www.geeksforgeeks.org/coin-change-dp-7/](https://www.geeksforgeeks.org/coin-change-dp-7/)  
33. Bài Toán Chia Kẹo Euler \- BITEXEDU, truy cập vào tháng 10 29, 2025, [https://giaoduc.bitexedu.com/thpt/tai-lieu-thpt/toan-thpt/toan-lop-10/bai-toan-chia-keo-euler/](https://giaoduc.bitexedu.com/thpt/tai-lieu-thpt/toan-thpt/toan-lop-10/bai-toan-chia-keo-euler/)  
34. Bài toán chia kẹo euler và ứng dụng | Học toán online chất lượng cao 2025 \- Vted, truy cập vào tháng 10 29, 2025, [https://vted.vn/tin-tuc/bai-toan-chia-keo-euler-va-ung-dung-4529.html](https://vted.vn/tin-tuc/bai-toan-chia-keo-euler-va-ung-dung-4529.html)  
35. Một số dãy số đặc biệt (Fibonacci, Catalan, Euler) \- Viblo, truy cập vào tháng 10 29, 2025, [https://viblo.asia/p/mot-so-day-so-dac-biet-fibonacci-catalan-euler-Az45bq6qlxY](https://viblo.asia/p/mot-so-day-so-dac-biet-fibonacci-catalan-euler-Az45bq6qlxY)  
36. Số Catalan – Wikipedia tiếng Việt, truy cập vào tháng 10 29, 2025, [https://vi.wikipedia.org/wiki/S%E1%BB%91\_Catalan](https://vi.wikipedia.org/wiki/S%E1%BB%91_Catalan)  
37. Các kiến thức cơ bản về Tổ hợp (Combinatorics) \- VNOI Wiki, truy cập vào tháng 10 29, 2025, [https://wiki.vnoi.info/translate/he/Number-Theory-5](https://wiki.vnoi.info/translate/he/Number-Theory-5)  
38. Quy hoạch động bitmask | VNOI Wiki, truy cập vào tháng 10 29, 2025, [https://wiki.vnoi.info/algo/dp/dp-bitmask](https://wiki.vnoi.info/algo/dp/dp-bitmask)  
39. Quy hoạch động bitmask và bài toán lát gạch \- YouTube, truy cập vào tháng 10 29, 2025, [https://www.youtube.com/watch?v=\_L\_Nh8sH8XE](https://www.youtube.com/watch?v=_L_Nh8sH8XE)  
40. SOS DP: Giải Mã Quy Hoạch Động Trên Tập Con \- Viblo, truy cập vào tháng 10 29, 2025, [https://viblo.asia/p/sos-dp-giai-ma-quy-hoach-dong-tren-tap-con-pgjLNge8V32](https://viblo.asia/p/sos-dp-giai-ma-quy-hoach-dong-tren-tap-con-pgjLNge8V32)  
41. Quy hoạch động bitmask Phần 1/2 \- Code Dream, truy cập vào tháng 10 29, 2025, [https://codedream.edu.vn/bitmask\_1/](https://codedream.edu.vn/bitmask_1/)  
42. Quy hoạch động trên cây \- Viblo, truy cập vào tháng 10 29, 2025, [https://viblo.asia/p/quy-hoach-dong-tren-cay-LzD5d9B4KjY](https://viblo.asia/p/quy-hoach-dong-tren-cay-LzD5d9B4KjY)  
43. Các thuật toán cây (Tree algorithms) \- Vallicon, truy cập vào tháng 10 29, 2025, [https://vallicon.com/post/c%C3%A1c-thu%E1%BA%ADt-to%C3%A1n-c%C3%A2y-(tree-algorithms)-jP9RE8RpaLQ](https://vallicon.com/post/c%C3%A1c-thu%E1%BA%ADt-to%C3%A1n-c%C3%A2y-\(tree-algorithms\)-jP9RE8RpaLQ)  
44. Quy hoạch động trên cây \- Code Dream, truy cập vào tháng 10 29, 2025, [https://codedream.edu.vn/quy-hoach-dong-tren-cay/](https://codedream.edu.vn/quy-hoach-dong-tren-cay/)  
45. Quy hoạch động chữ số | VNOI Wiki, truy cập vào tháng 10 29, 2025, [https://wiki.vnoi.info/algo/dp/digit-dp](https://wiki.vnoi.info/algo/dp/digit-dp)
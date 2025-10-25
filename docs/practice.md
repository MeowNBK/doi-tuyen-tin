
# **Cẩm Nang Thuật Toán Lập Trình Thi Đấu Dành Cho Đội Tuyển Tin Học 9 (C++)**

## **Phần I: Nền Tảng Tư Duy Thuật Toán và Chiến Lược Giải Quyết Vấn Đề**

### **1.1. Giới thiệu về Lập trình Thi đấu (Competitive Programming)**

Lập trình thi đấu, hay lập trình thể thao, là một môn thể thao trí tuệ trong đó người tham gia giải quyết các bài toán có tính logic hoặc toán học bằng cách viết các chương trình máy tính. Không giống như lập trình ứng dụng trong thực tế, nơi các dự án có thể kéo dài hàng tháng với các đội ngũ lớn, lập trình thi đấu tập trung vào việc tạo ra các lời giải chính xác và hiệu quả cho các vấn đề được định nghĩa rõ ràng trong một môi trường có ràng buộc chặt chẽ về thời gian thực thi và bộ nhớ sử dụng.1

Các cuộc thi thường được đánh giá tự động bởi một hệ thống máy chủ, gọi là "judge". Một lời giải chỉ được coi là "Accepted" (chấp nhận) khi nó vượt qua tất cả các bộ thử (test cases) ẩn của ban tổ chức. Do đó, việc hiểu sâu về bản chất thuật toán và hiệu quả của chúng là yếu tố quyết định thành công.

### **1.2. Phân tích Độ phức tạp Thuật toán (Big O): Chìa khóa để lựa chọn lời giải**

Trong lập trình thi đấu, các giới hạn (constraints) của bài toán, chẳng hạn như giới hạn về kích thước đầu vào $N$, không phải là những con số ngẫu nhiên. Chúng là một hình thức "giao tiếp" của người ra đề, nhằm định hướng thí sinh đến một lớp thuật toán có độ phức tạp phù hợp. Một máy tính thông thường có thể thực hiện khoảng $10^8$ phép tính trong một giây.3 Do đó, việc phân tích độ phức tạp giúp ta loại bỏ ngay lập tức những hướng đi không khả thi.

Ví dụ, nếu một bài toán có giới hạn $N \\le 10^5$, một thuật toán có độ phức tạp $O(N^2)$ sẽ yêu cầu khoảng $(10^5)^2 \= 10^{10}$ phép tính, chắc chắn sẽ dẫn đến lỗi "Time Limit Exceeded" (TLE). Trong trường hợp này, lời giải phải có độ phức tạp tốt hơn, chẳng hạn như $O(N \\log N)$ hoặc $O(N)$.2

Việc hình thành phản xạ "đọc" giới hạn và liên kết nó với độ phức tạp thuật toán là một kỹ năng meta quan trọng hàng đầu. Khi nhận một bài toán, một lập trình viên có kinh nghiệm sẽ nhìn vào giới hạn của $N$ trước tiên.

* Nếu $N \\le 20$, họ sẽ nghĩ đến các thuật toán có độ phức tạp hàm mũ như duyệt toàn bộ, quay lui, hoặc quy hoạch động bitmask ($O(2^N \\cdot N^k)$).  
* Nếu $N \\le 1000$, độ phức tạp $O(N^2)$ có thể được chấp nhận.  
* Nếu $N \\le 10^5$, họ sẽ hướng đến các thuật toán $O(N \\log N)$ hoặc $O(N)$.  
* Nếu $N$ rất lớn, ví dụ $N \\le 10^9$ hoặc $10^{18}$, lời giải gần như chắc chắn phải có độ phức tạp $O(\\log N)$, $O(\\sqrt{N})$ hoặc $O(1)$.

Bảng dưới đây cung cấp một công cụ tra cứu nhanh để hình thành tư duy này.

**Bảng 1: Lựa chọn Thuật Toán Dựa Trên Giới Hạn (Constraints)**

| Giới hạn (N) | Độ phức tạp khả thi | Lớp thuật toán gợi ý |
| :---- | :---- | :---- |
| $N \\le 10-12$ | $O(N\!)$, $O(N \\cdot 2^N)$ | Duyệt hoán vị, Quay lui cơ bản |
| $N \\le 20-22$ | $O(2^N)$, $O(2^N \\cdot N^k)$ | Quy hoạch động Bitmask, Chia đôi tập (Meet-in-the-middle) |
| $N \\le 100$ | $O(N^4)$, $O(N^3)$ | Floyd-Warshall, DP 3 chiều cơ bản |
| $N \\le 2,000$ | $O(N^2)$ | DP 2 chiều, các thuật toán sắp xếp cơ bản, duyệt cặp |
| $N \\le 10^5$ | $O(N \\log N)$ | Sắp xếp hiệu quả, Tìm kiếm nhị phân, Chia để trị, Cây cấu trúc (Segment Tree, BIT), Dijkstra với heap |
| $N \\le 10^6$ | $O(N)$, $O(N \\alpha(N))$ | BFS/DFS, Hai con trỏ, Sàng số, DSU, KMP |
| $N \> 10^9$ | $O(\\log N)$, $O(\\sqrt{N})$ | Tìm kiếm nhị phân, Lũy thừa nhị phân, các thuật toán số học |

### **1.3. Các Mô Hình Giải Quyết Vấn Đề (Problem-Solving Paradigms)**

Việc nhận diện các "pattern" (mô hình) giải quyết vấn đề là kỹ năng cốt lõi giúp định hướng lời giải một cách nhanh chóng.4 Các mô hình nền tảng bao gồm 6:

* **Duyệt toàn bộ / Quay lui:** Khi cần thử tất cả các khả năng hoặc liệt kê mọi cấu hình, thường với $N$ rất nhỏ.  
* **Tham lam (Greedy):** Khi bài toán có thể được giải quyết bằng cách đưa ra các lựa chọn "tốt nhất" ở mỗi bước.  
* **Chia để trị (Divide and Conquer):** Khi bài toán có thể được chia thành các bài toán con độc lập.  
* **Quy hoạch động (Dynamic Programming):** Khi bài toán có các bài toán con gối nhau và cấu trúc con tối ưu.  
* **Tìm kiếm trên đồ thị (Graph Traversal):** Khi bài toán có thể được mô hình hóa dưới dạng các đỉnh và cạnh, ví dụ như tìm đường đi ngắn nhất trên lưới (BFS).7

Các mô hình này không hoàn toàn độc lập. Một bài toán tối ưu có thể được giải bằng quy hoạch động, nhưng cũng có thể tồn tại một lời giải tham lam đúng đắn và hiệu quả hơn. Hiểu được sự khác biệt tinh tế giữa chúng—chẳng hạn, thuật toán tham lam đưa ra quyết định cục bộ và không bao giờ xem xét lại, trong khi quy hoạch động xây dựng lời giải tối ưu dựa trên các bài toán con đã được giải quyết—là chìa khóa để nâng cao trình độ.8

## **Phần II: Các Kỹ Thuật Lập Trình Cốt Lõi**

### **2.1. Duyệt Toàn Bộ (Brute Force / Complete Search)**

**Bản chất:** Đây là phương pháp thử tất cả các khả năng có thể để tìm ra đáp án.7 Mặc dù thường không phải là lời giải tối ưu nhất, duyệt toàn bộ là phương pháp đầu tiên cần nghĩ đến. Nó cực kỳ hữu ích để giải các bài toán con (subtasks) có giới hạn nhỏ và để kiểm tra tính đúng đắn của các thuật toán phức tạp hơn mà bạn nghĩ ra.5

**Hướng dẫn giải:** Các kỹ thuật sinh cấu hình tổ hợp thường được sử dụng bao gồm:

* **Sinh hoán vị:** Sử dụng hàm next\_permutation trong thư viện \<algorithm\> của C++ để duyệt qua tất cả các hoán vị của một dãy.  
* **Sinh tập con:** Có thể dùng đệ quy hoặc kỹ thuật bitmask. Với một tập hợp $N$ phần tử, ta có thể duyệt qua các số từ $0$ đến $2^N \- 1$. Mỗi số này biểu diễn một tập con: nếu bit thứ $i$ trong số đó là 1, phần tử thứ $i$ được chọn vào tập con.

### **2.2. Đệ Quy và Quay Lui (Recursion & Backtracking)**

**Bản chất:** Đệ quy là một kỹ thuật lập trình trong đó một hàm tự gọi chính nó để giải quyết một bài toán con có cấu trúc tương tự nhưng với kích thước nhỏ hơn.11 Quay lui (Backtracking) là một dạng đệ quy có hệ thống, được sử dụng để khám phá không gian trạng thái của một bài toán, đặc biệt hiệu quả cho các bài toán liệt kê tất cả các cấu hình hoặc tìm kiếm một cấu hình tối ưu.11

Hướng dẫn giải:  
Tư tưởng cốt lõi của quay lui là "thử và hoàn tác". Tại mỗi bước, ta thử một lựa chọn khả thi. Sau khi lời gọi đệ quy cho lựa chọn đó kết thúc (dù tìm ra lời giải hay đi vào ngõ cụt), ta phải "hoàn tác" lại lựa chọn đó để thử các khả năng khác.

1. **Xác định trạng thái:** Các tham số của hàm đệ quy (ví dụ: Try(i) để xây dựng phần tử thứ $i$ của cấu hình).  
2. **Xác định trường hợp cơ sở:** Điều kiện dừng của đệ quy (ví dụ: khi đã xây dựng đủ $N$ phần tử).  
3. **Xác định bước chuyển:** Vòng lặp để thử các giá trị cho phần tử hiện tại và gọi đệ quy cho phần tử tiếp theo.

**Ví dụ kinh điển:** Bài toán N-Hậu (xếp $N$ quân hậu trên bàn cờ $N \\times N$ sao cho không có hai quân nào ăn nhau) là một ví dụ điển hình của thuật toán quay lui.11

### **2.3. Thuật Toán Tham Lam (Greedy Algorithms)**

**Bản chất:** Tại mỗi bước của thuật toán, ta đưa ra một lựa chọn có vẻ là tốt nhất ở thời điểm hiện tại (tối ưu cục bộ), với hy vọng rằng một chuỗi các lựa chọn như vậy sẽ dẫn đến một giải pháp tối ưu toàn cục.8

**Hướng dẫn giải:**

1. **Xác định "lựa chọn tham lam" (Greedy Choice):** Đây là tiêu chí để đưa ra quyết định ở mỗi bước. Ví dụ: chọn công việc kết thúc sớm nhất, chọn vật phẩm có tỷ lệ giá trị/trọng lượng cao nhất.  
2. **Chứng minh tính đúng đắn:** Đây là bước khó nhất và quan trọng nhất. Một thuật toán tham lam trông "có vẻ đúng" có thể dễ dàng thất bại ở các trường hợp đặc biệt. Một kỹ thuật chứng minh phổ biến là "lập luận thay thế" (exchange argument): giả sử tồn tại một lời giải tối ưu không tuân theo lựa chọn tham lam ở bước đầu tiên. Sau đó, chứng minh rằng ta có thể thay thế lựa chọn đó bằng lựa chọn tham lam mà không làm kết quả tệ đi, từ đó dẫn đến một lời giải tối ưu mới tuân theo thuật toán tham lam.13

**Ví dụ kinh điển:**

* **Bài toán xếp lịch hoạt động (Activity Selection):** Cho một tập các hoạt động với thời gian bắt đầu và kết thúc. Chọn số lượng hoạt động tối đa có thể thực hiện mà không bị trùng lặp thời gian. Lựa chọn tham lam đúng là luôn chọn hoạt động kết thúc sớm nhất.13  
* **Bài toán đổi tiền:** Dùng ít tờ tiền nhất để tạo ra một số tiền cho trước, với các mệnh giá có sẵn. Nếu hệ thống tiền tệ là "chuẩn" (như hệ thống tiền tệ thông thường), lựa chọn tham lam là luôn lấy tờ tiền có mệnh giá lớn nhất có thể.

### **2.4. Chia để Trị (Divide and Conquer)**

**Bản chất:** Đây là một mô hình giải quyết vấn đề mạnh mẽ, bao gồm ba bước 6:

1. **Divide (Chia):** Chia bài toán lớn thành các bài toán con nhỏ hơn, độc lập với nhau.  
2. **Conquer (Trị):** Giải các bài toán con một cách đệ quy. Nếu bài toán con đủ nhỏ, giải trực tiếp.  
3. **Combine (Tổng hợp):** Kết hợp lời giải của các bài toán con để tạo thành lời giải cho bài toán ban đầu.

**Ví dụ kinh điển:**

* **Sắp xếp trộn (Merge Sort):** Chia mảng thành hai nửa, sắp xếp đệ quy hai nửa, sau đó trộn hai nửa đã sắp xếp lại với nhau.17  
* **Sắp xếp nhanh (Quick Sort):** Chọn một phần tử làm "chốt" (pivot), phân hoạch mảng thành hai phần (nhỏ hơn pivot và lớn hơn pivot), sau đó sắp xếp đệ quy hai phần đó.17

## **Phần III: Sắp Xếp và Tìm Kiếm – Nền Tảng Của Tối Ưu Hóa**

### **3.1. Các Thuật Toán Sắp Xếp**

Sắp xếp là một trong những thao tác cơ bản nhất và là tiền đề cho rất nhiều thuật toán hiệu quả khác.

* **Các thuật toán $O(N^2)$:** Bubble Sort, Insertion Sort, Selection Sort. Chúng đơn giản, dễ cài đặt nhưng chỉ phù hợp với dữ liệu nhỏ. Tuy nhiên, việc hiểu chúng giúp xây dựng nền tảng tư duy. Ví dụ, Insertion Sort lại rất hiệu quả đối với dữ liệu gần như đã được sắp xếp.17  
* **Các thuật toán $O(N \\log N)$:** Merge Sort, Quick Sort, Heap Sort. Đây là những thuật toán hiệu quả và được sử dụng rộng rãi.  
  * **Quick Sort** thường nhanh nhất trong thực tế ở trường hợp trung bình, nhưng có thể suy biến thành $O(N^2)$ nếu chọn pivot không tốt.17  
  * Trong C++, hàm std::sort là một công cụ cực kỳ mạnh mẽ. Nó thường được cài đặt bằng **Intro Sort**, một thuật toán lai kết hợp Quick Sort, Heap Sort (để tránh trường hợp xấu nhất của Quick Sort) và Insertion Sort (cho các mảng con nhỏ), đảm bảo độ phức tạp $O(N \\log N)$ trong mọi trường hợp.17 Do đó, trong các kỳ thi, việc sử dụng std::sort là lựa chọn ưu tiên hàng đầu.

### **3.2. Tìm Kiếm Nhị Phân (Binary Search)**

**Bản chất:** Tìm kiếm nhị phân là một kỹ thuật cực kỳ hiệu quả để tìm kiếm một giá trị hoặc một vị trí trong một không gian tìm kiếm đã được sắp xếp. Thay vì duyệt tuần tự, nó liên tục "chặt đôi" không gian tìm kiếm, loại bỏ một nửa không chứa kết quả ở mỗi bước.19

Tuy nhiên, bản chất sâu sắc hơn của tìm kiếm nhị phân không chỉ giới hạn ở việc tìm kiếm trên "mảng đã sắp xếp". Nó có thể áp dụng cho bất kỳ "hàm đơn điệu" (monotonic function) nào.19 Một hàm $f(x)$ được gọi là đơn điệu nếu nó luôn tăng hoặc luôn giảm. Ta có thể hình dung hàm kiểm tra (predicate) $P(x)$ trả về một dãy các giá trị false rồi đến một dãy các giá trị true (ví dụ: F, F, F, T, T, T). Bài toán tìm kiếm nhị phân trở thành việc tìm vị trí chuyển giao đầu tiên từ F sang T.

Cách tư duy này mở ra một lớp bài toán rất lớn gọi là **"Binary Search on the Answer"** (Chặt nhị phân kết quả). Đối với các bài toán tối ưu hóa có dạng "tìm giá trị nhỏ nhất/lớn nhất của X để thỏa mãn điều kiện P", ta có thể xây dựng một hàm check(X) để kiểm tra xem giá trị $X$ có thỏa mãn điều kiện P hay không. Nếu hàm check có tính đơn điệu (ví dụ, nếu $X$ thỏa mãn thì mọi $Y \> X$ cũng thỏa mãn), ta có thể tìm kiếm nhị phân trên không gian các giá trị của $X$ để tìm ra đáp án tối ưu.

**Hướng dẫn giải:**

* **Tìm kiếm trên mảng:** C++ STL cung cấp các hàm mạnh mẽ như lower\_bound (tìm phần tử đầu tiên $\\ge$ giá trị cho trước), upper\_bound (tìm phần tử đầu tiên $\>$ giá trị cho trước), và binary\_search (kiểm tra sự tồn tại).19  
* **Chặt nhị phân kết quả:**  
  1. Xác định không gian tìm kiếm cho kết quả (ví dụ, từ $1$ đến $10^9$).  
  2. Viết hàm check(mid) để kiểm tra xem giá trị mid có phải là một đáp án khả thi hay không.  
  3. Sử dụng vòng lặp while để thu hẹp không gian tìm kiếm cho đến khi tìm được kết quả tối ưu.

C++

// Mẫu code cho tìm kiếm nhị phân kết quả (tìm giá trị nhỏ nhất)  
long long l \= 0, r \= 1e9, ans \= \-1;  
while (l \<= r) {  
    long long mid \= l \+ (r \- l) / 2;  
    if (check(mid)) { // Nếu mid là một đáp án khả thi  
        ans \= mid;    // Lưu lại đáp án  
        r \= mid \- 1;  // Thử tìm đáp án nhỏ hơn  
    } else {  
        l \= mid \+ 1;  // mid quá nhỏ, cần tăng lên  
    }  
}  
cout \<\< ans;

## **Phần IV: Các Kỹ Thuật Xử Lý Mảng Hiệu Quả**

### **4.1. Mảng Cộng Dồn và Mảng Hiệu (Prefix Sums & Difference Array)**

**Bản chất:** Kỹ thuật mảng cộng dồn (Prefix Sums) là một phương pháp tiền xử lý mảng để có thể trả lời các truy vấn tổng trên một đoạn con trong thời gian hằng số $O(1)$.22 Mảng cộng dồn $P$ được xây dựng từ mảng $A$ theo công thức: $P\[i\] \= A \+ A \+ \\dots \+ A\[i\]$. Khi đó, tổng của đoạn $A$ được tính bằng $P \- P\[L-1\]$.23

**Hướng dẫn giải:**

* **Mảng 1D:** $P\[i\] \= P\[i-1\] \+ A\[i\]$.  
* Mảng 2D: Kỹ thuật này có thể mở rộng cho mảng 2 chiều để tính tổng của một hình chữ nhật con trong $O(1)$.  
  $P\[i\]\[j\] \= A\[i\]\[j\] \+ P\[i-1\]\[j\] \+ P\[i\]\[j-1\] \- P\[i-1\]\[j-1\]$.  
* **Mảng hiệu (Difference Array):** Là kỹ thuật ngược lại, cho phép cập nhật (cộng một giá trị) trên một đoạn của mảng trong $O(1)$, và sau đó có thể khôi phục lại mảng ban đầu bằng mảng cộng dồn trong $O(N)$.

### **4.2. Kỹ Thuật Hai Con Trỏ (Two Pointers)**

**Bản chất:** Đây là một kỹ thuật tối ưu hóa phổ biến, sử dụng hai chỉ số (con trỏ) di chuyển trên một hoặc hai mảng để tìm các cặp hoặc đoạn con thỏa mãn một điều kiện nào đó. Kỹ thuật này thường giúp giảm độ phức tạp từ $O(N^2)$ (duyệt tất cả các cặp/đoạn) xuống $O(N)$.25

Hướng dẫn giải:  
Có hai dạng chính:

1. **Hai con trỏ ngược chiều:** Một con trỏ bắt đầu từ đầu mảng, con trỏ kia từ cuối mảng và di chuyển vào trong.  
   * **Ví dụ:** Tìm một cặp số trong mảng đã sắp xếp có tổng bằng $X$. Ta đặt con trỏ left ở đầu, right ở cuối. Nếu tổng A\[left\] \+ A\[right\] \< X, ta tăng left. Nếu tổng $\> X$, ta giảm right. Nếu bằng $X$, ta đã tìm thấy.25  
2. **Hai con trỏ cùng chiều:** Cả hai con trỏ đều bắt đầu từ đầu mảng và di chuyển về phía cuối.  
   * **Ví dụ:** Tìm đoạn con liên tiếp ngắn nhất có tổng $\\ge S$. Ta dùng con trỏ right để mở rộng đoạn và con trỏ left để co lại đoạn khi tổng đã đủ lớn.25

### **4.3. Kỹ Thuật Cửa Sổ Trượt (Sliding Window)**

**Bản chất:** Cửa sổ trượt là một biến thể của kỹ thuật hai con trỏ cùng chiều, trong đó hai con trỏ left và right tạo thành một "cửa sổ" (đoạn con) trên mảng. Cửa sổ này "trượt" qua mảng từ trái sang phải.27 Mục đích chính là tối ưu hóa việc tính toán lặp lại. Thay vì tính toán lại từ đầu cho mỗi cửa sổ, ta chỉ cần cập nhật kết quả bằng cách thêm phần tử mới ở right và loại bỏ phần tử cũ ở left, giúp giảm độ phức tạp từ $O(N \\cdot K)$ xuống $O(N)$.28

**Các loại cửa sổ:**

* **Cửa sổ kích thước cố định:** Kích thước cửa sổ luôn bằng $K$. Khi con trỏ right di chuyển, left cũng di chuyển theo để duy trì kích thước.  
  * **Ví dụ:** Tìm tổng lớn nhất của các đoạn con có độ dài $K$.  
* **Cửa sổ kích thước thay đổi:** Kích thước cửa sổ có thể co giãn tùy theo điều kiện của bài toán.31

## **Phần V: Số Học và Tổ Hợp**

### **5.1. Các Khái Niệm Số Học Cơ Bản**

* **Ước chung lớn nhất (UCLN):** Thuật toán Euclid là phương pháp hiệu quả nhất để tìm UCLN của hai số nguyên $a$ và $b$. Bản chất của thuật toán dựa trên tính chất đệ quy: $UCLN(a, b) \= UCLN(b, a \\pmod b)$ với trường hợp cơ sở là $UCLN(a, 0\) \= a$.33  
* **Thuật toán Euclid mở rộng:** Dùng để tìm cặp số nguyên $(x, y)$ thỏa mãn phương trình Diophantine $ax \+ by \= UCLN(a, b)$. Ứng dụng quan trọng của nó là tìm nghịch đảo modulo.33  
* **Phép toán Modulo:** Các phép toán cộng, trừ, nhân, lũy thừa trong vành modulo là nền tảng cho rất nhiều bài toán số học.33

### **5.2. Số Nguyên Tố**

* **Kiểm tra số nguyên tố:** Phương pháp hiệu quả nhất cho một số $N$ đơn lẻ là duyệt các ước số từ $2$ đến $\\sqrt{N}$. Nếu $N$ không chia hết cho bất kỳ số nào trong khoảng này, nó là số nguyên tố (với điều kiện $N \\ge 2$).37  
* **Phân tích thừa số nguyên tố:** Mọi hợp số $N$ đều có thể được phân tích duy nhất thành tích của các số nguyên tố. Thuật toán đơn giản là chia $N$ lặp đi lặp lại cho các số từ $2$ đến $\\sqrt{N}$.40

### **5.3. Sàng Eratosthenes**

**Bản chất:** Đây là một thuật toán cực kỳ hiệu quả để tìm tất cả các số nguyên tố nhỏ hơn hoặc bằng một số nguyên $N$ cho trước, với độ phức tạp thời gian gần tuyến tính $O(N \\log \\log N)$.41

**Hướng dẫn giải:**

1. Tạo một mảng boolean isPrime từ $2$ đến $N$, ban đầu giả định tất cả đều là số nguyên tố (true).  
2. Bắt đầu từ $p \= 2$.  
3. Nếu $p$ là số nguyên tố (vẫn được đánh dấu true), hãy đánh dấu tất cả các bội của nó ($2p, 3p, 4p, \\dots$) là không phải số nguyên tố (false).  
4. Tìm số nguyên tố tiếp theo lớn hơn $p$ và lặp lại bước 3\.  
   Tối ưu hóa:  
* Vòng lặp ngoài chỉ cần chạy đến $\\sqrt{N}$.  
* Khi đánh dấu các bội của $p$, ta có thể bắt đầu từ $p^2$, vì các bội nhỏ hơn đã được đánh dấu bởi các số nguyên tố nhỏ hơn $p$.39

C++

void sieve(int n) {  
    vector\<bool\> is\_prime(n \+ 1, true);  
    is\_prime \= is\_prime \= false;  
    for (int p \= 2; p \* p \<= n; p++) {  
        if (is\_prime\[p\]) {  
            for (int i \= p \* p; i \<= n; i \+= p)  
                is\_prime\[i\] \= false;  
        }  
    }  
}

### **5.4. Giới thiệu về Tổ hợp**

Tổ hợp là ngành toán học nghiên cứu về việc đếm, sắp xếp và kết hợp các đối tượng. Trong lập trình thi đấu cấp THCS, các bài toán tổ hợp thường xoay quanh:

* **Quy tắc cộng và nhân:** Các nguyên tắc đếm cơ bản.  
* **Hoán vị:** Số cách sắp xếp $n$ phần tử khác nhau là $n\!$.  
* **Chỉnh hợp:** Số cách chọn $k$ phần tử từ $n$ phần tử và sắp xếp chúng theo thứ tự là $A\_n^k \= \\frac{n\!}{(n-k)\!}$.  
* **Tổ hợp:** Số cách chọn $k$ phần tử từ $n$ phần tử không tính thứ tự là $C\_n^k \= \\frac{n\!}{k\!(n-k)\!}$.

## **Phần VI: Quy Hoạch Động (Dynamic Programming \- DP)**

### **6.1. Giới thiệu Quy hoạch động**

Quy hoạch động là một trong những kỹ thuật mạnh mẽ và quan trọng nhất trong lập trình thi đấu.44 Nó được dùng để giải quyết các bài toán tối ưu bằng cách chia chúng thành các bài toán con nhỏ hơn, giải mỗi bài toán con chỉ một lần và lưu trữ kết quả để sử dụng lại.46

Một bài toán có thể giải được bằng quy hoạch động nếu nó thỏa mãn hai đặc tính cốt lõi:

1. **Cấu trúc con tối ưu (Optimal Substructure):** Lời giải tối ưu của bài toán lớn có thể được xây dựng từ lời giải tối ưu của các bài toán con của nó.9  
2. **Bài toán con gối nhau (Overlapping Subproblems):** Cùng một bài toán con được tính toán lặp đi lặp lại nhiều lần trong quá trình giải bài toán lớn bằng phương pháp đệ quy thông thường.46

Sự khác biệt chính giữa Chia để trị và DP nằm ở đặc tính thứ hai. Chia để trị giải quyết các bài toán con *độc lập*, trong khi DP hiệu quả khi các bài toán con *gối nhau*. Việc lưu trữ kết quả của các bài toán con (gọi là "memoization" hoặc "tabulation") chính là điểm mấu chốt của DP để tránh tính toán lại.

### **6.2. Các Bước Xây Dựng Lời Giải DP**

Để giải một bài toán bằng quy hoạch động, ta thường tuân theo các bước sau 44:

1. **Xác định trạng thái:** Định nghĩa bài toán con. Trạng thái thường được biểu diễn bằng các tham số, ví dụ dp\[i\] hoặc dp\[i\]\[j\], đại diện cho lời giải của một bài toán con cụ thể.  
2. **Tìm công thức truy hồi:** Xây dựng mối quan hệ giữa lời giải của một trạng thái và lời giải của các trạng thái nhỏ hơn.  
3. **Xác định thứ tự tính toán và các trường hợp cơ sở:** Các trạng thái cơ sở là những bài toán con nhỏ nhất có thể giải trực tiếp. Sau đó, tính toán các trạng thái lớn hơn dựa trên các trạng thái nhỏ hơn đã tính. Có hai cách tiếp cận chính:  
   * **Bottom-up (Tabulation):** Dùng vòng lặp để tính toán bảng DP từ các trạng thái cơ sở lên các trạng thái lớn hơn.  
   * **Top-down (Memoization):** Dùng đệ quy để giải bài toán lớn, nhưng lưu lại kết quả của các bài toán con đã giải để không phải tính lại.48

### **6.3. Các Bài Toán DP Kinh Điển**

* **Dãy con tăng dài nhất (Longest Increasing Subsequence \- LIS):**  
  * **Bài toán:** Cho một dãy số, tìm độ dài của dãy con tăng dài nhất.  
  * **Lời giải $O(N^2)$:** Gọi dp\[i\] là độ dài của dãy con tăng dài nhất kết thúc tại phần tử $A\[i\]$. Công thức truy hồi: $dp\[i\] \= 1 \+ \\max(\\{dp\[j\] \\mid 0 \\le j \< i, A\[j\] \< A\[i\]\\})$.50  
  * **Lời giải $O(N \\log N)$:** Có thể tối ưu bằng cách sử dụng tìm kiếm nhị phân để tìm giá trị dp\[j\] lớn nhất một cách hiệu quả.50  
* **Bài toán cái túi (Knapsack Problem):**  
  * **Bài toán (0/1 Knapsack):** Cho $N$ vật phẩm, mỗi vật có trọng lượng và giá trị riêng, và một cái túi có sức chứa tối đa. Chọn các vật phẩm để cho vào túi sao cho tổng giá trị là lớn nhất mà không vượt quá sức chứa.  
  * **Lời giải:** Gọi dp\[i\]\[w\] là giá trị lớn nhất có thể đạt được khi xét $i$ vật phẩm đầu tiên với giới hạn trọng lượng là $w$. Tại vật phẩm thứ $i$, ta có hai lựa chọn: không lấy nó, hoặc lấy nó (nếu đủ sức chứa).52  
* **Dãy con chung dài nhất (Longest Common Subsequence \- LCS):**  
  * **Bài toán:** Cho hai chuỗi $X$ và $Y$, tìm độ dài của dãy con chung dài nhất.  
  * **Lời giải:** Gọi dp\[i\]\[j\] là độ dài LCS của tiền tố $X\[1..i\]$ và $Y\[1..j\]$.54

### **6.4. Kỹ thuật Truy vết (Traceback)**

Sau khi tính toán xong bảng DP và có được giá trị tối ưu (ví dụ: độ dài lớn nhất, tổng giá trị lớn nhất), thường đề bài sẽ yêu cầu in ra chính lời giải đó (dãy con cụ thể, các vật phẩm được chọn). Kỹ thuật truy vết cho phép ta làm điều này bằng cách lưu lại "lựa chọn" đã dẫn đến kết quả tối ưu tại mỗi trạng thái, sau đó đi ngược lại từ trạng thái cuối cùng để xây dựng lại lời giải.

### **6.5. DP Nâng Cao (Giới thiệu)**

* **DP Bitmask:** Khi một trạng thái của bài toán phụ thuộc vào một tập hợp con của một tập hợp có kích thước nhỏ (thường $N \\le 22$), ta có thể sử dụng một số nguyên (bitmask) để biểu diễn tập hợp con đó. Mỗi bit của số nguyên tương ứng với một phần tử, bit bằng 1 nghĩa là phần tử đó có trong tập hợp con, và ngược lại.56

## **Phần VII: Lý Thuyết Đồ Thị**

### **7.1. Biểu Diễn Đồ Thị**

Trong lập trình thi đấu, có hai cách phổ biến để biểu diễn một đồ thị:

1. **Ma trận kề (Adjacency Matrix):** Một ma trận 2D adj\[V\]\[V\], trong đó adj\[u\]\[v\] \= 1 (hoặc trọng số) nếu có cạnh nối từ đỉnh $u$ đến đỉnh $v$.  
   * **Ưu điểm:** Kiểm tra sự tồn tại của cạnh $(u, v)$ trong $O(1)$.  
   * **Nhược điểm:** Tốn bộ nhớ $O(V^2)$, duyệt các đỉnh kề của một đỉnh mất $O(V)$. Chỉ phù hợp với đồ thị dày đặc (số cạnh $E$ xấp xỉ $V^2$).59  
2. **Danh sách kề (Adjacency List):** Một mảng các danh sách (hoặc vector trong C++), trong đó adj\[u\] chứa danh sách các đỉnh kề với $u$.  
   * **Ưu điểm:** Tiết kiệm bộ nhớ $O(V+E)$, duyệt các đỉnh kề của $u$ chỉ mất thời gian tỉ lệ với bậc của $u$.  
   * **Nhược điểm:** Kiểm tra sự tồn tại của cạnh $(u, v)$ mất thời gian tỉ lệ với bậc của $u$.  
   * **Khuyến nghị:** Trong lập trình thi đấu, đồ thị thường là đồ thị thưa ($E$ xấp xỉ $V$). Do đó, **danh sách kề (sử dụng vector\<vector\<int\>\>) gần như luôn là lựa chọn tốt hơn**.60

### **7.2. Các Thuật Toán Duyệt Đồ Thị**

* **BFS (Breadth-First Search \- Tìm kiếm theo chiều rộng):**  
  * **Bản chất:** Duyệt các đỉnh theo từng "lớp" khoảng cách từ đỉnh xuất phát, giống như một vết dầu loang. Thuật toán này sử dụng cấu trúc dữ liệu **hàng đợi (queue)**.62  
  * **Ứng dụng chính:** Tìm đường đi ngắn nhất (số cạnh ít nhất) trên đồ thị không có trọng số hoặc có trọng số bằng nhau.7  
* **DFS (Depth-First Search \- Tìm kiếm theo chiều sâu):**  
  * **Bản chất:** Đi sâu vào một nhánh cho đến khi không thể đi tiếp, sau đó quay lui để thử nhánh khác. Thuật toán này thường được cài đặt bằng đệ quy (sử dụng ngăn xếp ngầm của hệ thống).65  
  * **Ứng dụng chính:** Kiểm tra tính liên thông, tìm thành phần liên thông, phát hiện chu trình, sắp xếp topo, tìm khớp và cầu.65

### **7.3. Đường Đi Ngắn Nhất**

* **Thuật toán Dijkstra:**  
  * **Mục đích:** Tìm đường đi ngắn nhất từ một đỉnh nguồn đến tất cả các đỉnh khác trên đồ thị có **trọng số cạnh không âm**.  
  * **Cách hoạt động:** Là một thuật toán tham lam. Nó duy trì một tập các đỉnh đã có đường đi ngắn nhất cuối cùng. Ở mỗi bước, nó chọn đỉnh chưa được xử lý có khoảng cách tạm thời ngắn nhất và "kết nạp" vào tập.  
  * **Độ phức tạp:** $O(V^2)$ với cài đặt đơn giản. Tối ưu xuống $O(E \\log V)$ bằng cách sử dụng hàng đợi ưu tiên (priority\_queue trong C++).8  
* **Thuật toán Bellman-Ford:**  
  * **Mục đích:** Tương tự Dijkstra nhưng có thể xử lý được cả **trọng số âm**.  
  * **Ứng dụng:** Phát hiện sự tồn tại của chu trình âm (một chu trình có tổng trọng số các cạnh là âm).69  
* **Thuật toán Floyd-Warshall:**  
  * **Mục đích:** Tìm đường đi ngắn nhất giữa **tất cả các cặp đỉnh** trong đồ thị.  
  * **Cách hoạt động:** Là một thuật toán quy hoạch động với độ phức tạp $O(V^3)$.69

### **7.4. Cây Khung Nhỏ Nhất (Minimum Spanning Tree \- MST)**

**Bài toán:** Cho một đồ thị vô hướng, có trọng số và liên thông, tìm một cây con chứa tất cả các đỉnh của đồ thị sao cho tổng trọng số các cạnh của cây là nhỏ nhất.

* **Thuật toán Kruskal:** Một thuật toán tham lam. Sắp xếp tất cả các cạnh theo trọng số tăng dần. Duyệt qua các cạnh, thêm một cạnh vào cây khung nếu nó không tạo ra chu trình. Việc kiểm tra chu trình được thực hiện hiệu quả bằng cấu trúc dữ liệu DSU.8  
* **Thuật toán Prim:** Cũng là một thuật toán tham lam. Bắt đầu từ một đỉnh bất kỳ, dần dần mở rộng cây bằng cách luôn chọn cạnh có trọng số nhỏ nhất nối một đỉnh trong cây với một đỉnh ngoài cây.8

### **7.5. Sắp Xếp Topo (Topological Sort)**

**Bản chất:** Là một cách sắp xếp tuyến tính các đỉnh của một **đồ thị có hướng không chu trình (DAG)** sao cho với mọi cạnh có hướng từ $u$ đến $v$, đỉnh $u$ luôn đứng trước đỉnh $v$ trong thứ tự sắp xếp.16

**Hướng dẫn giải:**

* **Sử dụng BFS (Thuật toán Kahn):** Bắt đầu với các đỉnh có bán bậc vào bằng 0\. Lần lượt lấy các đỉnh này ra, thêm vào danh sách topo, và giảm bán bậc vào của các đỉnh kề với nó. Nếu một đỉnh kề có bán bậc vào mới bằng 0, thêm nó vào hàng đợi.  
* **Sử dụng DFS:** Thực hiện DFS trên đồ thị. Thứ tự topo là thứ tự ngược lại của thời gian kết thúc duyệt các đỉnh.67

## **Phần VIII: Cấu Trúc Dữ Liệu Nâng Cao**

### **8.1. Disjoint Set Union (DSU)**

**Bản chất:** DSU, hay Union-Find, là một cấu trúc dữ liệu để quản lý các tập hợp không giao nhau. Nó hỗ trợ hiệu quả hai thao tác chính 70:

* union(u, v): Gộp hai tập hợp chứa $u$ và $v$.  
* find(u): Tìm phần tử đại diện (gốc) của tập hợp chứa $u$. Hai phần tử $u$ và $v$ cùng tập hợp nếu find(u) \== find(v).

**Hướng dẫn giải:** Để đạt được độ phức tạp gần như hằng số $O(\\alpha(N))$ cho mỗi thao tác, cần áp dụng đồng thời hai kỹ thuật tối ưu:

1. **Nén đường đi (Path Compression):** Trong quá trình find(u), sau khi tìm được gốc, ta nối trực tiếp $u$ và các đỉnh trên đường đi từ $u$ lên gốc.  
2. **Gộp theo kích thước/hạng (Union by Size/Rank):** Khi gộp hai tập hợp, luôn nối cây nhỏ hơn vào gốc của cây lớn hơn (dựa trên số lượng phần tử hoặc chiều cao của cây).70

### **8.2. Cây Fenwick (Binary Indexed Tree \- BIT)**

**Bản chất:** BIT là một cấu trúc dữ liệu hiệu quả, cho phép thực hiện hai loại thao tác trong thời gian $O(\\log N)$ 74:

1. Cập nhật giá trị tại một điểm (point update).  
2. Truy vấn tổng của một đoạn tiền tố (prefix sum query).

**Hướng dẫn giải:** Ý tưởng của BIT dựa trên biểu diễn nhị phân của chỉ số. Mỗi nút trong cây BIT chịu trách nhiệm cho một khoảng có độ dài là một lũy thừa của 2\. Việc di chuyển lên và xuống cây được thực hiện bằng các phép toán bit, cụ thể là hàm lowbit(x) (thường được cài đặt là x & \-x).77

### **8.3. Cây Phân Đoạn (Segment Tree)**

**Bản chất:** Segment Tree là một cấu trúc dữ liệu dạng cây nhị phân rất linh hoạt, cho phép thực hiện các truy vấn trên một đoạn bất kỳ (ví dụ: tổng, min, max, UCLN...) và cập nhật phần tử, tất cả đều trong thời gian $O(\\log N)$.79

**Hướng dẫn giải:**

* Mỗi nút trên cây biểu diễn một đoạn của mảng ban đầu. Nút gốc biểu diễn cả mảng. Mỗi nút cha có hai con, mỗi con biểu diễn một nửa đoạn của cha.  
* **Kỹ thuật cập nhật lười (Lazy Propagation):** Đây là một tối ưu hóa quan trọng cho phép cập nhật trên cả một đoạn (ví dụ: cộng một giá trị $v$ cho tất cả các phần tử từ $L$ đến $R$) trong thời gian $O(\\log N)$. Ý tưởng là thay vì cập nhật tất cả các phần tử lá, ta chỉ cập nhật các nút lớn nhất nằm hoàn toàn trong đoạn truy vấn và đánh dấu một giá trị "lười" (lazy) tại các nút đó. Giá trị lazy này sẽ được "đẩy" xuống các nút con khi cần thiết.82

## **Phần IX: Xử Lý Chuỗi Ký Tự Nâng Cao**

### **9.1. Băm Chuỗi (String Hashing)**

**Bản chất:** Kỹ thuật này chuyển đổi một chuỗi (hoặc chuỗi con) thành một số nguyên duy nhất (gọi là giá trị băm \- hash value) bằng cách sử dụng công thức băm đa thức (polynomial rolling hash). Điều này cho phép so sánh hai chuỗi con có bằng nhau hay không trong thời gian $O(1)$ sau một bước tiền xử lý $O(N)$.84

**Hướng dẫn giải:**

* **Công thức:** Hash của chuỗi $S \= s\_1s\_2...s\_n$ được tính là $(s\_1 \\cdot p^0 \+ s\_2 \\cdot p^1 \+ \\dots \+ s\_n \\cdot p^{n-1}) \\pmod M$.  
* **Xử lý va chạm (Collision):** Việc hai chuỗi khác nhau có cùng giá trị băm là có thể xảy ra. Để giảm thiểu xác suất này, ta chọn $p$ là một số nguyên tố và $M$ là một số nguyên tố rất lớn. Có thể sử dụng hai cặp $(p, M)$ khác nhau để tăng độ tin cậy.  
* **Tính hash chuỗi con:** Bằng cách sử dụng mảng cộng dồn cho các giá trị hash, ta có thể tính hash của chuỗi con bất kỳ trong $O(1)$.

### **9.2. Thuật toán KMP và Z-function**

* **KMP (Knuth-Morris-Pratt):** Là một thuật toán so khớp chuỗi kinh điển, cho phép tìm tất cả các lần xuất hiện của một xâu mẫu $P$ (độ dài $M$) trong một xâu văn bản $T$ (độ dài $N$) với độ phức tạp thời gian tuyến tính $O(N+M)$. Ý tưởng cốt lõi là sử dụng một mảng tiền xử lý (mảng LPS \- Longest Proper Prefix which is also Suffix) để biết cần "trượt" xâu mẫu đi bao xa khi có một ký tự không khớp, tránh việc so sánh lại các ký tự đã khớp.87  
* **Z-function:** Là một thuật toán tạo ra một mảng $Z$, trong đó $Z\[i\]$ là độ dài của xâu con dài nhất bắt đầu từ vị trí $i$ mà cũng là một tiền tố của xâu ban đầu. Mảng $Z$ có thể được xây dựng trong thời gian tuyến tính và được ứng dụng để giải quyết bài toán so khớp chuỗi một cách hiệu quả.90

## **Phần X: Chiến Lược Thi Đấu và Kỹ Năng Thực Hành**

Kiến thức thuật toán là cần thiết, nhưng để chuyển hóa nó thành điểm số trong phòng thi lại đòi hỏi các kỹ năng và chiến lược riêng.

### **10.1. Chiến Thuật Trong Phòng Thi**

1. **Đọc và Phân loại đề:** Dành 5-10 phút đầu tiên để đọc lướt qua tất cả các bài. Phân loại chúng theo độ khó chủ quan (dễ, trung bình, khó) và xác định bài "cho điểm" (thường là bài 1\) để làm trước.10  
2. **Bắt đầu với lời giải "Trâu":** Đối với các bài toán khó, đừng cố gắng tìm ra lời giải tối ưu ngay lập tức. Hãy ưu tiên cài đặt một lời giải duyệt toàn bộ (brute-force) để đảm bảo có điểm cho các subtask có giới hạn nhỏ. Lời giải này cũng có thể dùng để sinh ra kết quả đúng cho các test case nhỏ, giúp bạn kiểm tra tính đúng đắn của thuật toán tối ưu sau này.10  
3. **Làm theo Subtask:** Các bài thi thường được chia thành các bài toán con (subtask) với các giới hạn khác nhau. Hãy tiếp cận bài toán bằng cách giải quyết từng subtask một. Việc này không chỉ giúp bạn tích lũy điểm mà còn có thể gợi ý hướng đi cho các subtask khó hơn.10

### **10.2. Kỹ Năng Gỡ Lỗi (Debugging)**

Gỡ lỗi là một kỹ năng quan trọng. Thay vì sửa code một cách ngẫu nhiên, hãy tiếp cận một cách có hệ thống:

* **In giá trị biến:** Sử dụng printf hoặc cout để in ra giá trị của các biến tại các điểm quan trọng trong chương trình để theo dõi luồng thực thi.5  
* **Tự sinh test case:** Tạo các test case nhỏ, đặc biệt là các trường hợp biên (ví dụ: mảng rỗng, mảng có một phần tử, tất cả các phần tử bằng nhau, giá trị lớn nhất/nhỏ nhất) để kiểm tra logic của bạn.5  
* **Cô lập vấn đề:** Cố gắng tạo ra một trường hợp đầu vào nhỏ nhất mà chương trình của bạn chạy sai. Điều này giúp thu hẹp phạm vi tìm kiếm lỗi.95  
* **Sử dụng Compiler Flags:** Khi biên dịch, hãy sử dụng các cờ gỡ lỗi như \-fsanitize=address,undefined (với GCC/Clang). Chúng sẽ giúp phát hiện các lỗi phổ biến như truy cập ngoài mảng, tràn số nguyên, v.v., và báo chính xác vị trí lỗi.96

### **10.3. Các Lỗi Thường Gặp trong C++ và Cách Tránh**

* **Lỗi logic:**  
  * **Tràn số nguyên (Integer Overflow):** Cẩn thận khi nhân hai số int, kết quả có thể vượt quá giới hạn của int trước khi được gán cho một biến long long. Hãy ép kiểu một trong hai toán hạng sang long long trước khi nhân: long long result \= 1LL \* a \* b;.97  
  * **Sai số với số thực:** Hạn chế sử dụng hàm pow cho số nguyên, nó có thể gây sai số. Sử dụng vòng lặp hoặc lũy thừa nhị phân. Hàm sqrt cũng có thể gây sai số, nên so sánh x\*x \<= N thay vì x \<= sqrt(N).98  
* **Lỗi hiệu năng:**  
  * **Sử dụng endl:** endl không chỉ xuống dòng (\\n) mà còn thực hiện flush bộ đệm, làm chương trình chậm đi đáng kể khi phải in ra nhiều dòng. Hãy luôn sử dụng '\\n'.97  
  * **Truyền tham trị:** Khi truyền các cấu trúc dữ liệu lớn (vector, string) vào hàm, hãy truyền bằng tham chiếu (&) hoặc tham chiếu hằng (const &) để tránh việc sao chép tốn kém.99  
* **Lỗi khi thi:**  
  * **Quên hoặc sai tên file I/O:** Một lỗi ngớ ngẩn nhưng có thể khiến bạn mất toàn bộ điểm của một bài.99 Hãy kiểm tra kỹ tên file \*.INP và \*.OUT.

### **10.4. Tầm Quan Trọng của Luyện Tập và "Upsolving"**

Không có con đường tắt nào để trở nên giỏi hơn ngoài việc luyện tập chăm chỉ.100

* **Luyện tập theo chủ đề:** Khi học một thuật toán mới, hãy tìm các bài tập có gắn thẻ (tag) tương ứng trên các trang như Codeforces, VNOJ để luyện tập cho đến khi thành thạo.102  
* **Tham gia các kỳ thi:** Tham gia các kỳ thi trực tuyến thường xuyên trên Codeforces, AtCoder,... giúp rèn luyện tốc độ, tâm lý và khả năng giải quyết vấn đề dưới áp lực thời gian.  
* **Upsolving:** Đây là một trong những phương pháp hiệu quả nhất. Sau mỗi kỳ thi (thật hoặc ảo), hãy dành thời gian để giải lại những bài bạn đã không làm được. Đọc lời giải (editorial) của người khác, hiểu ý tưởng và tự mình cài đặt lại. Đây là cách tốt nhất để học hỏi các kỹ thuật mới và lấp đầy lỗ hổng kiến thức.104
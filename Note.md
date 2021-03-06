# 0005 Longest Palindromic Substring

### 中心拓展算法

状态转移方程：
$$
\left\{
    \begin{align}
    &P(i,i) &=& \quad true\\
    &P(i,i+1) &=& \quad (S_i==S_{i+1}) \\
    &P(i,j) &=& \quad P(i+1,j-1) \ \&\&\  (S_i==S_j)
    \end{align}
\right.
$$
状态转移链：
$$
P(i,j) \to P(i+1,j-1) \to P(i+2,j-2) \to \cdots \to 边界情况
$$
其中，$边界情况$ 即字串长度为 $1$ 或 $2$ 的情况。枚举每一种 $边界情况$，并不断向外拓展，即可求出最大值。

时间复杂度 $O(n^2)$，空间复杂度 $O(1)$。

### Manacher算法

臂长 $length$ 表示中心拓展算法向外拓展的长度，对长度为奇数的最大回文字符串，其长度为 $2*length+1$。

若位置 $j$ 的臂长为 $length$，并且有 $j+length>i$，当在位置 $i$ 开始中心拓展时，可以先找到 $i$ 关于 $j$ 的对称点 $2*j-i$。

如果点 $2*j-i$ 的臂长为 $n$，那么点 $i$ 的臂长至少为 $\min(j+length-i,n)$。

<img src="https://neatlii-markdown.oss-cn-shanghai.aliyuncs.com/MarkdownImage/image-20220311170114301.png" alt="image-20220311170114301" style="zoom: 50%;" />

只需要在中心拓展算法过程中记录右臂在最右边的回文字符串，将其中心作为 $j$，就能最大限度地避免重复计算。

最后，可通过向字符串的头尾和每两个字符中间添加特殊字符，将所有奇偶数的的情况统一起来，例如 `#a#b#a#`。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。



# 0011 Container With Most Water

### 双指针

假设左指针和右指针指向的数分别为 $x$ 和 $y$，假设 $x\le y$，两个指针之间的距离为 $t$，那么当前容器的容量为：
$$
\min(x,y)*t=x*t
$$
若保持左指针不变，向左移动右指针，指向的数为 $y_1$，两个指针之间的距离变为 $t_1$，那么显然有 $t_1<t$，并且 $\min(x,y_1)<\min(x,y)$：

- 如果 $y_1\le y$，那么 $\min(x,y_1)\le\min(x,y)$；
- 如果 $y_1>y$，那么 $\min(x,y_1)=\min(x,y)$。

因此有：
$$
\min(x,y_1)*t_1<\min(x,y)*t
$$
因此只能向右移动左指针，直到指向的数 $x_1>x$为止，才有可能得到更大的容器容量。当 $x>y$ 时同理。

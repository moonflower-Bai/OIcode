#include <Eigen/Eigen>
#include <bits/stdc++.h>
#include <format>

std::string code = "LMQETXYEAGTXCTUIEWNCTXLZEWUAISPZYVAPEWLMGQWYAXFTCJMSQCADAGT"
                   "XLMDXNXSNPJQSYVAPRIQSMHNOCVAXFV";

std::vector<std::string> ref = {"TH", "HE", "IN", "ER", "AN", "RE", "ED", "ON",
                                "ES", "ST", "EN", "AT", "TO", "NT", "HA", "ND",
                                "OU", "EA", "NG", "AS", "OR", "TI", "IS", "ET",
                                "IT", "AR", "TE", "SE", "HI", "OF"};

std::map<std::string, int> cnt;
std::vector<std::pair<std::string, int>> candidates;

// ============ 辅助函数：手动取模 ============
inline int mod26(int x) {
    x %= 26;
    if (x < 0) x += 26;
    return x;
}

// ============ 扩展欧几里得 ============
int exgcd(int a, int b, int &x, int &y)
{
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int gcd = exgcd(b, a % b, x, y);
    int temp = x;
    x = y;
    y = temp - (a / b) * y;
    return gcd;
}

// ============ 模26逆矩阵 ============
void calcInverse(int a00, int a01, int a10, int a11, 
                 int &inv00, int &inv01, int &inv10, int &inv11)
{
    int det = a00 * a11 - a01 * a10;
    det = mod26(det);
    
    int x, y;
    int gcd = exgcd(det, 26, x, y);
    if (gcd != 1) {
        inv00 = inv01 = inv10 = inv11 = -1;  // 表示不可逆
        return;
    }
    
    int det_inv = mod26(x);
    
    // 伴随矩阵 * det_inv mod 26
    inv00 = mod26(det_inv * a11);
    inv01 = mod26(det_inv * (-a01));
    inv10 = mod26(det_inv * (-a10));
    inv11 = mod26(det_inv * a00);
}

// ============ 矩阵乘法取模 ============
void mulMatrix(int a00, int a01, int a10, int a11,
               int b00, int b01, int b10, int b11,
               int &c00, int &c01, int &c10, int &c11)
{
    c00 = mod26(a00 * b00 + a01 * b10);
    c01 = mod26(a00 * b01 + a01 * b11);
    c10 = mod26(a10 * b00 + a11 * b10);
    c11 = mod26(a10 * b01 + a11 * b11);
}

// ============ 矩阵向量乘法取模 ============
void mulVector(int m00, int m01, int m10, int m11, int v0, int v1,
               int &r0, int &r1)
{
    r0 = mod26(m00 * v0 + m01 * v1);
    r1 = mod26(m10 * v0 + m11 * v1);
}

// ============ 评分函数 ============
int getScore(const std::string &text)
{
    int score = 0;
    
    // 检查常见单词
    std::string words[] = {"THE", "AND", "FOR", "ARE", "BUT", "NOT", "YOU", 
                          "ALL", "CAN", "HER", "WAS", "ONE", "OUR", "OUT",
                          "THIS", "THAT", "WITH", "HAVE", "FROM", "THEY",
                          "HILL", "CIPHER", "CRYPTO"};
    for (const auto &word : words) {
        if (text.find(word) != std::string::npos) {
            score += 5;
        }
    }
    
    // 检查常见2-gram
    std::string bigrams[] = {"TH", "HE", "IN", "ER", "AN", "RE", "ED", "ON"};
    for (size_t i = 0; i + 1 < text.length(); i++) {
        std::string bg = text.substr(i, 2);
        for (const auto &ref_bg : bigrams) {
            if (bg == ref_bg) {
                score += 1;
                break;
            }
        }
    }
    
    return score;
}

int main()
{
    int n = code.length();
    std::cout << "[INFO] Length = " << n << std::endl;
    
    // 1. 统计密文bigram频率
    for (int i = 0; i + 1 < n; i += 2) {
        cnt[code.substr(i, 2)]++;
    }
    
    std::vector<std::pair<std::string, int>> vec2(cnt.begin(), cnt.end());
    sort(vec2.begin(), vec2.end(),
         [](const auto &a, const auto &b) { return a.second > b.second; });
    
    std::cout << "=== Bigram 频率 ===" << std::endl;
    for (int i = 0; i < std::min(10, (int)vec2.size()); i++) {
        std::cout << vec2[i].first << ": " << vec2[i].second << std::endl;
    }
    std::cout << std::endl;
    
    // 2. 唯密文攻击（用最笨但最可靠的方式）
    std::cout << "=== 开始破解 ===" << std::endl;
    
    int matchCount = 0;
    
    for (int ii = 0; ii < std::min(5, (int)vec2.size()); ii++) {
        for (int jj = ii + 1; jj < std::min(5, (int)vec2.size()); jj++) {
            
            // 密文矩阵 C
            int c00 = vec2[ii].first[0] - 'A';
            int c01 = vec2[ii].first[1] - 'A';
            int c10 = vec2[jj].first[0] - 'A';
            int c11 = vec2[jj].first[1] - 'A';
            
            for (int i = 0; i < 30; i++) {
                for (int j = i + 1; j < 30; j++) {
                    
                    // 明文矩阵 P
                    int p00 = ref[i][0] - 'A';
                    int p01 = ref[i][1] - 'A';
                    int p10 = ref[j][0] - 'A';
                    int p11 = ref[j][1] - 'A';
                    
                    // 求 P 的逆矩阵
                    int inv00, inv01, inv10, inv11;
                    calcInverse(p00, p01, p10, p11, inv00, inv01, inv10, inv11);
                    
                    if (inv00 == -1) continue;  // 不可逆
                    
                    // 密钥 K = C * P^(-1) mod 26
                    int k00, k01, k10, k11;
                    mulMatrix(c00, c01, c10, c11, inv00, inv01, inv10, inv11,
                              k00, k01, k10, k11);
                    
                    // 解密整个密文
                    std::string result;
                    for (int pos = 0; pos + 1 < n; pos += 2) {
                        int v0 = code[pos] - 'A';
                        int v1 = code[pos + 1] - 'A';
                        int r0, r1;
                        mulVector(k00, k01, k10, k11, v0, v1, r0, r1);
                        result += char(r0 + 'A');
                        result += char(r1 + 'A');
                    }
                    
                    int score = getScore(result);
                    if (score > 0) {
                        candidates.push_back({result, score});
                        matchCount++;
                    }
                }
            }
        }
    }
    
    std::cout << "[INFO] 共 " << matchCount << " 个候选" << std::endl;
    
    // 3. 排序输出
    sort(candidates.begin(), candidates.end(),
         [](const auto &a, const auto &b) { return a.second > b.second; });
    
    candidates.erase(std::unique(candidates.begin(), candidates.end(),
        [](const auto &a, const auto &b) { return a.first == b.first; }), candidates.end());
    
    std::cout << "\n=== 结果 ===" << std::endl;
    for (int i = 0; i < std::min(100, (int)candidates.size()); i++) {
        std::cout << "[" << candidates[i].second << "分] " 
                  << candidates[i].first << std::endl;
    }
    
    return 0;
}
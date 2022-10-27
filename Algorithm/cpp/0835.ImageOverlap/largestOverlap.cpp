class Solution {
public:
    using Mat = vector<vector<int>>;
    using BitSet = bitset<32>;
    using BitMat = vector<BitSet>;
    int sz = 0;
    
    int maxOverlap(const BitMat& m1, const BitMat& m2, int rowOffset, int colOffset) {
      int overlap1 = 0;  // phase 1 offset (+row, +col)
      int overlap2 = 0;  // phase 2 offset (-row, +col)
      int overlap3 = 0;  // phase 3 offset (-row, -col)
      int overlap4 = 0;  // phase 4 offset (+row, -col)
      for (int i = 0; i < sz; ++i) {
        if (i + rowOffset < sz) {
          overlap1 += ((m1[i + rowOffset] >> colOffset) & m2[i]).count();
          overlap4 += ((m1[i + rowOffset] << colOffset) & m2[i]).count();
        }
        if (i - rowOffset >= 0) {
          overlap2 += ((m1[i - rowOffset] >> colOffset) & m2[i]).count();
          overlap3 += ((m1[i - rowOffset] << colOffset) & m2[i]).count();
        }        
      }
      return std::max(overlap1, std::max(overlap2, std::max(overlap3, overlap4)));
    }

    int largestOverlap(Mat& img1, Mat& img2) {
      sz = img1.size();
      
      BitMat m1 = std::vector<BitSet>(sz, BitSet{});
      BitMat m2 = std::vector<BitSet>(sz, BitSet{});;
      
      for (int i = 0; i < sz; ++i) {
        for (int j = 0; j < sz; ++j) {
          if (img1[i][j]) m1[i].set(j);
          if (img2[i][j]) m2[i].set(j);
        }
      }

      int res = 0;
      for (int i = 0; i < sz; ++i) {
        for (int j = 0; j < sz; ++j) {
          res = std::max(res, maxOverlap(m1, m2, i, j));          
        }
      }      
      return res;
        
    }
};


// traverse distance
class Solution {
public:
    int largestOverlap(const vector<vector<int>>& A, const vector<vector<int>>& B) {
        int ans = 0;
        vector<int> flat_a, flat_b;
        unordered_map<int, int> distance_count;
        for (int r = 0; r < A.size(); ++r) {
            for (int c = 0; c < B.size(); ++c) {
                if (A[r][c]) flat_a.push_back(flat(r, c));
                if (B[r][c]) flat_b.push_back(flat(r, c));
            }
        }
        for (const auto& a : flat_a) {
            for (const auto& b : flat_b) {
                ++distance_count[a - b];
            }
        }
        for (const auto& c : distance_count)
            ans = max(ans, c.second);
        return ans;
    }
private:
    static inline int flat(const int r, const int c) { return (r<<6) + c; }
};

// 作者：hareyukai
// 链接：https://leetcode.cn/problems/image-overlap/solution/-dui-ahe-bju-you-1de-wei-zhi-ju-chi-ji-shu-by-hare/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
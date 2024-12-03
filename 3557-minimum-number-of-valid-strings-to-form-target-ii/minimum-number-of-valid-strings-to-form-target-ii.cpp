struct rolling_hash {
  static constexpr unsigned long long M = (1ULL << 61) - 1, P = 257;
  inline static vector<unsigned long long> p = vector<unsigned long long>{1};
  vector<unsigned long long> h;
  rolling_hash(const string &s) {
    int n = s.size();
    h.resize(n + 1);
    for (unsigned long long i = p.size(), pp = p.back(); i <= n; i++)
      p.push_back(pp = __uint128_t(pp) * P % M);
    for (int i = n - 1; i >= 0; i--)
      h[i] = (s[i] + __uint128_t(h[i + 1]) * P % M) % M;
  }
  unsigned long long hash(int l, int r) {
    return (h[l] - __uint128_t(h[r + 1]) * p[r - l + 1] % M + M) % M;
  }
};

template <typename T, typename A, typename C, typename C2 = C, typename F = identity>
struct segment_tree {
  vector<T> tree;
  A apply;
  C combine;
  C2 query_combine;
  F query_fn;
  segment_tree(int n, T v, A apply, C combine, C2 query_combine = {}, F query_fn = {}) : tree(2 * n, v), apply(apply), combine(combine), query_combine(query_combine), query_fn(query_fn) {
    for (int i = n - 1; i > 0; --i)
      tree[i] = combine(tree[i << 1], tree[i << 1 | 1]);
  }
  template <typename... Args>
  void update(int i, Args &&...args) {
    int n = tree.size() >> 1;
    for (apply(tree[i += n], std::forward<Args>(args)...); i >>= 1;)
      tree[i] = combine(tree[i << 1], tree[i << 1 | 1]);
  }
  template <typename R = T, typename... Args>
  R query(int l, int r, R ans = {}, Args &&...args) { // [l, r)
    int n = tree.size() >> 1;
    auto ansl = ans, ansr = ans;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l & 1)
        ansl = query_combine(ansl, query_fn(tree[l++], std::forward<Args>(args)...));
      if (r & 1)
        ansr = query_combine(query_fn(tree[--r], std::forward<Args>(args)...), ansr);
    }
    return query_combine(ansl, ansr);
  }
};

class Solution {
public:
  int minValidStrings(vector<string> &w, string t) {
    int n = w.size(), m = t.size();
    rolling_hash rh_t(t);
    vector<rolling_hash> rh_w;
    for (int i = 0; i < n; i++) {
      rh_w.emplace_back(w[i]);
    }
    auto apply = [](int &x, int y) {
      x = min(x, y);
    };
    auto comb = [](int x, int y) {
      return min(x, y);
    };
    segment_tree dp(m + 1, (int)1e9, apply, comb);
    dp.update(m, 0);
    for (int i = m - 1; i >= 0; i--) {
      int r = 0;
      for (int j = 0; j < n; j++) {
        int lb = 0, rb = min((int)w[j].size(), m - i) + 1;
        while (rb - lb > 1) {
          int mb = (lb + rb) / 2;
          if (rh_w[j].hash(0, mb - 1) == rh_t.hash(i, i + mb - 1)) {
            r = max(r, mb);
            lb = mb;
          } else {
            rb = mb;
          }
        }
      }
      dp.update(i, dp.query(i, i + r + 1, (int)1e9) + 1);
    }
    int x = dp.query(0, 1, (int)1e9);
    return x == 1e9 ? -1 : x;
  }
};
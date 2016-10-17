class NumMatrix {
public:
  NumMatrix(vector<vector<int>> &matrix) {
    mat = matrix;
    for (int i = 0; i < mat.size(); ++i)
      for (int j = 1; j < mat[0].size(); ++j)
        mat[i][j] += mat[i][j - 1];
    for (int i = 1; i < mat.size(); ++i)
      for (int j = 0; j < mat[0].size(); ++j)
        mat[i][j] += mat[i - 1][j];
  }
  int access(int x, int y) {
    if (x < 0 || y < 0) {
      return 0;
    }
    return mat[x][y];
  }
  int sumRegion(int row1, int col1, int row2, int col2) {
    return access(row2, col2) + access(row1 - 1, col1 - 1) -
           access(row2, col1 - 1) - access(row1 - 1, col2);
  }

private:
  vector<vector<int>> mat;
};

// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.sumRegion(1, 2, 3, 4);

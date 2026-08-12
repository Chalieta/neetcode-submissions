class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        for (int i = 0; i < matrix.size(); ++i) {
            vector<int> row;
            int sum = 0;
            for (int j = 0; j < matrix[0].size(); ++j) {
                sum += matrix[i][j];
                row.push_back(sum);
            }
            prefix.push_back(row);
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;
        for (int i = row1; i < row2 + 1; ++i) {
            int preR = prefix[i][col2];
            int preL = col1 ? prefix[i][col1 - 1] : 0;
            sum += preR - preL;
        }
        return sum;
    }

private:
    vector<vector<int>> prefix;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */